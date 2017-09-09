#define _TIME_C_

#include "time.h"
/*
  8MHZ 1us  6*X+5us   太多了就要另外算 只能大概
*/
uint16 buzz_time =0;
void delay(volatile uint16 ms)
{
    ms=ms*6+5;//140
    do{
      asm("nop"); ms--;
    }while(ms!=0);
}
void delayus(volatile uint8 us)
{

   do{
     nop; us--;
   }while(us!=0);
}

void buzz(uint8 time)
{
  uint16 time_change = time*2000;
  buzz_time=(time_change>buzz_time?time_change:buzz_time);
}
void updata_buzz()//0.00025更新一次
{
  if(buzz_time>0)
  {
    buzz_time--;
  }
  if(buzz_time>0)
  {
    PIN_POPBUZ;
  }
}
