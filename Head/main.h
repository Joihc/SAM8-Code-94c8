#ifndef _MAIN_H_
#define _MAIN_H_

#include "config.h"

#ifndef _MAIN_C_

#endif

void sysInit();
void ioInit();
void defaultValue();
void DetectNullPot();//�޹����
void DetectCoilHot();//���̳���
void DetectCoilCut();//����̽ͷ��·
void DetectIGBTHot_1();//IGBT����
void DetectIGBTCut_1();//IGBT̽ͷ��·
void DetectIGBTHot_2();//IGBT����
void DetectIGBTCut_2();//IGBT̽ͷ��·
void DetectVLow();//��ѹ���
void DetectVHight();//��ѹ���
void DetectVCut();//ȱ����
void DetectSwitchCut();//��λ���ؿ�·
void DetectUnderPotCut();//����̽ͷ��·
void DetectUnderPotHot();//���׳���
void DetectIgbtError();//IGBT��������
void DetectTransformer();//���������װ��
void DetectTransformerCut();//���̶��˻����������������
void SwitchSet();
void ViewSet(uint8 ShowNum);

 void T0_Interupt();
 void NULLPOTInterupt();
__interrupt void int_94c8();

#endif
