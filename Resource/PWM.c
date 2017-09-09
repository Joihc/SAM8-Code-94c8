#define _PWM_C_

#include "PWM.h"

uint8 pwm =PWM_MIN;//

void fixPWM(uint8 index)
{
}


uint4 getPWMCanTakeNullPot()
{
  return pwm>63?1:0;//设置开始检锅的频率，如果未达到则不理
}
uint4 getPWMRate()
{
  uint16 range  = 300;//getADCNumByNum(12);
  if(range>PWM8)
  {
    return 8;
  }
  else if(range>PWM7)
  {
    return 7;
  }
  else if(range>PWM6)
  {
    return 6;
  }
  else if(range>PWM5)
  {
    return 5;
  }
  else if(range>PWM4)
  {
    return 4;
  }
  else if(range>PWM3)
  {
    return 3;
  }
  else if(range>PWM2)
  {
    return 2;
  }
  else if(range>PWM1-5)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
#pragma inline=forced
uint8 Clamp(uint8 num,uint8 mix,uint8 max)
{
  if(num<mix)
  {
    return mix;
  }
  else if(num >max)
  {
    return max;
  }
  return num;
}
