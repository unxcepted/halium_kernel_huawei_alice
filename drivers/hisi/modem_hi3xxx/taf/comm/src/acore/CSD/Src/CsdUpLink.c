/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : CsdUpLink.c
  �� �� ��   : ����
  ��    ��   : w00199382
  ��������   : 2011��12��6��
  ����޸�   :
  ��������   : 2011��12��6��
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2011��12��6��
    ��    ��   : w00199382
    �޸�����   : �����ļ�

******************************************************************************/

/*****************************************************************************
  1 ͷ�ļ�����
*****************************************************************************/
#include "CsdUpLink.h"
#include "CsdDebug.h"
#include "PsLib.h"

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif



/*****************************************************************************
    Э��ջ��ӡ��㷽ʽ�µ�.C�ļ��궨��
*****************************************************************************/
#define    THIS_FILE_ID                 PS_FILE_ID_CSD_UP_LINK_C

#if(FEATURE_ON == FEATURE_CSD)

/*****************************************************************************
  2 ȫ�ֱ�������
*****************************************************************************/

/*****************************************************************************
  3 ����ʵ��
*****************************************************************************/

/*****************************************************************************
 �� �� ��  : CSD_UL_SendData
 ��������  : �ṩ��USB_MODEM�����������ݵĽӿ�At_UsbModemDataInd
 �������  : IMM_ZC_STRU *pstULData
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��12��14��
    ��    ��   : w00199382
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID CSD_UL_SendData(IMM_ZC_STRU *pstULData)
{
    /*��μ��*/
    if (VOS_NULL_PTR == pstULData)
    {
        CSD_ERROR_LOG(ACPU_PID_CSD, "CSD_UL_SendData:: pstULData Is Null");

        return;
    }

    /*���ݵ�ַ�Ϸ��Լ��*/
    if (VOS_NULL_PTR == pstULData->data)
    {
        CSD_ERROR_LOG(ACPU_PID_CSD, "CSD_UL_SendData:: pstULData->data Is Null");

        return;
    }

    /*���ݳ��ȼ��*/
    if (0 == pstULData->len)
    {
        CSD_ERROR_LOG(ACPU_PID_CSD, "CSD_UL_SendData:: pstULData->len Is Null");

        return;
    }

    CSD_DBG_UL_RECV_PKT_NUM(1);

    /*�������*/
    CSD_UL_InsertQueue(pstULData);

}
/*****************************************************************************
 �� �� ��  : CSD_UL_InsertQueue
 ��������  : �������ݽڵ���Ӻ���
 �������  : IMM_ZC_STRU * pstULData
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��12��8��
    ��    ��   : w00199382
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_UINT32 CSD_UL_InsertQueue(IMM_ZC_STRU *pstULData)
{

    IMM_ZC_HEAD_STRU                   *pstULQueue;
    VOS_UINT32                          ulInQueueRst;
    VOS_SEM                             hULDataSem = VOS_NULL_PTR;

    hULDataSem       = CSD_GetUpLinkDataSem();

    pstULQueue       = CSD_UL_GetQueue();

    /*�������δ�����򷵻ش����ͷ������ڴ�*/
    if (VOS_NULL_PTR == pstULQueue)
    {
        IMM_ZcFree(pstULData);
        CSD_DBG_UL_ENQUE_FAIL_NUM(1);
        CSD_ERROR_LOG(ACPU_PID_CSD, "CSD_UL_InsertQueue:: ULQueue Is Null");

        return VOS_ERR;
    }

    /*�����뻺����У��˴���Ҫ����������Ϊ�˷�ֹ�ڷ��ʻ������ʱ���Դ�������Ҳ��
    ����*/
    VOS_TaskLock();

    ulInQueueRst     = CSD_UL_InsertQueueTail(pstULQueue,pstULData);

    VOS_TaskUnlock();

    if (VOS_ERR == ulInQueueRst)
    {
        IMM_ZcFree(pstULData);
        CSD_ERROR_LOG(ACPU_PID_CSD, "CSD_UL_InsertQueue:: ULQueue Is Null");

        return VOS_ERR;
    }

    /*�����뻺����гɹ��ͷ��ź���*/
    VOS_SmV(hULDataSem);

    CSD_DBG_UL_SAVE_BUFF_PKT_NUM(1);

    CSD_NORMAL_LOG(ACPU_PID_CSD,"CSD_UL_InsertQueue::Insert ULQueue Done!");

    return VOS_OK;

}

