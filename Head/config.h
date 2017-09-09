#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "ioS3F94C8.h"
#include "intrinsics.h"

#define nop (__no_operation())
#define di (__disable_interrupt())
#define ei (__enable_interrupt())

//****************************������д******************************
typedef signed short int4;
typedef signed char int8;//8λ�з�������
typedef signed int int16;//16λ�з�������
typedef signed long int32;//32λ�з�������
typedef unsigned short uint4;
typedef unsigned char uint8;//8λ�޷���
typedef unsigned int uint16;//16λ�޷���
typedef unsigned long unit32;//32λ�޷���
//******************************************************************

//*****************************λ��*********************************
#define Set_Bit(byte,bit) (byte|=(1<<bit))//��byte��bitλ��ȡ1
#define Clr_Bit(byte,bit) (byte&=~(1<<bit))//��byte��bitλ��ȡ0
#define Com_Bit(byte,bit) (byte^=(1<<bit))//��byte��bitλ��ȡ��
#define Test_Bit(byte,bit) (byte&(1<<bit))//��byte��bit���
//******************************************************************


#define Screen_TM1629 // Screen_74HC164 ���� Screen_74HC595  Screen_TM1629

#define DEBUG //debugģʽ�²���飬ֻ�������� DEBUG

#define CLOSE_WD  (BTCON_bit.WDG = 0)
#define CLEAR_WD (BTCON_bit.CNT_CLR == 1)
#define OPEN_WD (BTCON_bit.WDG = 10)

#define PIN_POPBUZ (Com_Bit(P2,3))

#define OPEN_F (Set_Bit(P2,3))
#define CLOSE_F  (Clr_Bit(P2,3))

#define FZ_ALL_TIME (60)
#endif /* _CONFIG_H_ */
