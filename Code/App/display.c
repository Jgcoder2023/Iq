#include "display.h"
#include "pic.h"
#include "rgb.h"
#include <stdio.h>
#include <stdlib.h>

// 定义全局控制数据体
DisplayData DD;

// 初始化页面（也就是首页选择iq充值）
void DFSelectIQ(void) {
    DisplayInit(DpSelectIQ);
    LCD_ShowChinese(22,17,(u8*)"智商力量充值机",BLACK,WHITE,16,0);
    LCD_ShowPicture(32,17 + 16 + 8,35,41,gImage_zs);            // 智商亮
    LCD_ShowPicture(32 + 35 + 29,17 + 16 + 8,29,40,gImage_llh); // 力量灰
    LCD_ShowPicture(45,17 + 16 + 8 + 40 + 2,10,8,gImage_gtriangle); // 智商的下箭头
    // LCD_ShowPicture(32+35+29+10,17+16+9+40,10,8,gImage_ytriangle);
    // //力量下的箭头
    LCD_ShowPicture(32 + 35 + 29 + 10,17 + 16 + 9 + 40,10,8,gImage_wtriangle); // 白色箭头
    LCD_ShowChinese(28,17 + 16 + 8 + 40 + 2 + 8 + 5,(u8*)"智商充值",GRAY,WHITE,12,0);
    LCD_ShowChinese(32 + 35 + 20,17 + 16 + 8 + 40 + 2 + 8 + 5,(u8*)"力量充值",GRAY,WHITE,12,0);
}