/*****************************************************************************
 �� �� ��  : CSD_InitUlQueue
 ��������  : ��ʼ�����л������
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��12��7��
    ��    ��   : w00199382
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_UINT32 CSD_UL_InitQueue(VOS_VOID)
{

    IMM_ZC_HEAD_STRU                    *pstULQueue;

    pstULQueue     = CSD_UL_GetQueue();

    /*����������У�����Ѵ�����ֱ�ӷ���*/
    if (VOS_NULL_PTR ==  pstULQueue)
    {
        CSD_WARNING_LOG(ACPU_PID_CSD,
                        "CSD_UL_InitQueue:: ULQueue Is Null Need Alloc Mem !");

        /*����ͷ�ڵ��ڴ�*/
        pstULQueue = (IMM_ZC_HEAD_STRU *)PS_MEM_ALLOC(ACPU_PID_CSD, sizeof(IMM_ZC_HEAD_STRU));

        CSD_UL_SetQueue(pstULQueue);

        /*���ڳ�ʼ����������ָ������ж����Դ˴���Ҫ��ָ������ж�*/
        if (VOS_NULL_PTR == pstULQueue)
        {
            CSD_ERROR_LOG(ACPU_PID_CSD, "CSD_UL_InitQueue:: PS_MEM_ALLOC Fail");
            return VOS_ERR;
        }

        /*��ʼ������*/
        IMM_ZcQueueHeadInit(pstULQueue);

    }

    CSD_NORMAL_LOG3(ACPU_PID_CSD,
                   "CSD_UL_InitQueue:: Queue len is %d, Pre is 0x%x, Next is 0x%x",
                   pstULQueue->qlen,
                   pstULQueue->next,
                   pstULQueue->prev);

    /*lint -e429*/
    return VOS_OK;
    /*lint +e429*/
}
/*****************************************************************************
 �� �� ��  : CSD_UL_BuildDiccInsertData
 ��������  : ���÷��͵�DICC������
 �������  : IMM_ZC_HEAD_STRU      *pstUlQueue,
             CSD_UL_DATA_STRU      *pstULData
 �������  : *pstULData
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��12��16��
    ��    ��   : w00199382
    �޸�����   : �����ɺ���
  2.��    ��   : 2012��05��21��
    ��    ��   : f00179208
    �޸�����   : ���ⵥ��:DTS2012052101051,C�˹�����������Ҫ������ʵ��ַת��
*****************************************************************************/
VOS_UINT32 CSD_UL_BuildDiccInsertData(
    IMM_ZC_HEAD_STRU                   *pstUlQueue,
    CSD_CST_DATA_REQ_STRU              *pstULData,
    DICC_INSERT_DSCP_BLK_STRU          *pstDiccInsertData
)
{
    IMM_ZC_STRU                        *pstULImmZcData;
    IMM_MEM_STRU                       *pstULImmData;

    /*��ȡ��һ������*/
    pstULImmZcData                      = CSD_UL_GetQueueFrontNode(pstUlQueue);

    if (VOS_NULL_PTR == pstULImmZcData)
    {
        CSD_DBG_UL_QUENULL_NUM(1);
        CSD_ERROR_LOG(ACPU_PID_CSD, "CSD_UL_ConfigDataToDICC pstULNode Is Null!");

        return VOS_ERR;
    }

    /*IMM_ZcMapToImmMem��ΪIMMͷ*/
    pstULImmData                        = IMM_ZcMapToImmMem(pstULImmZcData);

    if (VOS_NULL_PTR == pstULImmData)
    {
        /*�ͷŽڵ��ڴ�*/
        IMM_ZcFree(pstULImmZcData);

        CSD_DBG_UL_ZCTOIMM_FAIL_NUM(1);

        CSD_ERROR_LOG(ACPU_PID_CSD, "CSD_UL_ConfigDataToDICC pstULImmData Is Null!");

        return VOS_ERR;
    }

    /*���ַת��Ϊʵ��ַ*/
    /* Modified by f00179208 for DTS2012052101051, 2012-05-21 Begin */
    pstULData->pucData                  = (VOS_UINT8 *)TTF_VIRT_TO_PHY((VOS_VOID *)(pstULImmZcData->data));
    /* Modified by f00179208 for DTS2012052101051, 2012-05-21 End */

    pstULData->pGarbage                 = (VOS_VOID *)pstULImmData;
    pstULData->usLen                    = (VOS_UINT16)pstULImmZcData->len;

    /*���ò���ͨ���ڵ�����*/
    pstDiccInsertData->enAutoTrigTx     = PS_FALSE;
    pstDiccInsertData->ucDataLen        = DICC_INFO_BLOCK_MAX_LEN;
    pstDiccInsertData->pucUserData      = (VOS_UINT8 *)(pstULData);

    /*�ͷŽڵ��ڴ�*/
    IMM_ZcHeadFree(pstULImmZcData);

    CSD_NORMAL_LOG(ACPU_PID_CSD,"CSD_UL_ConfigDataToDICC  Done!");

    return VOS_OK;
}
/*****************************************************************************
 �� �� ��  : CSD_UL_SendDataToDICC
 ��������  : ��������ȡ���� �����͵�DICC
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : CSD_UL_SEND_DATA_STATE_ENUM_UINT16
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��12��8��
    ��    ��   : w00199382
    �޸�����   : �����ɺ���
  2.��    ��   : 2012��05��24��
    ��    ��   : f00179208
    �޸�����   : DTS2012052405689,������һ�η������ݸ������������50��
*****************************************************************************/
CSD_UL_SEND_DATA_STATE_ENUM_UINT16 CSD_UL_SendDataToDICC(VOS_VOID)
{
    VOS_UINT32                          ulCnt;
    VOS_UINT32                          ulRslt;
    VOS_UINT32                          ulFreeSpaceCnt;
    VOS_UINT32                          ulLinkCnt;
    IMM_ZC_HEAD_STRU                   *pstULQueue;
    CSD_CST_DATA_REQ_STRU               stULData;
    DICC_INSERT_DSCP_BLK_STRU           stDiccInsertData;
    IMM_MEM_STRU                       *pstULImmData;

    /*��ȡ���ж���*/
    pstULQueue      = CSD_UL_GetQueue();

    /*��ȡDICC���ͽڵ���Ŀ*/
    ulFreeSpaceCnt  = DICC_GetChannelFreeSpaceCnt(ACPU_PID_CSD,
                                                  DICC_CHAN_ID_UL_CSD_DATA_CHAN,
                                                  DICC_CPU_ID_ACPU);

    if (DICC_INVALID_VALUE == ulFreeSpaceCnt)
    {
       CSD_ERROR_LOG(ACPU_PID_CSD,
                     "CSD_UL_SendDataToDICC:: DICC_GetChannelFreeSpaceCnt Fail");

       return CSD_UL_SEND_DATA_NOT_CONTINUE;
    }

    /*���������������*/
    VOS_TaskLock();

    /*��ȡ����ڵ���*/
    ulLinkCnt                           = IMM_ZcQueueLen(pstULQueue);

    if (0 == ulLinkCnt )
    {
        CSD_WARNING_LOG1(ACPU_PID_CSD,
                        "CSD_UL_SendDataToDICC:: ulLinkCnt is Null",
                        ulLinkCnt);

        VOS_TaskUnlock();

        return CSD_UL_SEND_DATA_NOT_CONTINUE;
    }

    ulCnt                               = PS_MIN(ulLinkCnt, ulFreeSpaceCnt);

    /* Added by f00179208 for DTS2012052405689, 2012-05-24 Begin */
    /* CST�Ļ���BUFFERĿǰ������8K������50�����ݴ��2.5K��CST�����ص�����������3K */
    /* ��CST�����غ󣬵�ֹͣ��������0.5�����ʱ����ʱ�����д��������ݻ�����CSD */
    /* ������DICC����С����������͵ĸ����Ƚϣ�ȡ������С�ķ��� */
    ulCnt                               = PS_MIN(ulCnt, CSD_UL_MAX_SEND_CNT);
    /* Added by f00179208 for DTS2012052405689, 2012-05-24 End */

    while (0 < ulCnt)
    {
        /*������������*/
        ulRslt = CSD_UL_BuildDiccInsertData(pstULQueue,
                                            &stULData,
                                            &stDiccInsertData);
        if (VOS_OK != ulRslt)
        {
            CSD_ERROR_LOG(ACPU_PID_CSD,
                         "CSD_UL_SendDataToDICC:: CSD_UL_BuildDiccInsertData Fail");

            /* Added by f00179208 for DTS2012052405689, 2012-05-24 Begin */
            VOS_TaskUnlock();
            /* Added by f00179208 for DTS2012052405689, 2012-05-24 End */

            return CSD_UL_SEND_DATA_NOT_CONTINUE;
        }

        /*DICC��������ͨ�� */
        ulRslt = DICC_InsertChannelData(ACPU_PID_CSD,
                                        DICC_CHAN_ID_UL_CSD_DATA_CHAN,
                                        &stDiccInsertData,
                                        DICC_CPU_ID_ACPU);
        if ( DICC_OK != ulRslt )
        {
            /*��Ҫ�ͷ�IMM�ڴ�*/
            pstULImmData                = (IMM_MEM_STRU *)stULData.pGarbage;
            IMM_MemFree(pstULImmData);

            CSD_DBG_UL_INSERT_FAIL_NUM(1);

            CSD_ERROR_LOG1(ACPU_PID_CSD,
                          "CSD_UL_SendDataToDICC:: DICC_InsertChannelData Fail",
                          ulRslt);
            break;
        }

        ulCnt--;

        CSD_NORMAL_LOG1(ACPU_PID_CSD,
                        "CSD_UL_SendDataToDICC:: ulCnt DEC",
                        ulCnt);
    }

    /*���������ɣ���������*/
    VOS_TaskUnlock();

    /*�����ж�*/
    ulRslt = DICC_TriggerChanDataTx(ACPU_PID_CSD,
                                    DICC_CHAN_ID_UL_CSD_DATA_CHAN,
                                    DICC_CPU_ID_ACPU);

    /*���µ�ǰSLICE*/
    CSD_SetCurrTxSlice(OM_GetSlice());

    if ( DICC_OK != ulRslt )
    {
        CSD_ERROR_LOG1(ACPU_PID_CSD,
                      "CSD_UL_SendDataToDICC:: DICC_TriggerChanDataTx Fail",
                      ulRslt);

        return CSD_UL_SEND_DATA_NOT_CONTINUE;
    }

    if (ulLinkCnt > ulFreeSpaceCnt)
    {
        CSD_WARNING_LOG(ACPU_PID_CSD,
                        "CSD_UL_SendDataToDICC CSD_UL_SEND_DATA_CONTINUE !");

        return CSD_UL_SEND_DATA_CONTINUE;
    }

    return CSD_UL_SEND_DATA_NOT_CONTINUE;
}


