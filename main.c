//*****************************
//  author：  hg
//  date:     2017/4/9
//  mcu:      s3f94c8
//  project:  电磁炉  8MHZ
//*****************************
#define _MAIN_C_


#include "main.h"
#include "adc.h"
#include "PWM.h"

#ifdef Screen_74HC164
#include "74HC164.h"
#elif defined  Screen_74HC595
#include "74HC595.h"
#elif defined  Screen_TM1629
#include "TM1629.h"
#endif
//Must be initialized to 00H;Must be initialized to 00H;3.9V LVR;000000 00 External crystal ceramic oscillator
//lvr使能 P1.2自动被指成输出口；P1.0,P1.1需要设置成输出以降低功耗
__root const volatile uint8 Smart_Code[]@0x003C={0x00, 0x00, 0xB0, 0x00};
__code const uint8 POWER_RATE[] =
{
    10,20,30,40,50,60,70,80,90,100
};
uint8 rangeNow =0;
uint16 time_1s =0;
uint16 BUZZ_open =0;//0关闭，非1开启 
uint8 fanTime =0;
uint8 temperatureCheckTime =60;


#pragma inline=forced							   //--initiation
void sysInit()
{
	ADCON = 0xF8; //o/16
	BTCON = 0x00;
	CLKCON = 0x18;//00/16 01/8 10/2 11/1

        //系统PWM初始化
        
        //系统初始化TO
        T0DATA = 0xC8;//0.000001 *200=0.2mS
        T0CON = 0x82 ;//10 00 0 0 1 0   0/8 =1M = 1us
}

#pragma inline=forced
void ioInit()
{
	P0CONH = 0xDF;//11(ADC7) 01(PWM) 11(ADC5) 11(ADC4)
        P0CONL = 0xF3;//11(ADC3) 11(ADC2) 00(INT1) 11(ADC0)
        P0PND =0x00;  //0000 P0.1(0禁止 0清除) P0.0(0 0)  
        P1CON =0xCA;  //开漏输出
        
        P2CONH =0x3F; //0 011(ADC8) 11(DAT) 11(CLK)  
        P2CONL =0x7F; //01（蜂鸣器） 11（com1) 11(com2) 10(匹配输出，控制位）       
}
#pragma inline=forced
void defaultValue()
{

}
int main()
{
	di;
	//系统初始化 IO初始化
	sysInit();
	ioInit();

#ifdef Screen_74HC164
        init_74HC164();
#elif defined Screen_74HC595
        
#elif defined Screen_TM1629
        init_TM1629();
#endif

	defaultValue();

	ei;
        buzz(6);
        delay(6000);
        //while((BTCNT && 0x80) != 0);//等待晶振稳定
        //启用TO定时


	while (1)
	{
          SwitchSet();  
          ViewSet(rangeNow);
	}
}
#pragma inline=forced
void SwitchSet()
{
	uint4 rangeNext = getSwitchByAnum();
	if (rangeNext != rangeNow && rangeNext != 9)
	{
          rangeNow=rangeNext;
          buzz(1);
	}
}
#ifdef Screen_74HC164
void ViewSet(uint8 ShowNum)
{
	setNum_74HC164(ShowNum);
	whileUpdate_74HC164();
}
#elif defined Screen_74HC595
void ViewSet(uint8 ShowNum)
{
        whileUpdate_74HC595();
}
#elif defined Screen_TM1629
void ViewSet(uint8 ShowNum)
{
        set_TM1629_Down(getADCNum(3), 1); 
        set_TM1629_LeftNum(rangeNow);
        whileUpdate_TM1629();
}
#endif
//中断
#pragma vector=0x00
__interrupt void int_94c8()
{
	if (T0CON & 0x01)//timer 0(Timer 0 Match)
	{
		T0CON &= ~0x01;
		T0_Interupt();
	}
	else if (PWMCON & 0x01)//PWM Overflow
	{
		PWMCON &= ~0x01;
	}
	else if (P0PND & 0x01)//P0.0 External Interrupt
	{
		P0PND &= ~0x01;
	}
	else if (P0PND & 0x02)//P0.1 External Interrupt
	{
		P0PND &= ~0x02;
                NULLPOTInterupt();
	}
}
#pragma inline=forced
//A定时器
void T0_Interupt()
{
	CLEAR_WD;
	time_1s++;
        updata_buzz();
	if (time_1s >= 4000)//1s
	{
          time_1s=0;
          if(fanTime >= 1 && fanTime <FZ_ALL_TIME)
          {
            fanTime++;
          }
          if(fanTime <FZ_ALL_TIME)
          {
            OPEN_F;
          }
          else
          {
            CLOSE_F;
          }
#ifdef Screen_74HC164
	  interuptUpdate_74HC164();
#elif defined Screen_74HC595
          interuptUpdate_TM1629();
#endif
          //if(TEST_PWM && temperatureCheckTime)//只在开通状态检查温度运转
          //{
          //     temperatureCheckTime--;//开路延时倒计时
          //}
        }
	CLEAR_WD;
}
#pragma inline=forced
void NULLPOTInterupt()
{
  //无锅计数
}