// 首页选择力量充值
void DFSelectPower(void) {
    DisplayInit(DpSelectPower);
    LCD_ShowChinese(22,17,(u8*)"智商力量充值机",BLACK,WHITE,16,0);
    LCD_ShowPicture(32,17 + 16 + 8,35,41,gImage_zsh);          // 智商灰
    LCD_ShowPicture(32 + 35 + 29,17 + 16 + 8,29,40,gImage_ll); // 力量亮
    // LCD_ShowPicture(45,17+16+8+40+2,10,8,gImage_gtriangle);
    // //智商的下箭头
    LCD_ShowPicture(45,17 + 16 + 8 + 40 + 2,10,8,gImage_wtriangle); // 白色箭头
    LCD_ShowPicture(32 + 35 + 29 + 10,17 + 16 + 9 + 40,10,8,gImage_ytriangle); // 力量下的箭头
    LCD_ShowChinese(28,17 + 16 + 8 + 40 + 2 + 8 + 5,(u8*)"智商充值",GRAY,WHITE,12,0);
    LCD_ShowChinese(32 + 35 + 20,17 + 16 + 8 + 40 + 2 + 8 + 5,(u8*)"力量充值",GRAY,WHITE,12,0);
}
// 设置iq充值页面（设置的数据开始闪烁）
void DFSetIQ(void) {
    if (DD.IsRefresh == 1) {
        if (DD.FlickerNum <= 5) {
            if (DD.SetIQValue > 99) {
                LCD_ShowIntNum(56,42,DD.SetIQValue,3,BLUE,WHITE,32); // 三个显示的位置
            } else {
                LCD_ShowIntNum(64,42,DD.SetIQValue,2,BLUE,WHITE,32); // 两个现实的位置
                LCD_ShowString(64 + 32,42,(u8*)" ",BLUE,WHITE,32,0); // 最后一位补白
                LCD_DrawSolidRectangle(56,42,64,42 + 32,WHITE); // 补足前面的空白
            }
        } else {
            LCD_ShowString(56,42,(u8*)"   ",BLUE,WHITE,32,0); // 空白让其闪烁起来
            if (DD.FlickerNum >= 10) {
                DD.FlickerNum = 0;
            }
        }
        DD.FlickerNum++;
        return;
    }
    LCD_ShowChinese(10,5,(u8*)"设置需要充值的智商能量",BLACK,WHITE,12,0);
    LCD_ShowChinese(10,20,(u8*)"充能范围",BLACK,WHITE,12,0);
    LCD_ShowString(10 + 12 * 4,20,(u8*)":70-170",MAGENTA,WHITE,12,0);
    LCD_ShowIntNum(64,42,DD.SetIQValue,2,BLUE,WHITE,32); // 两个现实的位置
    LCD_ShowChinese(56,90,(u8*)"开始充能",BLACK,WHITE,12,0);
    LCD_DrawRectangle(56 - 6,86,56 + 6 + 12 * 4,90 + 12 + 4,BLACK);
    DD.IsRefresh = 1;
    DD.SelectIQPower = 1; //设置选择了IQ
}
// 设置力量充值页面（设置的数据开始闪烁）
void DFSetPower(void) {
    if (DD.IsRefresh == 1) {
        if (DD.FlickerNum <= 5) {
            if (DD.SetPowerValue > 99) {
                LCD_ShowIntNum(56,42,DD.SetPowerValue,3,BLUE,WHITE,32); // 三个显示的位置
            } else {
                LCD_ShowIntNum(64,42,DD.SetPowerValue,2,BLUE,WHITE,32); // 两个现实的位置
                LCD_ShowString(64 + 32,42,(u8*)" ",BLUE,WHITE,32,0); // 最后一位补白
                LCD_DrawSolidRectangle(56,42,64,42 + 32,WHITE); // 补足前面的空白
            }
        } else {
            LCD_ShowString(56,42,(u8*)"   ",BLUE,WHITE,32,0); // 空白让其闪烁起来
            if (DD.FlickerNum >= 10) {
                DD.FlickerNum = 0;
            }
        }
        DD.FlickerNum++;
        return;
    }
    LCD_ShowChinese(10,5,(u8*)"设置需要充值的力量能量",BLACK,WHITE,12,0);
    LCD_ShowChinese(10,20,(u8*)"充值范围",BLACK,WHITE,12,0);
    LCD_ShowString(10 + 12 * 4,20,(u8*)":10-700",MAGENTA,WHITE,12,0);
    LCD_ShowIntNum(64,42,DD.SetPowerValue,2,BLUE,WHITE,32); // 两个现实的位置
    LCD_ShowChinese(56,90,(u8*)"开始充能",BLACK,WHITE,12,0);
    LCD_DrawRectangle(56 - 6,86,56 + 6 + 12 * 4,90 + 12 + 4,BLACK);
    DD.IsRefresh = 1;
    DD.SelectIQPower = 2; //设置选择了PWOER
}
// 设置iq充值页面（选中开始充值按钮红色）
void DFStartSetIQ(void) {
    LCD_ShowChinese(10,5,(u8*)"设置需要充值的智商能量",BLACK,WHITE,12,0);
    LCD_ShowChinese(10,20,(u8*)"充能范围",BLACK,WHITE,12,0);
    LCD_ShowString(10 + 12 * 4,20,(u8*)":70-170",MAGENTA,WHITE,12,0);
    if (DD.SetIQValue > 99) {
        LCD_ShowIntNum(56,42,DD.SetIQValue,3,BLACK,WHITE,32); // 三个显示的位置
    } else {
        LCD_ShowIntNum(64,42,DD.SetIQValue,2,BLACK,WHITE,32); // 两个现实的位置
    }
    LCD_ShowChinese(56,90,(u8*)"开始充能",BLUE,WHITE,12,0);
    LCD_DrawRectangle(56 - 6,86,56 + 6 + 12 * 4,90 + 12 + 4,BLUE); // 选中按钮变红
    DD.IsRefresh = 0;
}
// 设置力量充值页面（选中开始充值按钮红色）
void DFStartSetPower(void) {
    LCD_ShowChinese(10,5,(u8*)"设置需要充值的力量能量",BLACK,WHITE,12,0);
    LCD_ShowChinese(10,20,(u8*)"充能范围",BLACK,WHITE,12,0);
    LCD_ShowString(10 + 12 * 4,20,(u8*)":10kg - 700kg",MAGENTA,WHITE,12,0);
    if (DD.SetIQValue > 99) {
        LCD_ShowIntNum(56,42,DD.SetPowerValue,3,BLACK,WHITE,32); // 三个显示的位置
    } else {
        LCD_ShowIntNum(64,42,DD.SetPowerValue,2,BLACK,WHITE,32); // 两个现实的位置
    }
    LCD_ShowChinese(56,90,(u8*)"开始充能",BLUE,WHITE,12,0);
    LCD_DrawRectangle(56 - 6,86,56 + 6 + 12 * 4,90 + 12 + 4,BLUE); // 选中按钮变红
    DD.IsRefresh = 0;
}
// 充值前的提醒事项
void DFTip(void) {
    LCD_ShowChinese(48,12,(u8*)"温馨提示",RED,WHITE,16,0);
    LCD_ShowChinese(2,38,(u8*)"请佩戴好充能电极和监测电极",RED,WHITE,12,0);
    LCD_ShowChinese(26,52,(u8*)"如有不适请立即停止",RED,WHITE,12,0);
    LCD_ShowChinese(56,90,(u8*)"确认充能",RED,WHITE,12,0);
    LCD_DrawRectangle(56 - 6,86,56 + 6 + 12 * 4,90 + 12 + 4,RED); // 选中变成红色
    DD.IsRefresh = 0;
}
// 充值IQ监控    进度条数据需要变化
void DFChargeIQ(void) {
    static u8 speedRefreshFalg=0,StopTimer=0;
    u8 speedLenth; //进度条长度
    static char hrValue[5],so2Value[11],speeds[6];
    if (DD.IsRefresh == 1) {
        if(DD.hrValue == 0){
            LCD_ShowString(28+4*12,72,(u8*)":",GRAY,WHITE,12,0);
            LCD_ShowChinese(28+5*12,72,(u8*)"未佩戴电极",GRAY,WHITE,12,0);
            speedRefreshFalg=1;
            if(DD.IQspeed > 0){
                StopTimer++;    //计数中途停止的时间
            }
            if(StopTimer > 30){ //超过3S则 充值失败
                StopTimer = 0; 
                changePage(DpShowFail,true);
                DD.IsRefresh = 0;
                DD.IsMax30102 = 0;
                DD.LedDirection = 2;   //led向左移动，也就是抽回
                return;
            }
        }else{
            StopTimer = 0;
            DD.IQspeed += rands()/100;
            speedLenth = (u8)(1.5f * DD.IQspeed);
            if(DD.IQspeed > 100){
                DD.IQspeed = 100;
                speedLenth = 150;
            }
            sprintf(speeds,":%3d%%",DD.IQspeed);
            if(speedRefreshFalg == 1){
                LCD_DrawSolidRectangle(28+4*12,72,28+10*12,72+12,WHITE);
                speedRefreshFalg = 0;
            }
            LCD_ShowString(28 + 4 * 12,72,(u8*)&speeds,GRAY,WHITE,12,0);
        }
        sprintf(hrValue,":%3d",DD.hrValue);
        sprintf(so2Value,":%5.2f%%",DD.so2Value);
        LCD_ShowString(28 + 4 * 12,24,(u8*)&hrValue,GRAY,WHITE,12,0);
        LCD_ShowString(28 + 4 * 12,24 + 14 + 8,(u8*)&so2Value,GRAY,WHITE,12,0);
        for (u16 i = 11; i < speedLenth; i++) {
            LCD_DrawLine(i,72 + 22 + 1,i,72 + 22 + 20,GRAY); // 画线  画进度条里面
        }

        if(DD.IQspeed >= 100){//说明充值完成
            DD.IQspeed = 0;
            DD.IsRefresh = 0;
            DD.IsMax30102 = 0;
            changePage(DpShowSuccess,true);
        }
        return;
    }
    LCD_ShowChinese(10,2,(u8*)"智商充值监测",BLACK,WHITE,12,0);
    LCD_ShowPicture(10,24,16,14,gImage_xl); // 心率图标
    LCD_ShowChinese(10 + 16 + 2,24,(u8*)"心率监测",GRAY,WHITE,12,0);
    LCD_ShowPicture(10,24 + 14 + 6,16,16,gImage_so2); // 血氧图标
    LCD_ShowChinese(10 + 16 + 2,24 + 14 + 8,(u8*)"血氧监测",GRAY,WHITE,12,0);
    LCD_ShowPicture(10,24 + 14 + 6 + 16 + 10,16,16,gImage_jd); // 进度图标
    LCD_ShowChinese(10 + 16 + 2,72,(u8*)"充能进度",GRAY,WHITE,12,0);
    LCD_DrawRectangle(10,72 + 22,160 - 10,72 + 22 + 20,BLACK); // 画进度条外框
    DD.IsRefresh = 1;
    DD.IsMax30102 = 1;
    DD.LedDirection = 1;   //led向右移动
}
// 力量监控  进度条数据需要变化
void DFChargePower(void) {
    static u8 speedRefreshFalg=0,StopTimer=0;
    u8 speedLenth; //进度条长度
    static char hrValue[5],so2Value[11],speeds[6];
    if (DD.IsRefresh == 1) {
        if(DD.hrValue == 0){
            LCD_ShowString(28+4*12,72,(u8*)":",GRAY,WHITE,12,0);
            LCD_ShowChinese(28+5*12,72,(u8*)"未佩戴电极",GRAY,WHITE,12,0);
            speedRefreshFalg=1;
            if(DD.PowerSpeed > 0){
                StopTimer++;    //计数中途停止的时间
            }
            if(StopTimer > 30){ //超过3S则 充值失败
                StopTimer = 0; 
                changePage(DpShowFail,true);
                DD.IsRefresh = 0;
                DD.IsMax30102 = 0;
                DD.LedDirection = 2;   //led向左移动，也就是抽回
                return;
            }
        }else{
            StopTimer = 0;
            DD.PowerSpeed += rands()/100;
            speedLenth = (u8)(1.5f * DD.PowerSpeed);
            if(DD.PowerSpeed > 100){
                DD.PowerSpeed = 100;
                speedLenth = 150;
            }
            sprintf(speeds,":%3d%%",DD.PowerSpeed);
            if(speedRefreshFalg == 1){
                LCD_DrawSolidRectangle(28+4*12,72,28+10*12,72+12,WHITE);
                speedRefreshFalg = 0;
            }
            LCD_ShowString(28 + 4 * 12,72,(u8*)&speeds,GRAY,WHITE,12,0);
        }
        sprintf(hrValue,":%3d",DD.hrValue);
        sprintf(so2Value,":%5.2f%%",DD.so2Value);
        LCD_ShowString(28 + 4 * 12,24,(u8*)&hrValue,GRAY,WHITE,12,0);
        LCD_ShowString(28 + 4 * 12,24 + 14 + 8,(u8*)&so2Value,GRAY,WHITE,12,0);
        for (u16 i = 11; i < speedLenth; i++) {
            LCD_DrawLine(i,72 + 22 + 1,i,72 + 22 + 20,GRAY); // 画线  画进度条里面
        }

        if(DD.PowerSpeed >= 100){//说明充值完成
            DD.PowerSpeed = 0;
            DD.IsRefresh = 0;
            DD.IsMax30102 = 0;
            changePage(DpShowSuccess,true);
        }
        return;
    }
    LCD_ShowChinese(10,2,(u8*)"力量充值监测",BLACK,WHITE,12,0);
    LCD_ShowPicture(10,24,16,14,gImage_xl); // 心率图标
    LCD_ShowChinese(10 + 16 + 2,24,(u8*)"心率监测",GRAY,WHITE,12,0);
    LCD_ShowPicture(10,24 + 14 + 6,16,16,gImage_so2); // 血氧图标
    LCD_ShowChinese(10 + 16 + 2,24 + 14 + 8,(u8*)"血氧监测",GRAY,WHITE,12,0);
    LCD_ShowPicture(10,24 + 14 + 6 + 16 + 10,16,16,gImage_jd); // 进度图标
    LCD_ShowChinese(10 + 16 + 2,72,(u8*)"充能进度",GRAY,WHITE,12,0);
    LCD_DrawRectangle(10,72 + 22,160 - 10,72 + 22 + 20,BLACK); // 画进度条外框
    DD.IsRefresh = 1;
    DD.IsMax30102 = 1;
    DD.LedDirection = 1;   //led向右移动

    // LCD_ShowChinese(10,2,(u8*)"力量充值监测",BLACK,WHITE,12,0);
    // LCD_ShowPicture(10,24,16,14,gImage_xl); // 心率图标
    // LCD_ShowChinese(10 + 16 + 2,24,(u8*)"心率监测",GRAY,WHITE,12,0);
    // LCD_ShowString(28 + 4 * 12,24,(u8*)":68",GRAY,WHITE,12,0);
    // LCD_ShowPicture(10,24 + 14 + 6,16,16,gImage_so2); // 血氧图标
    // LCD_ShowChinese(10 + 16 + 2,24 + 14 + 8,(u8*)"血氧监测",GRAY,WHITE,12,0);
    // LCD_ShowString(28 + 4 * 12,24 + 14 + 8,(u8*)":96.65%",GRAY,WHITE,12,0);
    // LCD_ShowPicture(10,24 + 14 + 6 + 16 + 10,16,16,gImage_jd); // 进度图标
    // LCD_ShowChinese(10 + 16 + 2,72,(u8*)"充能进度",GRAY,WHITE,12,0);
    // LCD_ShowString(28 + 4 * 12,72,(u8*)":13%",GRAY,WHITE,12,0);
    // LCD_DrawRectangle(10,72 + 22,160 - 10,72 + 22 + 20,BLACK); // 画进度条外框
    // for (u16 i = 11; i < 150; i++) {
    //     LCD_DrawLine(i,72 + 22 + 1,i,72 + 22 + 20,GRAY); // 画线  画进度条里面
    // }
}
// 成功页
void DFShowSuccess(void) {
    LCD_ShowChinese(10,6,(u8*)"充能结果",BLACK,WHITE,12,0);
    LCD_ShowPicture(65,40,30,30,gImage_success);
    LCD_ShowChinese(48,82,(u8*)"充值成功",GREEN,WHITE,16,0);
}
// 失败页
void DFShowFail(void) {
    LCD_ShowChinese(10,6,(u8*)"充能结果",BLACK,WHITE,12,0);
    if(DD.IQspeed > 0 || DD.PowerSpeed > 0){
        LCD_ShowPicture(65,30,30,30,gImage_fail);
        LCD_ShowChinese(48,66,(u8*)"充值失败",RED,WHITE,16,0);
        LCD_ShowChinese(20,86,(u8*)"正在抽回已充值的能量",BLACK,WHITE,12,0);
        LCD_ShowChinese(62,86 + 12 + 4,(u8*)"请稍后",BLACK,WHITE,12,0);
    }else{
        LCD_ShowPicture(65,40,30,30,gImage_fail);
        LCD_ShowChinese(48,82,(u8*)"充值失败",RED,WHITE,16,0);
    }
}

