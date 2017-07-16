#ifndef __TAF_COMMON_H__
#define __TAF_COMMON_H__

/*============================================================================*/

/******************************************************************************/
/* Copyright (c) ,1988-2001,Huawei Tech. Co.,Ltd                              */
/* File name     :Taf_Common.h                                              */
/* Author        :zzy                                                         */
/* Description   :TAFM�ṩ��TAF������ģ��Ĺ���ͷ�ļ�                         */
/* Others        :                                                            */
/* Function List :                                                            */
/* History       :                                                            */
/*               :2005-04-13 ����                                             */
/*
 1.��    ��   : 2007��01��08��
    ��    ��   : h44270
    �޸�����   : ���ⵥ��:A32D07108��������ý����ռ��Ƶ�豸���������쳣,����ADMģ��
 2.��    ��   : 2007��01��18��
    ��    ��   : h59254
    �޸�����   : ���ⵥ��:A32D6632
 3.��    ��   : 2007��03��14��
   ��    ��   : d49431
   �޸�����   : ���ⵥ��:A32D06085
 4.��    ��   : 2007��04��30��
   ��    ��   : l65478
   �޸�����   : ���ⵥ��:A32D09194
 5.��    ��   : 2007��05��09��
   ��    ��   : �޽� id:60022475
   �޸�����   : ���ⵥ��:A32D10838
 6.��    ��   : 2007��05��11��
   ��    ��   : h44270
   �޸�����   : ���ⵥ�ţ�A32D10878,����LOG����
 7.��    ��   : 2007��08��28��
   ��    ��   : d49431
   �޸�����   : ���ⵥA32D12736��ȥ�������ж�������ؽӿڵĵ���
 8.��    ��   : 2008��8��25��
   ��    ��   : ��ӳ�� 62575
   �޸�����   : ���ⵥ�� AT2D05096,AT��ѡ���TAF�·�������ģ��ʱ��������д����ȷ
 9.��    ��   : 2011��04��23��
   ��    ��   : L00171473
   �޸�����   : for V7R1 porting, ������ض����WARNING
*/
/******************************************************************************/

/******************************************************************************/
#include "vos.h"
#include "PsTypeDef.h"
#include "PsCommonDef.h"
#include "v_id.h"
#include "product_config.h"
#include "TafClientApi.h"
#include "om.h"




/******************************************************************************/

/******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/*========================================================*/

/* ��־������ҵ��ı��뿪�أ����ⵥA32D12736 */
#define  TAF_FEATURE_NO_VOICE_SERVICE
/*TAFM�ϱ��ṹ��optionλ���ֽ��ܸ�����
��ģ����Դӽṹ��ʼ��ַmemset TAF_EVT_OP_LEN���ֽڴﵽ����ֵĿ��*/
#define   TAF_EVT_OP_LEN   4

/*----------TAFM�����ӿ�----------*/
/*TAF��ģ��ID*/
#ifndef SUBMOD_NULL
#define  SUBMOD_NULL 0
#endif
#define  TAF_CCA     1
#define  TAF_APS     2
#define  TAF_SMA     3
#define  TAF_SSA     4
#define  TAF_MMA     5
#define   TAF_ALL_SUBMODULE   0xFF    /*������ģ��*/

/*��ʱ��V200Ҫɾ��*/
#define   TAF_TAFM             0
#define   TAF_SPEECH           1
#define   TAF_STATUS           2
#define   TAF_MAX_SPEECH_TI    14


/*��ӡ��������ӳ�䵽OM����ĺ�*/
#define    INFO_PRINT      PS_PRINT_INFO
#define    NORMAL_PRINT    PS_PRINT_NORMAL
#define    WARNING_PRINT   PS_PRINT_WARNING
#define    ERROR_PRINT     PS_PRINT_ERROR



#define TAF_PRINT(  Module,  PrintLevel,  Str)     \
           PS_LOG(Module, 0, PrintLevel, Str)