/*****************************************************************************
 �� �� ��  : CSD_UL_CalcIsrSlice
 ��������  : ��ȡ����DICC�жϼ��ʱ��
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��12��19��
    ��    ��   : w00199382
    �޸�����   : �����ɺ���
  2.��    ��   : 2013��03��07��
    ��    ��   : f00179208
    �޸�����   : timer�ɵݼ�ת��Ϊ����
*****************************************************************************/
VOS_UINT32 CSD_UL_CalcIsrSlice(VOS_VOID)
{
    VOS_UINT32                          ulCurrSliceCnt;
    VOS_UINT32                          ulLastSliceCnt;
    VOS_UINT32                          ulSliceDuration;

    ulLastSliceCnt     = CSD_GetLastTxSlice();
    ulCurrSliceCnt     = OM_GetSlice();

    /* Modified by f00179208 for timer_modify, 2013-03-07, Begin */
    /* ʱ�������0��ʼ���������Ե�ǰ��ʱ���Ӧ�ô����ϴΡ�����ʱ���
       ��0xFFFFFFFFʱ�����õ�0������else��֧����������� */
    if (ulCurrSliceCnt > ulLastSliceCnt)
    {
        ulSliceDuration = ulCurrSliceCnt - ulLastSliceCnt;
    }
    else
    {
        ulSliceDuration = CSD_MAX_SLICE_CNT - ulLastSliceCnt + ulCurrSliceCnt;
    }
    /* Modified by f00179208 for timer_modify, 2013-03-07, End */

    return ulSliceDuration;
}

