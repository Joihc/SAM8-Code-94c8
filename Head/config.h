#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "ioS3F94C8.h"
#include "intrinsics.h"

#define nop (__no_operation())
#define di (__disable_interrupt())
#define ei (__enable_interrupt())

//****************************类型缩写******************************
typedef signed short int4;
typedef signed char int8;//8位有符号整型
typedef signed int int16;//16位有符号整型
typedef signed long int32;//32位有符号整型
typedef unsigned short uint4;
typedef unsigned char uint8;//8位无符号
typedef unsigned int uint16;//16位无符号
typedef unsigned long unit32;//32位无符号
//******************************************************************

//*****************************位域*********************************
#define Set_Bit(byte,bit) (byte|=(1<<bit))//对byte的bit位置取1
#define Clr_Bit(byte,bit) (byte&=~(1<<bit))//对byte的bit位置取0
#define Com_Bit(byte,bit) (byte^=(1<<bit))//对byte的bit位置取反
#define Test_Bit(byte,bit) (byte&(1<<bit))//对byte的bit结果
//******************************************************************


#define Screen_TM1629 // Screen_74HC164 或者 Screen_74HC595  Screen_TM1629

#define DEBUG //debug模式下不检查，只正常运行 DEBUG

#define CLOSE_WD  (BTCON_bit.WDG = 0)
#define CLEAR_WD (BTCON_bit.CNT_CLR == 1)
#define OPEN_WD (BTCON_bit.WDG = 10)

#define PIN_POPBUZ (Com_Bit(P2,3))

#define OPEN_F (Set_Bit(P2,3))
#define CLOSE_F  (Clr_Bit(P2,3))

#define FZ_ALL_TIME (60)
#endif /* _CONFIG_H_ */