// 显示函数的初始化
static DisplayFunc DF[DpCount] = {
    {DpSelectIQ,DFSelectIQ},
    {DpSelectPower,DFSelectPower},
    {DpSetIQ,DFSetIQ},
    {DpStartSetIQ,DFStartSetIQ},
    {DpSetPower,DFSetPower},
    {DpStartSetPower,DFStartSetPower},
    {DpTip,DFTip},
    {DpChargeIQ,DFChargeIQ},
    {DpChargePower,DFChargePower},
    {DpShowSuccess,DFShowSuccess},
    {DpShowFail,DFShowFail},
};

// 更新LCD
void task_Lcd(void) {
    if (DD.ThisDisplay == DD.PrevDisplay && DD.IsRefresh == 0) {
        return;
    }
    DD.PrevDisplay = DD.ThisDisplay;
    for (size_t i = 0; i < DpCount; i++) {
        if (DD.ThisDisplay == DF[i].Self) {
            DF[i].Func();
        }
    }
}

// 按键扫描
void task_Key(void) {
    KeyInputScan();
    KeyValueCalculate();

    switch (DD.ThisDisplay) {
    case DpSelectIQ:
        if (R_KeyState(2) || R_KeyState(0)) {
            changePage(DpSelectPower,false);
        }
        if (R_KeyState(1)) {
            changePage(DpSetIQ,true);
        }
        break;
    case DpSelectPower:
        if (R_KeyState(2) || R_KeyState(0)) {
            changePage(DpSelectIQ,false);
        }
        if (R_KeyState(1)) {
            changePage(DpSetPower,true);
        }
        break;
    case DpSetIQ:
        if (R_KeyState(0) || D_KeyState(0)) {
            if (DD.SetIQValue <= 70) {return;}
            DD.SetIQValue--;
            DD.FlickerNum = 0;
        }
        if (R_KeyState(2) || D_KeyState(2)) {
            if (DD.SetIQValue >= 170) {return;}
            DD.SetIQValue++;
            DD.FlickerNum = 0;
        }
        if (R_KeyState(1)) {
            changePage(DpStartSetIQ,true);
        }
        break;
    case DpSetPower:
        if (R_KeyState(0) || D_KeyState(0)) {
            if (DD.SetPowerValue <= 70) {return;}
            DD.SetPowerValue--;
            DD.FlickerNum = 0;
        }
        if (R_KeyState(2) || D_KeyState(2)) {
            if (DD.SetPowerValue >= 170) {return;}
            DD.SetPowerValue++;
            DD.FlickerNum = 0;
        }
        if (R_KeyState(1)) {
            changePage(DpStartSetPower,true);
        }
        break;
    case DpStartSetIQ:
    case DpStartSetPower:
        if (R_KeyState(1)) {
            changePage(DpTip,true);
        }
        break;
    case DpTip:
        if (R_KeyState(1)) {
            if(DD.SelectIQPower == 1){
                changePage(DpChargeIQ,true);
            }
            if(DD.SelectIQPower == 2){
                changePage(DpChargePower,true);
            }
        }
        break;
    case DpChargeIQ:
    case DpChargePower:
        // 任意键切到失败 
        if (R_KeyState(0) || R_KeyState(1) || R_KeyState(2)) {
            changePage(DpShowFail,true);

            DD.IsRefresh = 0;
            DD.IsMax30102 = 0;
            if(DD.IQspeed > 0 || DD.PowerSpeed > 0){
                //说明有充值   需要抽回
                DD.LedDirection = 2;
            }else{
                //没有 直接结束
                DD.LedDirection = 0;
            }
        }
        break;
    case DpShowSuccess:
    case DpShowFail:
        // 成功页或错误页按任意键切到首页 
        if (R_KeyState(0) || R_KeyState(1) || R_KeyState(2)) {
            if(DD.SelectIQPower == 2){
                changePage(DpSelectPower,true);
            }else{
                changePage(DpSelectIQ,true);
            }
        }
        break;
    default:
        break;
    }
}