/*****************************************************************************
 �� �� ��  : CSD_UL_ProcDataTask
 ��������  : �������ݴ���
 �������  : void
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��12��7��
    ��    ��   : w00199382
    �޸�����   : �����ɺ���
  2.��    ��   : 2012��12��13��
    ��    ��   : L00171473
    �޸�����   : DTS2012121802573, TQE����
*****************************************************************************/
VOS_VOID CSD_UL_ProcDataTask(VOS_VOID)
{
    VOS_SEM                             hUpLinkSem = VOS_NULL_PTR;
    VOS_UINT32                          ulSliceDurationCnt;
    CSD_UL_SEND_DATA_STATE_ENUM_UINT16  enSendDataRslt;

    hUpLinkSem               = CSD_GetUpLinkDataSem();

    for ( ; ; )
    {

        /* ��ȡ�ź���, ��ȡ����ʱ��, ˵�����Է������� */
        if (VOS_OK != VOS_SmP(hUpLinkSem, 0))
        {
            CSD_NORMAL_LOG(ACPU_PID_CSD,
                          "CSD_UL_ProcDataTask:: VOS_SmP pulUpLinkSem then continue !");

            /* Modified by l00171473 for DTS2012121802573, 2012-12-12, begin */

#ifdef __PC_UT__
            break;
#else
            continue;
#endif
            /* Modified by l00171473 for DTS2012121802573, 2012-12-12, end */

        }


        for ( ; ; )
        {
            /*�жϵ�ǰ�Ƿ񲦺ųɹ�*/
            if (AT_CSD_CALL_STATE_ON != CSD_GetCallState())
            {
                CSD_WARNING_LOG(ACPU_PID_CSD,
                                "CSD_UL_ProcDataTask:: NOT AT_CSD_CALL_STATE_ON then Break !");

                break;
            }

            /*��ȡ�����жϼ��ʱ��*/
            ulSliceDurationCnt = CSD_UL_CalcIsrSlice();

            /*��ȡ��ǰSLICE������ϴη����Ƿ����10MS, �״η���, ����Ҫ�ж� */
            if (ulSliceDurationCnt < CSD_TEN_MILLISECOND)
            {
                CSD_WARNING_LOG(ACPU_PID_CSD,
                                "CSD_UL_ProcDataTask:: ulSliceDurationCnt < CSD_TX_DURATION then continue !");

                VOS_TaskDelay(CSD_UL_TASK_DELAY_TIME);

                continue;
            }

            /* ��DICC����һ������ */
            enSendDataRslt = CSD_UL_SendDataToDICC();

            /* ���û�л���δ���͵�����, ѭ���˳� */
            if (CSD_UL_SEND_DATA_CONTINUE != enSendDataRslt)
            {
                CSD_NORMAL_LOG(ACPU_PID_CSD,
                               "CSD_UL_ProcDataTask:: CSD_UL_SEND_DATA_NOT_CONTINUE ");

                break;
            }
        }

#ifdef __PC_UT__
        break;
#endif
    }
}
/*****************************************************************************
 �� �� ��  : CSD_UL_RcvAtCallStateOn
 ��������  : �������յ�callstateon��״̬
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��12��20��
    ��    ��   : w00199382
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_UINT32 CSD_UL_RcvAtCallStateOn(VOS_VOID)
{
    VOS_UINT32                          ulRslt;

    /*��ʼ���������*/
    ulRslt  = CSD_UL_InitQueue();

    if (VOS_ERR == ulRslt )
    {
        CSD_ERROR_LOG(ACPU_PID_CSD,
                      "CSD_UL_RcvAtCallStateInd:: CSD_UL_InitQueue Fail Set State Off");

        /*�����ʼ���쳣ʱ������Ϊ��ǰδ���ųɹ�*/
        CSD_SetCallState(AT_CSD_CALL_STATE_OFF);

        return VOS_ERR;
    }

    CSD_SetCallState(AT_CSD_CALL_STATE_ON);

    return VOS_OK;
}
/*****************************************************************************
 �� �� ��  : CSD_UL_RcvAtCallStateOff
 ��������  : �����յ�AT��callstateoff��Ϣ
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��12��20��
    ��    ��   : w00199382
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_UINT32 CSD_UL_RcvAtCallStateOff(VOS_VOID)
{
    IMM_ZC_HEAD_STRU                   *pstULQueue;
    VOS_UINT32                          ulRslt;

    pstULQueue      = CSD_UL_GetQueue();

    if (VOS_NULL_PTR == pstULQueue )
    {
        CSD_WARNING_LOG(ACPU_PID_CSD,
                        "CSD_UL_RcvAtCallStateInd:: pstULQueue Is NullSet State Off !");

        CSD_SetCallState(AT_CSD_CALL_STATE_OFF);

        return VOS_OK;
    }

    VOS_TaskLock();

    /*����������*/
    ulRslt          = CSD_UL_FreeQueue(pstULQueue);

    /*�ͷ�ͷ���*/
    PS_MEM_FREE(ACPU_PID_CSD, pstULQueue);

    /*ͷ�����Ϊ��*/
    CSD_UL_SetQueue(VOS_NULL_PTR);

    VOS_TaskUnlock();

    if (VOS_OK != ulRslt)
    {
        CSD_ERROR_LOG(ACPU_PID_CSD,
                      "CSD_UL_RcvAtCallStateInd:: CSD_UL_FreeQueue Fail Set State Off");
    }

    /*�жϼ��SLICE����*/
    CSD_SetCurrTxSlice(CSD_DEFAULT_TX_SLICE);

    CSD_SetCallState(AT_CSD_CALL_STATE_OFF);

    return VOS_OK;
}

