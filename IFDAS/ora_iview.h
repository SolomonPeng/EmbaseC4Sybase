/******************************************************************************
Copyright (c) 2007 All rights reserved. 广东天讯电信科技有限公司
Date:         2007-06-12
Author:       黄海旺
File:         ora_iview.h
Description:  根据用户接入号或者客户编号从CMMS系统数据库中取客户经理信息.
              
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
Input:    i_type  查询类型标识
          i_num   客户接入号
          i_code  客户编号
output:   i_info  返回的客户经理信息
Retrun:   0 表示查询信息成功,-1 表示查询信息失败或没有查到客户经理信息.
Date:     2007-06-12
******************************************************************************/
extern int get_cmms_staff(char i_type,char *i_num,char *i_code,CMMSINFO *i_info);
extern int get_service_staff(char i_type,char *i_num,char *i_code,char *i_staff_id,char *i_staff_name,char *i_cust_type,char *i_rusult);

/******************************************************************************
Function: get_hmg_gxjr
Input:    beginDate 开始时间
          endDate   结束时间
output:   NULL
Retrun:   0 表示处理成功,-1 表示处理失败.
Date:     2007-06-12
Description: 从傲天的系统提取共享接入信息到IVIEW数据库.
******************************************************************************/
extern int get_hmg_gxjr(char *beginDate,char *endDate);

/******************************************************************************
Function: get_hmg_gxjr
Input:    NULL
output:   NULL
Retrun:   0 表示处理成功,-1 表示处理失败.
Date:     2007-06-12
Description: 从傲天的系统提取VOIP用户信息到IVIEW数据库.
******************************************************************************/
extern int get_hmg_voipusers(char *beginDate,char *endDate);

/******************************************************************************
Function: get_hmg_gxjr
Input:    NULL
output:   NULL
Retrun:   0 表示处理成功,-1 表示处理失败.
Date:     2007-06-12
Description: 从傲天的系统提取用户IP信息到IVIEW数据库.
******************************************************************************/
extern int get_hmg_voipipnet(char *beginDate,char *endDate);

/******************************************************************************
Function: get_hmg_gxjr
Input:    NULL
output:   NULL
Retrun:   0 表示处理成功,-1 表示处理失败.
Date:     2007-06-12
Descripiton: 将以上的三个功能函数集在一起
******************************************************************************/
extern int get_hmg_all(char *beginDate,char *endDate);

#endif