// LED
void task_Led(void) {
    static u32 ledData = 0b11100000000000000000000000000000;  // 初始数据
    static u8 colour = 0;
    if(DD.LedDirection == 0 || DD.LedDirection == 3){
        return;
    }

    // 根据选择类型决定颜色 4是绿色，6是蓝色，0是透明
    if(DD.SelectIQPower == 1){
        colour = 4;
    }else if(DD.SelectIQPower == 2){
        colour = 6;
    }else{
        colour = 0;
    }

    if (DD.LedDirection == 1) {
        // 说明已经充值成功，执行最后一圈
        if(DD.ThisDisplay == DpShowSuccess){
            RGB_Flowing(ledData,colour);
            ledData = ledData >> 1U;
            if (ledData <= 0X07) {
				ledData = 0XE0000000;
                LedOff(); //全灭
                DD.LedDirection = 0;
            }
        }

        if(DD.hrValue > 0){
            RGB_Flowing(ledData,colour);
            ledData = ledData >> 1U;
            if (ledData <= 0X03) {
                ledData = 0XE0000000;
            }
        }
    }
    if(DD.LedDirection == 2) {
        RGB_Flowing(ledData,colour);
        ledData = ledData << 1U;
        if(DD.IQspeed > 0){
            DD.IQspeed--;
        }
        if (ledData >= 0X80000000) {
            ledData = 0X1C;
            
            if(DD.IQspeed == 0){
                LedOff();//全灭
                DD.LedDirection = 0;
                if(DD.SelectIQPower == 2){
                    changePage(DpSelectPower,true);
                }else{
                    changePage(DpSelectIQ,true);
                }
            }
        }
    }
}