#define TAFM_PRINT(Str)     \
           PS_LOG(TAF_TAFM, 0, ERROR_PRINT, Str)

#define TAFM_PRINT1(Str, Para1)     \
           PS_LOG1(TAF_TAFM, 0, ERROR_PRINT, Str, Para1)

#define TAFM_PRINT2(Str, Para1, Para2)    \
           PS_LOG2(TAF_TAFM, 0, ERROR_PRINT, Str, Para1, Para2)





/*�����ӿ�*/
/*�������ý���ϱ�*/
VOS_VOID Taf_ParaSetResult( VOS_UINT16           ClientId,
                        VOS_UINT8                  OpId,
                        TAF_PARA_SET_RESULT     Result,
                            TAF_PARA_TYPE     QueryPara,
                        VOS_VOID                    *pPara );


/*******************************************************************************/

#define SMA_INFO_LOG(String)            PS_LOG(WUEPS_PID_TAF,  TAF_SMA, PS_PRINT_INFO,    String)
#define SMA_NORM_LOG(String)            PS_LOG(WUEPS_PID_TAF,  TAF_SMA, PS_PRINT_NORMAL,  String)
#define SMA_WARN_LOG(String)            PS_LOG(WUEPS_PID_TAF,  TAF_SMA, PS_PRINT_WARNING, String)
#define SMA_ERR_LOG(String)             PS_LOG(WUEPS_PID_TAF,  TAF_SMA, PS_PRINT_ERROR,   String)
#define SMA_LOG1(String, Para1)         PS_LOG1(WUEPS_PID_TAF, TAF_SMA, PS_PRINT_INFO,    String, Para1)
#define SMA_LOG2(String, Para1, Para2)  PS_LOG2(WUEPS_PID_TAF, TAF_SMA, PS_PRINT_NORMAL,  String, Para1, Para2)

/*�з���ֵ����Ϣ�����궨��*/
#define PS_ALLOC_MSG_RTN_FAIL(pMsg, ulPid , ulLen) \
    if(VOS_NULL_PTR == (pMsg = (VOS_VOID *)PS_ALLOC_MSG((ulPid),(ulLen) - VOS_MSG_HEAD_LENGTH))) \
    {\
        PS_LOG1((ulPid), PS_SUBMOD_NULL, PS_PRINT_ERROR," VOS_AllocMsg ERR! len:",(VOS_INT32)(ulLen));\
        return  VOS_ERR;\
    }

/*δ������Ϣ�ṹ,������Ϣ�ڴ�,������ڴ泤�Ȳ�����Ϣ��ͷ����*/
#define PS_ALLOC_MSG_RTN_FAIL_WITHOUT_HEADER_LEN(pMsg, ulPid , ulLen) \
    if(VOS_NULL_PTR == (pMsg = (VOS_VOID *)PS_ALLOC_MSG((ulPid),(ulLen)))) \
    {\
        PS_LOG1((ulPid), PS_SUBMOD_NULL, PS_PRINT_ERROR," VOS_AllocMsg ERR! len:",(VOS_INT32)(ulLen));\
        return  VOS_ERR;\
    }

/*δ������Ϣ�ṹ,������Ϣ�ڴ�,������ڴ泤�Ȳ�����Ϣ��ͷ����*/
#define PS_ALLOC_MSG_WITHOUT_HEADER_LEN(pMsg, ulPid , ulLen) \
    if(VOS_NULL_PTR == (pMsg = (VOS_VOID *)PS_ALLOC_MSG((ulPid),(ulLen)))) \
    {\
        PS_LOG1((ulPid), PS_SUBMOD_NULL, PS_PRINT_ERROR," VOS_AllocMsg ERR! len:",(VOS_INT32)(ulLen));\
        return;\
    }

