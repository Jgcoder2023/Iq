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
    DpSelectIQ,   //Ĭ��״̬  ѡ��iq
    DpSelectPower,  //ѡ������
    DpSetIQ,        //����iq��ֵ ���õ����ݿ�ʼ��˸
    DpStartSetIQ,   //����iq��ֵ ѡ�п�ʼ��ֵ����
    DpSetPower,
    DpStartSetPower,
    DpTip,     //������ֵ����ʾҳ
    DpChargeIQ,     //��ֵ���
    DpChargePower,  
    DpShowSuccess,  
    DpShowFail,

    DpCount  //�����������
};

// ��ʾ�ṹ��
typedef struct{
    enum DisplayState Self;    // ��ǰ��ʾ
    void (*Func)(void);        // ��ʾִ�к���
} DisplayFunc;


typedef struct{
    enum DisplayState  ThisDisplay;   // ��ǰ��ʾ
    enum DisplayState  PrevDisplay;   // ��һ����ʾ

    // ������
    u8 SetIQValue;     //���ó�ֵ��IQ����
    u8 SetPowerValue;  //���ó�ֵ����������
    u8 IQspeed;   //IQ��ֵ�Ľ���
    u8 PowerSpeed; //POWER��ֵ�Ľ���

    u8 hrValue;  //����
    float so2Value; //Ѫ��

    u8 FlickerNum;     //��˸ʱ���ʱ��־

    // ��־��
    u8 LedDirection:2;  //led��ʾ�ķ���0 3����ʾ 1�� 2��
    u8 SelectIQPower:2; //0δѡ�� 1ѡ��iq 2ѡ��power
    u8 IsMax30102:1;  //�Ƿ�ʼ����Ѫ�����
    u8 IsRefresh:1;   //��ǰ�˵����Ƿ���Ҫǿ��ˢ��
    u8 SelectIQ:1;
} DisplayData;




void task_Lcd(void);
void task_Led(void);
void task_Key(void);
void task_Max30102(void);
void changePage(enum DisplayState pageName,bool isClearScreen);   //�л�ҳ��
void DisplayInit(enum DisplayState selectPage);
u8 rands(void);

#endif //__DISPLAY_H__