/*****************************************************************************
 �� �� ��  : CSD_UL_RcvAtCallStateInd
 ��������  : ����At������ָʾvedio phone״̬��ָʾ
 �������  : AT_CSD_CALL_TYPE_STATE enCallState
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��12��6��
    ��    ��   : w00199382
    �޸�����   : �����ɺ���
  2.��    ��   : 2013��05��28��
    ��    ��   : f00179208
    �޸�����   : V3R3 PPP PROJECT
*****************************************************************************/
VOS_UINT32 CSD_UL_RcvAtCallStateInd(MsgBlock* pMsg)
{
    VOS_UINT32                          ulRslt;
    AT_CSD_CALL_TYPE_STATE_ENUM_UINT16  enCallState;
    AT_CSD_CALL_STATE_TYPE_IND_STRU    *pstMsg;

    pstMsg          = (AT_CSD_CALL_STATE_TYPE_IND_STRU *)pMsg;
    enCallState     = pstMsg->enCallState;

    /* Added by f00179208 for V3R3 PPP RPOJECT 2013-05-28, Begin */
    CSD_UL_SetAtClientIndex(pstMsg->ucIndex);
    /* Added by f00179208 for V3R3 PPP RPOJECT 2013-05-28, End */

    if (AT_CSD_CALL_STATE_ON == enCallState)
    {
        ulRslt      = CSD_UL_RcvAtCallStateOn();
    }
    else if (AT_CSD_CALL_STATE_OFF == enCallState)
    {
        ulRslt      = CSD_UL_RcvAtCallStateOff();
    }
    else
    {
        CSD_ERROR_LOG1(ACPU_PID_CSD,
                      "CSD_UL_RcvAtCallStateInd:: enCallState Illage",
                      enCallState);

        return VOS_ERR;
    }

    return ulRslt;

}

