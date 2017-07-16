/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : AdsInit.h
  �� �� ��   : ����
  ��    ��   : ³��/l60609
  ��������   : 2011��12��7��
  ����޸�   :
  ��������   : AdsInit.c ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2011��12��7��
    ��    ��   : ³��/l60609
    �޸�����   : �����ļ�

******************************************************************************/

#ifndef __ADSINIT_H__
#define __ADSINIT_H__

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "AdsUpLink.h"
#include "AdsDownLink.h"

/* Added by f00179208 for CCPU RESET, 2013-04-15, Begin */
#include "AcpuReset.h"
/* Added by f00179208 for CCPU RESET, 2013-04-15, End */

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 �궨��
*****************************************************************************/
/* ADS�����Դ��������ջ��С */
#define  ADS_DL_SELF_TASK_STACK_SIZE    (5120)

/* ADS�������ȼ� */
#define  ADS_UL_TASK_PRIORITY           (82)


/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/


/*****************************************************************************
  4 ȫ�ֱ�������
*****************************************************************************/


/*****************************************************************************
  5 ��Ϣͷ����
*****************************************************************************/


/*****************************************************************************
  6 ��Ϣ����
*****************************************************************************/


/*****************************************************************************
  7 STRUCT����
*****************************************************************************/


/*****************************************************************************
  8 UNION����
*****************************************************************************/


/*****************************************************************************
  9 OTHERS����
*****************************************************************************/


/*****************************************************************************
  10 ��������
*****************************************************************************/



#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif

VOS_UINT32 ADS_UL_PidInit(enum VOS_INIT_PHASE_DEFINE enPhase);

VOS_UINT32 ADS_DL_PidInit(enum VOS_INIT_PHASE_DEFINE enPhase);

/* Added by f00179208 for CCPU RESET, 2013-04-15, Begin */
VOS_INT ADS_UL_CCpuResetCallback(
    DRV_RESET_CB_MOMENT_E               enParam,
    VOS_INT                             iUserData
);
VOS_INT ADS_DL_CCpuResetCallback(
    DRV_RESET_CB_MOMENT_E               enParam,
    VOS_INT                             iUserData
);
/* Added by f00179208 for CCPU RESET, 2013-04-15, End */

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of AdsInit.h */