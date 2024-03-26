#include "iic.h"
#include "app.h"
// HAL_StatusTypeDef HAL_I2C_Mem_Write_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size);
// HAL_StatusTypeDef HAL_I2C_Mem_Read_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size);

void IIC_Write_Byte(uint8_t device_addr, uint8_t register_addr, uint8_t data) {
    IIC_Write_Array(device_addr,register_addr,&data,1);
}

uint8_t IIC_Read_Byte(uint8_t device_addr, uint8_t register_addr) {
    uint8_t data;
    IIC_Read_Array(device_addr,register_addr,&data,1);
    return data;
}

uint8_t IIC_Write_Array(uint8_t device_addr, uint16_t register_addr, u8 *Data,uint16_t Num) {
    HAL_I2C_Mem_Write(&hi2c1, device_addr, register_addr, I2C_MEMADD_SIZE_8BIT,Data, Num, 100);
    // HAL_I2C_Mem_Write_DMA(&hi2c1, device_addr, register_addr, I2C_MEMADD_SIZE_8BIT,Data, Num);
    return 1;
}

uint8_t IIC_Read_Array(uint8_t device_addr, uint16_t register_addr, u8 *Data,uint16_t Num) {
    HAL_I2C_Mem_Read(&hi2c1, device_addr, register_addr, I2C_MEMADD_SIZE_8BIT,Data, Num, 100);
    // HAL_I2C_Mem_Read_DMA(&hi2c1, device_addr, register_addr, I2C_MEMADD_SIZE_8BIT,Data, Num);
    return 1;
}