#define _74HC595_C_

#include "74HC595.h"
//BFAE DHCG  0是亮
__code const uint8 LED7Code[]={
   0x05;//0   0000 0101
   0x7D;//1   0111 1101
   0x05;//3   0101 0100
   0x7D;//4   0011 0100
   0x05;//5   1001 0100
   0x7D;//6   1000 0100
   0x05;//7   0101 1101
   0x7D;//8   0000 0100
   0x05;//9   0001 0100
   0x7D;//a   0001 1100
   0x05;//b   1010 0100
   0x7D;//c   1000 0111
   0xFF;//全灭
}
/*
    C-|Q1  7   VCC|-
    H-|Q2  4    Q0|-G/SW3
    D-|Q3  H   SDI|-
SW2/E-|Q4  C   /OE|-
SW1/A-|Q5  5   SCK|-
    F-|Q6  9   LCK|-
    B-|Q7  5 /SCLR|-
     -|GND     Q7`|-

    3-|Q1  7   VCC|-
LD2/2-|Q2  4    Q0|- 
LD3/1-|Q3  H   SDI|-
LD1/4-|Q4  C   /OE|-
LED  -|Q5  5   SCK|-
     -|Q6  9   LCK|-
     -|Q7  5 /SCLR|-
     -|GND     Q7`|-

*/
void sendbyte(uchar dat)         //串行输出一字节
{    
    uint8 i; 
    for(i = 0; i < 8; i++) {
      if (dat & 0x80)  
        sda = 1; 
      else  
        sda = 0;
      scl = 0;  
      dat <<= 1; 
      scl = 1;
    }
}

void display(uint8 LED_pos,uint8 LED_num,uint4 flush) //位码 段码 时钟标志
{
    uint8 pos =0;
    uint8 num =LED7Code[LED_num];
    switch(LED_pos)
    {
    case 1:
      pos =0x08;//00001000
      num=flush?(num&0xFB):num;
      break;
    case 2:
      pos =0x04;//00000100
      num=flush?(num&0xFB):num;
      break;
    case 3:
      pos =0x02;//00000010
      break;
    case 4:
      pos =0x10;//00010000
      break;
    }
    sendbyte(pos);
    sendbyte(num);  
    rck = 0;   
    rck = 1;
}
//switch 1 2 3
uint4 keyscan()
{
  uint4 times=0;
   //sw1 0x00 
  sendbyte(0);
  sendbyte(0x20);//0010 0000
  rck = 0;   
  rck = 1;
  if(!Test_Switch)
  {
    while(times<5)
    {
      times++
    }
    if(times==5)
    {
      return 1;
    }
  }
  times=0;
   //sw2 0x00 
  sendbyte(0);
  sendbyte(0x10);//0001 0000
  rck = 0;   
  rck = 1;
  if(!Test_Switch)
  {
    while(times<5)
    {
      times++
    }
    if(times==5)
    {
      return 2;
    }
  }
  //sw3 0x00 
  sendbyte(0);
  sendbyte(0x01);//0000 0001
  rck = 0;   
  rck = 1;
  if(!Test_Switch)
  {
    while(times<5)
    {
      times++
    }
    if(times==5)
    {
      return 3;
    }
  }
}
//led
void displayLED(uint4 num)
{
  
  switch(num)
  {
  case 1:
    sendbyte(0x30);
    break;
  case 2:
    sendbyte(0x24);
    break;
  case 3:
    sendbyte(0x28);
    break;
  }
  sendbyte(0);
  rck = 0;   
  rck = 1;
}