/*���˳���ǰ��������Ϣ�����궨��*/
#define PS_ALLOC_MSG_UNRTN(pMsg, ulPid , ulLen) \
    if(VOS_NULL_PTR == (pMsg = (VOS_VOID *)PS_ALLOC_MSG((ulPid),(ulLen) - VOS_MSG_HEAD_LENGTH))) \
    {\
        PS_LOG1((ulPid), PS_SUBMOD_NULL, PS_PRINT_ERROR," VOS_AllocMsg ERR! len:",(VOS_INT32)(ulLen));\
    }

/*���˳���ǰ������δ������Ϣ�ṹ,������Ϣ�ڴ�,������ڴ泤�Ȳ�����Ϣ��ͷ����*/
#define PS_ALLOC_MSG_UNRTN_WITHOUT_HEADER_LEN(pMsg, ulPid , ulLen) \
    if(VOS_NULL_PTR == (pMsg = (VOS_VOID *)PS_ALLOC_MSG((ulPid),(ulLen)))) \
    {\
        PS_LOG1((ulPid), PS_SUBMOD_NULL, PS_PRINT_ERROR," VOS_AllocMsg ERR! len:",(VOS_INT32)(ulLen));\
    }

/*��Ϣ�ͷź궨��*/
#define PS_FREEMSG(ulPID,pMsg)\
        VOS_FreeMsg((ulPID), (pMsg));

/*�з���ֵ�ڴ�����궨��*/
#define PS_MEM_ALLOC_RTN_FAIL(pMem, ulPid , ulLen) \
    if(VOS_NULL_PTR == (pMem = (VOS_VOID *)VOS_MemAlloc((ulPid), DYNAMIC_MEM_PT, (ulLen)))) \
    {\
        PS_LOG1((ulPid), PS_SUBMOD_NULL, PS_PRINT_ERROR," VOS_MemAlloc ERR! len:",(VOS_INT32)(ulLen));\
        return VOS_ERR;\
    }

/*���˳���ǰ�������ڴ�����궨��*/
#define PS_MEM_ALLOC_UNRTN(pMem, ulPid , ulLen) \
    if(VOS_NULL_PTR == (pMem = (VOS_VOID *)VOS_MemAlloc((ulPid), DYNAMIC_MEM_PT, (ulLen)))) \
    {\
        PS_LOG1((ulPid), PS_SUBMOD_NULL, PS_PRINT_ERROR," VOS_MemAlloc ERR! len:",(VOS_INT32)(ulLen));\
    }

/* Added by z00214637 for DSDA GUNAS C CORE, 2012-12-29, begin */
#define TAF_COMM_BUILD_USIM_GET_FILE_INFO(pstGetfileInfo, enAppTypePara, usEfIdPara, ucRecordNumPara) \
{ \
    (pstGetfileInfo)->usEfId       = usEfIdPara; \
    (pstGetfileInfo)->ucRecordNum  = ucRecordNumPara; \
    (pstGetfileInfo)->enAppType    = enAppTypePara; \
    (pstGetfileInfo)->ucRsv        = 0; \
}

#define TAF_COMM_BUILD_USIM_SET_FILE_INFO(pstSetfileInfo, enAppTypePara, usEfIdPara, ucRecordNumPara, ulEfLenPara, pucEfPara) \
{ \
    (pstSetfileInfo)->usEfId       = usEfIdPara; \
    (pstSetfileInfo)->ucRecordNum  = ucRecordNumPara; \
    (pstSetfileInfo)->enAppType    = enAppTypePara; \
    (pstSetfileInfo)->ucRsv        = 0; \
    (pstSetfileInfo)->ulEfLen      = ulEfLenPara; \
    (pstSetfileInfo)->pucEfContent = pucEfPara; \
}
/* Added by z00214637 for DSDA GUNAS C CORE, 2012-12-29, end */

/*========================================================*/
#ifdef __cplusplus
}
#endif
/******************************************************************************/

/*============================================================================*/
#endif          /* __TAF_COMMON_H__ */