/*****************************************************************************
 �� �� ��  : CSD_UL_ProcMsg
 ��������  : CSD ����PID��Ϣ����
 �������  : MsgBlock* pMsg
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2011��12��6��
   ��    ��   : w00199382
   �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID CSD_UL_ProcMsg(MsgBlock* pMsg)
{

    if (VOS_NULL_PTR == pMsg)
    {
        CSD_ERROR_LOG1(ACPU_PID_CSD,
                      "CSD_UL_ProcMsg:: pMsg is Null",
                      pMsg);
        return ;
    }

    switch ( pMsg->ulSenderPid )
    {
        case WUEPS_PID_AT :
            CSD_UL_RcvAtMsg(pMsg);
            break;

        default:
            CSD_ERROR_LOG1(ACPU_PID_CSD,
                          "CSD_UL_ProcMsg:: ulSenderPid Illage",
                          pMsg->ulSenderPid);
            break;
    }
}

/*****************************************************************************
 �� �� ��  : CSD_UL_RcvAtMsg
 ��������  : ��������PID��Ϣ
 �������  : struct MsgCB                        *pRcvMsg
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��12��6��
    ��    ��   : w00199382
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID CSD_UL_RcvAtMsg(MsgBlock* pMsg)
{
    MSG_HEADER_STRU                    *pstMsgHeader;

    /* ����Ϣ���л�ȡMSG ID */
    pstMsgHeader = (MSG_HEADER_STRU *)pMsg;

    switch (pstMsgHeader->ulMsgName)
    {
        case ID_AT_CSD_CALL_STATE_IND :
             CSD_UL_RcvAtCallStateInd((MsgBlock *)pMsg);
             break;

        default:
            CSD_ERROR_LOG1(ACPU_PID_CSD,
                          "CSD_UL_RcvAtMsg:: enMsgId Illage",
                          pstMsgHeader->ulMsgName);
            break;
    }


}

#endif /*FEATURE_CSD*/





#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif