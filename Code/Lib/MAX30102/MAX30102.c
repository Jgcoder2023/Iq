#include "MAX30102.h"
#include "app.h"

void MAX30102_GPIO(void) {
    // RCC_APB2PeriphClockCmd(MAX30102_INTPin_CLK,ENABLE);
    // GPIO_InitTypeDef GPIO_InitStruct;
    // GPIO_InitStruct.GPIO_Mode		=	GPIO_Mode_IN_FLOATING;
    // GPIO_InitStruct.GPIO_Pin		=	MAX30102_INTPin_Pin;
    // GPIO_Init(MAX30102_INTPin_PORT,&GPIO_InitStruct);
    // HAL已经初始化了
}

uint8_t Max30102_reset(void) {
    IIC_Write_Byte(MAX30102_Device_address, REG_MODE_CONFIG, 0x40);
    return 1;
}

void MAX30102_Config(void) {
    IIC_Write_Byte(MAX30102_Device_address, REG_INTR_ENABLE_1, 0xc0); //// INTR setting
    IIC_Write_Byte(MAX30102_Device_address, REG_INTR_ENABLE_2, 0x00); //
    IIC_Write_Byte(MAX30102_Device_address, REG_FIFO_WR_PTR, 0x00); // FIFO_WR_PTR[4:0]
    IIC_Write_Byte(MAX30102_Device_address, REG_OVF_COUNTER,0x00); // OVF_COUNTER[4:0]
    IIC_Write_Byte(MAX30102_Device_address, REG_FIFO_RD_PTR, 0x00); // FIFO_RD_PTR[4:0]

    IIC_Write_Byte(MAX30102_Device_address, REG_FIFO_CONFIG,0x0f); // sample avg = 1, fifo rollover=false, fifo almost full = 17
    IIC_Write_Byte(MAX30102_Device_address, REG_MODE_CONFIG,0x03); // 0x02 for Red only, 0x03 for SpO2 mode 0x07 multimode LED
    IIC_Write_Byte(MAX30102_Device_address, REG_SPO2_CONFIG,0x27); // SPO2_ADC range = 4096nA, SPO2 sample rate (50 Hz), LED pulseWidth (400uS)
    IIC_Write_Byte(MAX30102_Device_address, REG_LED1_PA, 0x32); // Choose value for ~ 10mA for LED1
    IIC_Write_Byte(MAX30102_Device_address, REG_LED2_PA,0x32); // Choose value for ~ 10mA for LED2
    IIC_Write_Byte(MAX30102_Device_address, REG_PILOT_PA,0x7f); // Choose value for ~ 25mA for Pilot LED
}


uint16_t fifo_red;
uint16_t fifo_ir;
//   https://blog.csdn.net/u012183892/article/details/109545972
void max30102_read_fifo(void) {
    uint16_t un_temp;
    fifo_red = 0;
    fifo_ir = 0;
    uint8_t ach_i2c_data[6];

    // read and clear status register
    IIC_Read_Byte(MAX30102_Device_address, REG_INTR_STATUS_1);
    IIC_Read_Byte(MAX30102_Device_address, REG_INTR_STATUS_2);

    ach_i2c_data[0] = REG_FIFO_DATA;

    IIC_Read_Array(MAX30102_Device_address, REG_FIFO_DATA, ach_i2c_data, 6);

    un_temp = ach_i2c_data[0];
    un_temp <<= 14;
    fifo_red += un_temp;
    un_temp = ach_i2c_data[1];
    un_temp <<= 6;
    fifo_red += un_temp;
    un_temp = ach_i2c_data[2];
    un_temp >>= 2;
    fifo_red += un_temp;

    un_temp = ach_i2c_data[3];
    un_temp <<= 14;
    fifo_ir += un_temp;
    un_temp = ach_i2c_data[4];
    un_temp <<= 6;
    fifo_ir += un_temp;
    un_temp = ach_i2c_data[5];
    un_temp >>= 2;
    fifo_ir += un_temp;

    if (fifo_ir <= 10000) {
        fifo_ir = 0;
    }
    if (fifo_red <= 10000) {
        fifo_red = 0;
    }
}

// 获取本周期采集的心率和血氧
HrSo2 getHrSo2(void){
    // 找到整个周期内最大值和最小值
    uint16_t redMax,redMin,irMax,irMin,redAc,redDc,irAc,irDc,irTemp;
    float R2;
    uint16_t samplingNum=0;
    HrSo2 hsData={0,0};
    if (HAL_GPIO_ReadPin(INT_GPIO_Port,INT_Pin) == GPIO_PIN_SET) {
        return hsData;
    }
    for (size_t i = 0; i < 64; i++){    
        max30102_read_fifo();
        if(irTemp != fifo_ir){
            irTemp = fifo_ir;
            samplingNum++;
        }
        if(i == 0){
            redMax = fifo_red;
            redMin = fifo_red;
            irMax = fifo_ir;
            irMin = fifo_ir;
        }else{
            if(fifo_red > redMax){redMax = fifo_red;}
            if(fifo_red < redMin){redMin = fifo_red;}
            if(fifo_ir > irMax){irMax = fifo_ir;}
            if(fifo_ir < irMin){irMin = fifo_ir;}
        }
    }

    //计算心率 
    hsData.hr = samplingNum * 1.7f;
    if(hsData.hr < 30){
        hsData.hr = 0;
        hsData.so2 = 0;
        return hsData;
    }

    redAc = redMax-redMin;//单个周期内最大最小数据差为交流分量
	redDc = redMin;		//数据=直流分量+交流分量
	irAc = irMax-irMin;//同理
	irDc = irMin;

	// 结果生成，数据较为稳定，开头几个数据可以不要，比较不稳
	R2 = ((float)redAc * (float)irDc)/((float)irAc * (float)redDc);
	hsData.so2 =-45.060*R2*R2 + 30.354 *R2 + 94.845;
    if(hsData.so2 > 99.99){hsData.so2 = 99.99;}
    if(hsData.so2 < 80){hsData.so2 = 0;hsData.hr=0;}
    return hsData;
}

// 计算一个数组的平均值
uint16_t Average(uint16_t* Data,uint8_t lenth){
    uint32_t sum = 0;
    for(uint8_t i=0;i<lenth;i++){
        sum = sum + Data[i];
    }
    return sum/lenth;
}