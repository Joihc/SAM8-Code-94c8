#ifndef _PWM_H_
#define _PWM_H_

#include "config.h"
#include "adc.h"

#ifndef _PWM_C_
#endif

/*   28KHZ   17 -30KHZ  0.9V-3V��
  0->0V
  1->0.9V->184.14
  2->1.2V->245.52
  3->1.5V->306.9
  4->1.8V->368.28
  5->2.1V->429.66
  6->2.4V->471.04
  7->2.7V->552.42
  8->3.0V->613.8
*/
#define PWM1 (35)
#define PWM2 (70)
#define PWM3 (110)
#define PWM4 (140)
#define PWM5 (170)
#define PWM6 (200)
#define PWM7 (230)
#define PWM8 (250)

#define PWM_MIN (60) //30KHZ
#define PWM_POT (65)
#define PWM_MAX (118) //16.66KHZ  236

#define PWM_RETURN (90)//�����ͻص�Ƶ�� 20KHZ
#define RETURN_PWM (30)//�ص�ADֵ
//0.5 -1.2
void setTBPWM();
void fixPWM(uint8 index);
uint4 getPWMRate();
uint8 Clamp(uint8 num,uint8 mix,uint8 max);

//void testIGBT();
uint4 getPWMCanTakeNullPot();
#endif /* _PWM_H_ */
