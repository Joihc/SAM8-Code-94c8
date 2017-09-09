#ifndef _74HC595_H_
#define _74HC595_H_

#include "config.h"
#include "time.h"

#ifndef _74HC595_C_

#endif

enum LED_STATE
{
  OFF,
  ON,
  FLUSH
};


//sda
//scl
//rck

//左-右 卡槽上 P2.2 P2.1 P2.5 P2.4 GND +5V
#define Test_Switch (Test_Bit(P2,2))

#define COM_1_0 (Clr_Bit(P2,2))
#define COM_COM_1 (Com_Bit(P2,2))

//数字显示开关
#define COM_2_1 (Set_Bit(P2,1))
#define COM_2_0 (Clr_Bit(P2,1))

#define DAT_1 (Set_Bit(P2,5))
#define DAT_0 (Clr_Bit(P2,5))

#define CLK_1 (Set_Bit(P2,4))
#define CLK_0 (Clr_Bit(P2,4))



#endif /* _74HC164_H_ */
