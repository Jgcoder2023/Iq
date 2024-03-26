#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "app.h"
#include "lcd.h"
#include "lcd_init.h"
#include "led.h"
#include "rgb.h"
#include "MAX30102.h"
#include "key.h"

enum DisplayState{
    DpSelectIQ,   //默认状态  选择iq
    DpSelectPower,  //选择力量
    DpSetIQ,        //设置iq充值 设置的数据开始闪烁
    DpStartSetIQ,   //设置iq充值 选中开始充值界面
    DpSetPower,
    DpStartSetPower,
    DpTip,     //启动充值的提示页
    DpChargeIQ,     //充值监控
    DpChargePower,  
    DpShowSuccess,  
    DpShowFail,

    DpCount  //用于数组计数
};

// 显示结构体
typedef struct{
    enum DisplayState Self;    // 当前显示
    void (*Func)(void);        // 显示执行函数
} DisplayFunc;


typedef struct{
    enum DisplayState  ThisDisplay;   // 当前显示
    enum DisplayState  PrevDisplay;   // 上一个显示

    // 数据类
    u8 SetIQValue;     //设置充值的IQ数据
    u8 SetPowerValue;  //设置充值的力量数据
    u8 IQspeed;   //IQ充值的进度
    u8 PowerSpeed; //POWER充值的进度

    u8 hrValue;  //心率
    float so2Value; //血氧

    u8 FlickerNum;     //闪烁时间计时标志

    // 标志类
    u8 LedDirection:2;  //led显示的方向0 3不显示 1右 2左
    u8 SelectIQPower:2; //0未选择 1选择iq 2选择power
    u8 IsMax30102:1;  //是否开始心率血氧监测
    u8 IsRefresh:1;   //当前菜单下是否需要强制刷新
    u8 SelectIQ:1;
} DisplayData;




void task_Lcd(void);
void task_Led(void);
void task_Key(void);
void task_Max30102(void);
void changePage(enum DisplayState pageName,bool isClearScreen);   //切换页面
void DisplayInit(enum DisplayState selectPage);
u8 rands(void);

#endif //__DISPLAY_H__



