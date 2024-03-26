#include "display.h"
#include "pic.h"
#include "rgb.h"
#include <stdio.h>
#include <stdlib.h>

// ����ȫ�ֿ���������
DisplayData DD;

// ��ʼ��ҳ�棨Ҳ������ҳѡ��iq��ֵ��
void DFSelectIQ(void) {
    DisplayInit(DpSelectIQ);
    LCD_ShowChinese(22,17,(u8*)"����������ֵ��",BLACK,WHITE,16,0);
    LCD_ShowPicture(32,17 + 16 + 8,35,41,gImage_zs);            // ������
    LCD_ShowPicture(32 + 35 + 29,17 + 16 + 8,29,40,gImage_llh); // ������
    LCD_ShowPicture(45,17 + 16 + 8 + 40 + 2,10,8,gImage_gtriangle); // ���̵��¼�ͷ
    // LCD_ShowPicture(32+35+29+10,17+16+9+40,10,8,gImage_ytriangle);
    // //�����µļ�ͷ
    LCD_ShowPicture(32 + 35 + 29 + 10,17 + 16 + 9 + 40,10,8,gImage_wtriangle); // ��ɫ��ͷ
    LCD_ShowChinese(28,17 + 16 + 8 + 40 + 2 + 8 + 5,(u8*)"���̳�ֵ",GRAY,WHITE,12,0);
    LCD_ShowChinese(32 + 35 + 20,17 + 16 + 8 + 40 + 2 + 8 + 5,(u8*)"������ֵ",GRAY,WHITE,12,0);
}