// 切换页面
void changePage(enum DisplayState pageName,bool isClearScreen){
    DD.PrevDisplay = DD.ThisDisplay;
    DD.ThisDisplay = pageName;
    if(isClearScreen == true){
        LCD_Fill(0,0,LCD_W,LCD_H,WHITE); // 清屏
    }
}

// 整体的初始化
void DisplayInit(enum DisplayState selectPage){
    DisplayData dd = {
        .ThisDisplay = selectPage,
        .PrevDisplay = DpCount,

        .SetIQValue = 90,
        .SetPowerValue = 50,
        .IQspeed = 0,
        .PowerSpeed = 0,

        .LedDirection = 0,
        .SelectIQPower=0,
        .IsMax30102 = 0,
        .IsRefresh = 0,
        .FlickerNum = 0
    };
    DD = dd;
}

void task_Max30102(void) {
    HrSo2 HrSo2Data;
    if (DD.IsMax30102 == 1) {
        HrSo2Data = getHrSo2();
        DD.hrValue = HrSo2Data.hr;
        DD.so2Value = HrSo2Data.so2;
    }else{
        DD.hrValue = 0;
        DD.so2Value = 0;
    }
}

// 产生随机数
u8 rands(void) {
    static u8 randValue;
    srand(randValue + DD.SetIQValue + DD.SetPowerValue + GetCounter()); // 随机填写一个参数
    randValue = rand();                   // 生成一个随机值
    return randValue;
}