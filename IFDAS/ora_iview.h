/******************************************************************************
Copyright (c) 2007 All rights reserved. �㶫��Ѷ���ſƼ����޹�˾
Date:         2007-06-12
Author:       �ƺ���
File:         ora_iview.h
Description:  �����û�����Ż��߿ͻ���Ŵ�CMMSϵͳ���ݿ���ȡ�ͻ�������Ϣ.
              
*******************************************************************************/
#ifndef  ORA_IVIEW_INCLUDE 
#define ORA_IVIEW_INCLUDE

#include <string.h>
#include <stdio.h>
#include <sqlca.h>
#include <stdlib.h>
#include <sqlda.h>
#include <sqlcpr.h>

#define SQLNOTFOUND 		1403
#define SQLNOTCONNECT   1012
#define SQLUNIQUE		    1
#define SQLEXIST		    -1
#define FIELD_MAX_SIZE  1024

struct cmms_info
{
  char m_staff_id[FIELD_MAX_SIZE];
  char m_staff_name[FIELD_MAX_SIZE];
  char m_cust_type[FIELD_MAX_SIZE];
  char m_result[FIELD_MAX_SIZE];	
};

typedef struct cmms_info CMMSINFO;

/******************************************************************************
Function: get_cmms_staff
Input:    i_type  ��ѯ���ͱ�ʶ
          i_num   �ͻ������
          i_code  �ͻ����
output:   i_info  ���صĿͻ�������Ϣ
Retrun:   0 ��ʾ��ѯ��Ϣ�ɹ�,-1 ��ʾ��ѯ��Ϣʧ�ܻ�û�в鵽�ͻ�������Ϣ.
Date:     2007-06-12
******************************************************************************/
extern int get_cmms_staff(char i_type,char *i_num,char *i_code,CMMSINFO *i_info);
extern int get_service_staff(char i_type,char *i_num,char *i_code,char *i_staff_id,char *i_staff_name,char *i_cust_type,char *i_rusult);

/******************************************************************************
Function: get_hmg_gxjr
Input:    beginDate ��ʼʱ��
          endDate   ����ʱ��
output:   NULL
Retrun:   0 ��ʾ����ɹ�,-1 ��ʾ����ʧ��.
Date:     2007-06-12
Description: �Ӱ����ϵͳ��ȡ���������Ϣ��IVIEW���ݿ�.
******************************************************************************/
extern int get_hmg_gxjr(char *beginDate,char *endDate);

/******************************************************************************
Function: get_hmg_gxjr
Input:    NULL
output:   NULL
Retrun:   0 ��ʾ����ɹ�,-1 ��ʾ����ʧ��.
Date:     2007-06-12
Description: �Ӱ����ϵͳ��ȡVOIP�û���Ϣ��IVIEW���ݿ�.
******************************************************************************/
extern int get_hmg_voipusers(char *beginDate,char *endDate);

/******************************************************************************
Function: get_hmg_gxjr
Input:    NULL
output:   NULL
Retrun:   0 ��ʾ����ɹ�,-1 ��ʾ����ʧ��.
Date:     2007-06-12
Description: �Ӱ����ϵͳ��ȡ�û�IP��Ϣ��IVIEW���ݿ�.
******************************************************************************/
extern int get_hmg_voipipnet(char *beginDate,char *endDate);

/******************************************************************************
Function: get_hmg_gxjr
Input:    NULL
output:   NULL
Retrun:   0 ��ʾ����ɹ�,-1 ��ʾ����ʧ��.
Date:     2007-06-12
Descripiton: �����ϵ��������ܺ�������һ��
******************************************************************************/
extern int get_hmg_all(char *beginDate,char *endDate);

#endif