// ��ҳѡ��������ֵ
void DFSelectPower(void) {
    DisplayInit(DpSelectPower);
    LCD_ShowChinese(22,17,(u8*)"����������ֵ��",BLACK,WHITE,16,0);
    LCD_ShowPicture(32,17 + 16 + 8,35,41,gImage_zsh);          // ���̻�
    LCD_ShowPicture(32 + 35 + 29,17 + 16 + 8,29,40,gImage_ll); // ������
    // LCD_ShowPicture(45,17+16+8+40+2,10,8,gImage_gtriangle);
    // //���̵��¼�ͷ
    LCD_ShowPicture(45,17 + 16 + 8 + 40 + 2,10,8,gImage_wtriangle); // ��ɫ��ͷ
    LCD_ShowPicture(32 + 35 + 29 + 10,17 + 16 + 9 + 40,10,8,gImage_ytriangle); // �����µļ�ͷ
    LCD_ShowChinese(28,17 + 16 + 8 + 40 + 2 + 8 + 5,(u8*)"���̳�ֵ",GRAY,WHITE,12,0);
    LCD_ShowChinese(32 + 35 + 20,17 + 16 + 8 + 40 + 2 + 8 + 5,(u8*)"������ֵ",GRAY,WHITE,12,0);
}
// ����iq��ֵҳ�棨���õ����ݿ�ʼ��˸��
void DFSetIQ(void) {
    if (DD.IsRefresh == 1) {
        if (DD.FlickerNum <= 5) {
            if (DD.SetIQValue > 99) {
                LCD_ShowIntNum(56,42,DD.SetIQValue,3,BLUE,WHITE,32); // ������ʾ��λ��
            } else {
                LCD_ShowIntNum(64,42,DD.SetIQValue,2,BLUE,WHITE,32); // ������ʵ��λ��
                LCD_ShowString(64 + 32,42,(u8*)" ",BLUE,WHITE,32,0); // ���һλ����
                LCD_DrawSolidRectangle(56,42,64,42 + 32,WHITE); // ����ǰ��Ŀհ�
            }
        } else {
            LCD_ShowString(56,42,(u8*)"   ",BLUE,WHITE,32,0); // �հ�������˸����
            if (DD.FlickerNum >= 10) {
                DD.FlickerNum = 0;
            }
        }
        DD.FlickerNum++;
        return;
    }
    LCD_ShowChinese(10,5,(u8*)"������Ҫ��ֵ����������",BLACK,WHITE,12,0);
    LCD_ShowChinese(10,20,(u8*)"���ܷ�Χ",BLACK,WHITE,12,0);
    LCD_ShowString(10 + 12 * 4,20,(u8*)":70-170",MAGENTA,WHITE,12,0);
    LCD_ShowIntNum(64,42,DD.SetIQValue,2,BLUE,WHITE,32); // ������ʵ��λ��
    LCD_ShowChinese(56,90,(u8*)"��ʼ����",BLACK,WHITE,12,0);
    LCD_DrawRectangle(56 - 6,86,56 + 6 + 12 * 4,90 + 12 + 4,BLACK);
    DD.IsRefresh = 1;
    DD.SelectIQPower = 1; //����ѡ����IQ
}
// ����������ֵҳ�棨���õ����ݿ�ʼ��˸��
void DFSetPower(void) {
    if (DD.IsRefresh == 1) {
        if (DD.FlickerNum <= 5) {
            if (DD.SetPowerValue > 99) {
                LCD_ShowIntNum(56,42,DD.SetPowerValue,3,BLUE,WHITE,32); // ������ʾ��λ��
            } else {
                LCD_ShowIntNum(64,42,DD.SetPowerValue,2,BLUE,WHITE,32); // ������ʵ��λ��
                LCD_ShowString(64 + 32,42,(u8*)" ",BLUE,WHITE,32,0); // ���һλ����
                LCD_DrawSolidRectangle(56,42,64,42 + 32,WHITE); // ����ǰ��Ŀհ�
            }
        } else {
            LCD_ShowString(56,42,(u8*)"   ",BLUE,WHITE,32,0); // �հ�������˸����
            if (DD.FlickerNum >= 10) {
                DD.FlickerNum = 0;
            }
        }
        DD.FlickerNum++;
        return;
    }
    LCD_ShowChinese(10,5,(u8*)"������Ҫ��ֵ����������",BLACK,WHITE,12,0);
    LCD_ShowChinese(10,20,(u8*)"��ֵ��Χ",BLACK,WHITE,12,0);
    LCD_ShowString(10 + 12 * 4,20,(u8*)":10-700",MAGENTA,WHITE,12,0);
    LCD_ShowIntNum(64,42,DD.SetPowerValue,2,BLUE,WHITE,32); // ������ʵ��λ��
    LCD_ShowChinese(56,90,(u8*)"��ʼ����",BLACK,WHITE,12,0);
    LCD_DrawRectangle(56 - 6,86,56 + 6 + 12 * 4,90 + 12 + 4,BLACK);
    DD.IsRefresh = 1;
    DD.SelectIQPower = 2; //����ѡ����PWOER
}
// ����iq��ֵҳ�棨ѡ�п�ʼ��ֵ��ť��ɫ��
void DFStartSetIQ(void) {
    LCD_ShowChinese(10,5,(u8*)"������Ҫ��ֵ����������",BLACK,WHITE,12,0);
    LCD_ShowChinese(10,20,(u8*)"���ܷ�Χ",BLACK,WHITE,12,0);
    LCD_ShowString(10 + 12 * 4,20,(u8*)":70-170",MAGENTA,WHITE,12,0);
    if (DD.SetIQValue > 99) {
        LCD_ShowIntNum(56,42,DD.SetIQValue,3,BLACK,WHITE,32); // ������ʾ��λ��
    } else {
        LCD_ShowIntNum(64,42,DD.SetIQValue,2,BLACK,WHITE,32); // ������ʵ��λ��
    }
    LCD_ShowChinese(56,90,(u8*)"��ʼ����",BLUE,WHITE,12,0);
    LCD_DrawRectangle(56 - 6,86,56 + 6 + 12 * 4,90 + 12 + 4,BLUE); // ѡ�а�ť���
    DD.IsRefresh = 0;
}
// ����������ֵҳ�棨ѡ�п�ʼ��ֵ��ť��ɫ��
void DFStartSetPower(void) {
    LCD_ShowChinese(10,5,(u8*)"������Ҫ��ֵ����������",BLACK,WHITE,12,0);
    LCD_ShowChinese(10,20,(u8*)"���ܷ�Χ",BLACK,WHITE,12,0);
    LCD_ShowString(10 + 12 * 4,20,(u8*)":10kg - 700kg",MAGENTA,WHITE,12,0);
    if (DD.SetIQValue > 99) {
        LCD_ShowIntNum(56,42,DD.SetPowerValue,3,BLACK,WHITE,32); // ������ʾ��λ��
    } else {
        LCD_ShowIntNum(64,42,DD.SetPowerValue,2,BLACK,WHITE,32); // ������ʵ��λ��
    }
    LCD_ShowChinese(56,90,(u8*)"��ʼ����",BLUE,WHITE,12,0);
    LCD_DrawRectangle(56 - 6,86,56 + 6 + 12 * 4,90 + 12 + 4,BLUE); // ѡ�а�ť���
    DD.IsRefresh = 0;
}
// ��ֵǰ����������
void DFTip(void) {
    LCD_ShowChinese(48,12,(u8*)"��ܰ��ʾ",RED,WHITE,16,0);
    LCD_ShowChinese(2,38,(u8*)"������ó��ܵ缫�ͼ��缫",RED,WHITE,12,0);
    LCD_ShowChinese(26,52,(u8*)"���в���������ֹͣ",RED,WHITE,12,0);
    LCD_ShowChinese(56,90,(u8*)"ȷ�ϳ���",RED,WHITE,12,0);
    LCD_DrawRectangle(56 - 6,86,56 + 6 + 12 * 4,90 + 12 + 4,RED); // ѡ�б�ɺ�ɫ
    DD.IsRefresh = 0;
}
// ��ֵIQ���    ������������Ҫ�仯
void DFChargeIQ(void) {
    static u8 speedRefreshFalg=0,StopTimer=0;
    u8 speedLenth; //����������
    static char hrValue[5],so2Value[11],speeds[6];
    if (DD.IsRefresh == 1) {
        if(DD.hrValue == 0){
            LCD_ShowString(28+4*12,72,(u8*)":",GRAY,WHITE,12,0);
            LCD_ShowChinese(28+5*12,72,(u8*)"δ����缫",GRAY,WHITE,12,0);
            speedRefreshFalg=1;
            if(DD.IQspeed > 0){
                StopTimer++;    //������;ֹͣ��ʱ��
            }
            if(StopTimer > 30){ //����3S�� ��ֵʧ��
                StopTimer = 0; 
                changePage(DpShowFail,true);
                DD.IsRefresh = 0;
                DD.IsMax30102 = 0;
                DD.LedDirection = 2;   //led�����ƶ���Ҳ���ǳ��
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
            LCD_DrawLine(i,72 + 22 + 1,i,72 + 22 + 20,GRAY); // ����  ������������
        }

        if(DD.IQspeed >= 100){//˵����ֵ���
            DD.IQspeed = 0;
            DD.IsRefresh = 0;
            DD.IsMax30102 = 0;
            changePage(DpShowSuccess,true);
        }
        return;
    }
    LCD_ShowChinese(10,2,(u8*)"���̳�ֵ���",BLACK,WHITE,12,0);
    LCD_ShowPicture(10,24,16,14,gImage_xl); // ����ͼ��
    LCD_ShowChinese(10 + 16 + 2,24,(u8*)"���ʼ��",GRAY,WHITE,12,0);
    LCD_ShowPicture(10,24 + 14 + 6,16,16,gImage_so2); // Ѫ��ͼ��
    LCD_ShowChinese(10 + 16 + 2,24 + 14 + 8,(u8*)"Ѫ�����",GRAY,WHITE,12,0);
    LCD_ShowPicture(10,24 + 14 + 6 + 16 + 10,16,16,gImage_jd); // ����ͼ��
    LCD_ShowChinese(10 + 16 + 2,72,(u8*)"���ܽ���",GRAY,WHITE,12,0);
    LCD_DrawRectangle(10,72 + 22,160 - 10,72 + 22 + 20,BLACK); // �����������
    DD.IsRefresh = 1;
    DD.IsMax30102 = 1;
    DD.LedDirection = 1;   //led�����ƶ�
}
// �������  ������������Ҫ�仯
void DFChargePower(void) {
    static u8 speedRefreshFalg=0,StopTimer=0;
    u8 speedLenth; //����������
    static char hrValue[5],so2Value[11],speeds[6];
    if (DD.IsRefresh == 1) {
        if(DD.hrValue == 0){
            LCD_ShowString(28+4*12,72,(u8*)":",GRAY,WHITE,12,0);
            LCD_ShowChinese(28+5*12,72,(u8*)"δ����缫",GRAY,WHITE,12,0);
            speedRefreshFalg=1;
            if(DD.PowerSpeed > 0){
                StopTimer++;    //������;ֹͣ��ʱ��
            }
            if(StopTimer > 30){ //����3S�� ��ֵʧ��
                StopTimer = 0; 
                changePage(DpShowFail,true);
                DD.IsRefresh = 0;
                DD.IsMax30102 = 0;
                DD.LedDirection = 2;   //led�����ƶ���Ҳ���ǳ��
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
            LCD_DrawLine(i,72 + 22 + 1,i,72 + 22 + 20,GRAY); // ����  ������������
        }

        if(DD.PowerSpeed >= 100){//˵����ֵ���
            DD.PowerSpeed = 0;
            DD.IsRefresh = 0;
            DD.IsMax30102 = 0;
            changePage(DpShowSuccess,true);
        }
        return;
    }
    LCD_ShowChinese(10,2,(u8*)"������ֵ���",BLACK,WHITE,12,0);
    LCD_ShowPicture(10,24,16,14,gImage_xl); // ����ͼ��
    LCD_ShowChinese(10 + 16 + 2,24,(u8*)"���ʼ��",GRAY,WHITE,12,0);
    LCD_ShowPicture(10,24 + 14 + 6,16,16,gImage_so2); // Ѫ��ͼ��
    LCD_ShowChinese(10 + 16 + 2,24 + 14 + 8,(u8*)"Ѫ�����",GRAY,WHITE,12,0);
    LCD_ShowPicture(10,24 + 14 + 6 + 16 + 10,16,16,gImage_jd); // ����ͼ��
    LCD_ShowChinese(10 + 16 + 2,72,(u8*)"���ܽ���",GRAY,WHITE,12,0);
    LCD_DrawRectangle(10,72 + 22,160 - 10,72 + 22 + 20,BLACK); // �����������
    DD.IsRefresh = 1;
    DD.IsMax30102 = 1;
    DD.LedDirection = 1;   //led�����ƶ�

    // LCD_ShowChinese(10,2,(u8*)"������ֵ���",BLACK,WHITE,12,0);
    // LCD_ShowPicture(10,24,16,14,gImage_xl); // ����ͼ��
    // LCD_ShowChinese(10 + 16 + 2,24,(u8*)"���ʼ��",GRAY,WHITE,12,0);
    // LCD_ShowString(28 + 4 * 12,24,(u8*)":68",GRAY,WHITE,12,0);
    // LCD_ShowPicture(10,24 + 14 + 6,16,16,gImage_so2); // Ѫ��ͼ��
    // LCD_ShowChinese(10 + 16 + 2,24 + 14 + 8,(u8*)"Ѫ�����",GRAY,WHITE,12,0);
    // LCD_ShowString(28 + 4 * 12,24 + 14 + 8,(u8*)":96.65%",GRAY,WHITE,12,0);
    // LCD_ShowPicture(10,24 + 14 + 6 + 16 + 10,16,16,gImage_jd); // ����ͼ��
    // LCD_ShowChinese(10 + 16 + 2,72,(u8*)"���ܽ���",GRAY,WHITE,12,0);
    // LCD_ShowString(28 + 4 * 12,72,(u8*)":13%",GRAY,WHITE,12,0);
    // LCD_DrawRectangle(10,72 + 22,160 - 10,72 + 22 + 20,BLACK); // �����������
    // for (u16 i = 11; i < 150; i++) {
    //     LCD_DrawLine(i,72 + 22 + 1,i,72 + 22 + 20,GRAY); // ����  ������������
    // }
}
// �ɹ�ҳ
void DFShowSuccess(void) {
    LCD_ShowChinese(10,6,(u8*)"���ܽ��",BLACK,WHITE,12,0);
    LCD_ShowPicture(65,40,30,30,gImage_success);
    LCD_ShowChinese(48,82,(u8*)"��ֵ�ɹ�",GREEN,WHITE,16,0);
}
// ʧ��ҳ
void DFShowFail(void) {
    LCD_ShowChinese(10,6,(u8*)"���ܽ��",BLACK,WHITE,12,0);
    if(DD.IQspeed > 0 || DD.PowerSpeed > 0){
        LCD_ShowPicture(65,30,30,30,gImage_fail);
        LCD_ShowChinese(48,66,(u8*)"��ֵʧ��",RED,WHITE,16,0);
        LCD_ShowChinese(20,86,(u8*)"���ڳ���ѳ�ֵ������",BLACK,WHITE,12,0);
        LCD_ShowChinese(62,86 + 12 + 4,(u8*)"���Ժ�",BLACK,WHITE,12,0);
    }else{
        LCD_ShowPicture(65,40,30,30,gImage_fail);
        LCD_ShowChinese(48,82,(u8*)"��ֵʧ��",RED,WHITE,16,0);
    }
}

// ��ʾ�����ĳ�ʼ��
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

// ����LCD
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

// ����ɨ��
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
        // ������е�ʧ�� 
        if (R_KeyState(0) || R_KeyState(1) || R_KeyState(2)) {
            changePage(DpShowFail,true);

            DD.IsRefresh = 0;
            DD.IsMax30102 = 0;
            if(DD.IQspeed > 0 || DD.PowerSpeed > 0){
                //˵���г�ֵ   ��Ҫ���
                DD.LedDirection = 2;
            }else{
                //û�� ֱ�ӽ���
                DD.LedDirection = 0;
            }
        }
        break;
    case DpShowSuccess:
    case DpShowFail:
        // �ɹ�ҳ�����ҳ��������е���ҳ 
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
    static u32 ledData = 0b11100000000000000000000000000000;  // ��ʼ����
    static u8 colour = 0;
    if(DD.LedDirection == 0 || DD.LedDirection == 3){
        return;
    }

    // ����ѡ�����;�����ɫ 4����ɫ��6����ɫ��0��͸��
    if(DD.SelectIQPower == 1){
        colour = 4;
    }else if(DD.SelectIQPower == 2){
        colour = 6;
    }else{
        colour = 0;
    }

    if (DD.LedDirection == 1) {
        // ˵���Ѿ���ֵ�ɹ���ִ�����һȦ
        if(DD.ThisDisplay == DpShowSuccess){
            RGB_Flowing(ledData,colour);
            ledData = ledData >> 1U;
            if (ledData <= 0X07) {
				ledData = 0XE0000000;
                LedOff(); //ȫ��
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
                LedOff();//ȫ��
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


// �л�ҳ��
void changePage(enum DisplayState pageName,bool isClearScreen){
    DD.PrevDisplay = DD.ThisDisplay;
    DD.ThisDisplay = pageName;
    if(isClearScreen == true){
        LCD_Fill(0,0,LCD_W,LCD_H,WHITE); // ����
    }
}

// ����ĳ�ʼ��
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

// ���������
u8 rands(void) {
    static u8 randValue;
    srand(randValue + DD.SetIQValue + DD.SetPowerValue + GetCounter()); // �����дһ������
    randValue = rand();                   // ����һ�����ֵ
    return randValue;
}