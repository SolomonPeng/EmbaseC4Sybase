#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <sybhesql.h>
#include <time.h>
#include "sybsqlex.h"

typedef	struct _ORGAN_VIEW
{
	CS_INT   DISTRICT_NO;
	CS_CHAR  DISTRICT_NAME[40];
	CS_INT   BRANCH_NO;
	CS_CHAR  BRANCH_NAME[40];
	CS_INT   SUB_BRANCH_NO;
	CS_CHAR  SUB_BRANCH_NAME[40];
	CS_INT   BUILD_NO;
	CS_CHAR  BUILD_NAME[40];
	CS_INT   LINE_TEST_NO;
	CS_CHAR  LINE_TEST_NAME[40];
}ORGAN_VIEW;

typedef struct _INCOME_ORGAN
{
	CS_INT  ORG_ID;
	CS_CHAR BRANCH_NO[10];
	CS_CHAR BRANCH_NAME[20];
}INCOME_ORGAN;

typedef	struct _ORGAN
{
	CS_INT   ORG_ID;
	CS_CHAR  ORG_NAME[40];
	CS_INT   ORG_PARENTID;
	CS_CHAR  ORG_TYPEID[10];
}ORGAN;

typedef	struct _STATIC_DATA
{
	CS_CHAR   DICT_ID[30];
	CS_CHAR   DICT_CODE[20];
	CS_CHAR   DICT_NAME[200];
}STATIC_DATA;

typedef struct _ORGAN_STRUCT
{
	CS_CHAR  DISTRICT_NO[10];
	CS_CHAR  DISTRICT_NAME[20];
	CS_CHAR  BRANCH_NO[10];
	CS_CHAR  BRANCH_NAME[20];
	CS_CHAR  SUB_BRANCH_NO[10];
	CS_CHAR  SUB_BRANCH_NAME[20];
	CS_CHAR  BUILD_NO[10];
	CS_CHAR  BUILD_NAME[20];
	CS_CHAR  LINE_TEST_NO[10];
	CS_CHAR  LINE_TEST_NAME[20];
	CS_CHAR  INCOME_BRANCH_NO[10];
	CS_CHAR  INCOME_BRANCH_NAME[20];
}ORGAN_STRUCT;



EXEC SQL INCLUDE SQLCA;

int  g_runflag;
CS_CHAR rp[100];
char    buf[1024];
char g_logpath[150];
int  g_totalrows;
int  g_succrows;
int  g_failrows;
char g_tablename[30];


EXEC SQL BEGIN DECLARE SECTION;

char g_sql[1024];

CS_CHAR m_gszSTAT_TYPE[6+1];
CS_CHAR m_gszPERIODS[10+1];
CS_CHAR m_gszDATA_KIND[8];
CS_CHAR m_gszBEGIN_DATE[10];
CS_CHAR m_gszEND_DATE[10];
CS_CHAR m_gszPRE_BEGIN_DATE[10];
CS_CHAR m_gszPRE_END_DATE[10];
CS_CHAR m_gszSSTATUS[1];
CS_CHAR m_gszISSUE_DATE[10];
CS_INT  m_giPRIORITY;

CS_INT  m_giCALL_TIME_LIMIT;
CS_INT  m_giCALL_TOTAL_LIMIT;



CS_CHAR m_gszACC_NBR[30];
CS_INT  m_giCALL_IN_TIMES;
CS_INT  m_giCALL_IN_TOTAL;
CS_INT  m_giCALL_OUT_TIMES;
CS_INT  m_giCALL_OUT_TOTAL;
CS_CHAR	m_gszCALL_TIMES_SCALE[5];
CS_CHAR	m_gszCALL_TOTAL_SCALE[5];

CS_CHAR m_gszDISTRICT_NO[10];
CS_CHAR m_gszDISTRICT_NAME[20];
CS_CHAR m_gszBRANCH_NO[10];
CS_CHAR m_gszBRANCH_NAME[20];
CS_CHAR m_gszSUB_BRANCH_NO[10];
CS_CHAR m_gszSUB_BRANCH_NAME[20];
CS_CHAR m_gszBUILD_NO[10];
CS_CHAR m_gszBUILD_NAME[20];
CS_CHAR m_gszLINE_TEST_NO[10];
CS_CHAR m_gszLINE_TEST_NAME[20];
CS_CHAR m_gszINCOME_BRANCH_NO[10];
CS_CHAR m_gszINCOME_BRANCH_NAME[20];
CS_CHAR	m_gszSERV_NBR[30];
CS_CHAR	m_gszPROD_ID[20];
CS_CHAR	m_gszPROD_NAME[20];
CS_INT 	m_giEXCHANGE_ID;
CS_INT  m_giINCOME_ORG_ID;
CS_CHAR	m_gszCUST_NAME[160];
CS_CHAR	m_gszCUST_ADDRESS[400];
CS_CHAR	m_gszCERT_TYPE_ID[6];
CS_CHAR	m_gszCERT_TYPE[30];
CS_CHAR	m_gszCERT_ID[80];
CS_CHAR	m_gszCUST_CLASS_DL_ID[6];
CS_CHAR	m_gszCUST_CLASS_DL[30];
CS_CHAR	m_gszCUST_CLASS_XL_ID[6];
CS_CHAR	m_gszCUST_CLASS_XL[40];
CS_CHAR	m_gszRELA_MAN[80];
CS_CHAR	m_gszRELA_PHONE[40];
CS_CHAR	m_gszCUST_NBR[30];
char    m_gszCUST_TYPE[6];
char    m_gszCUST_TYPE_DESC[20];
char    m_gszCUST_MANAGER_ID[10];
char    m_gszCUST_MANAGER_NAME[60];
CS_CHAR m_gszCUST_PROP_ID[6];
CS_CHAR m_gszCUST_PROP[20];
CS_CHAR	m_gszSYSTEM_NBR[60];
CS_CHAR	m_gszLINE_BOX_NBR[60];
CS_CHAR	m_gszCROSS_BOX_NBR[60];
CS_CHAR	m_gszBLACK_AREA[30];
EXEC SQL END DECLARE SECTION;

static ORGAN_VIEW g_organview[ORGAN_VIEW_SIZE];
static ORGAN g_organ[ORGAN_SIZE];
static STATIC_DATA g_staticdata[STATIC_DATA_SIZE];
static ORGAN_STRUCT g_org;
static INCOME_ORGAN g_incomeorgan[INCOME_ORGAN_SIZE];


void error_handler();
void warning_handler();
void write_log (const char *,const char *);
char *gettime1 (char *);
char *getdate8 (char *);
void printDataInfo();
int  getstatistics();
void updatestatistics();
void drawdata();
void patchdata();
void updatedata();
void InitialOrganView();
void InitialOrgan();
void InitialIncomeOrgan();
void InitialStaticData();
void InitialDataInfo();
void MatchOrgan(CS_INT,CS_INT,ORGAN_STRUCT*);
int  GetDataInfo();
void GetStaticValue(CS_CHAR*,const char*,CS_CHAR*);

int main()
{
	EXEC SQL BEGIN DECLARE SECTION;
	/* storage for login name and password. */
	CS_CHAR	username[30];
	CS_CHAR	password[30];
	CS_CHAR server[30];
	EXEC SQL END DECLARE SECTION;

	EXEC SQL WHENEVER SQLERROR CALL error_handler();
	EXEC SQL WHENEVER SQLWARNING CALL warning_handler();
	EXEC SQL WHENEVER NOT FOUND CONTINUE;





	strcpy(username, USER);
	strcpy(password, PASSWORD);
	strcpy(server,   SERVER);

	EXEC SQL CONNECT :username IDENTIFIED BY :password at connectionsybase using :server;

	EXEC SQL at connectionsybase USE iview;

	InitialOrganView();
	InitialOrgan();
	InitialStaticData();

	g_runflag=1;
	m_giCALL_TIME_LIMIT=3600;
	m_giCALL_TOTAL_LIMIT=10;
	while(g_runflag)
	{
		if(getstatistics())
		{
			if(strcmp(m_gszPERIODS,"WEEK")==0)
			{
				strcpy(g_tablename,"STAT_LDD_INOUT_WEEK");
			}
			else if(strcmp(m_gszPERIODS,"MONTH")==0)
			{
				strcpy(g_tablename,"STAT_LDD_INOUT_MONTH");
			}
			else if(strcmp(m_gszPERIODS,"DATE")==0)
			{
				strcpy(g_tablename,"STAT_LDD_INOUT_DATE");
			}
			if(m_gszSSTATUS[0]=='1')
			{
				write_log("INFO","开始进行长途比多的处理");
				sprintf(buf,"%s,%s,%s,%s",m_gszDATA_KIND,m_gszPERIODS,m_gszBEGIN_DATE,m_gszEND_DATE);
				write_log("INFO",buf);
				drawdata();
				sprintf(buf,"%s提取数据完成!",g_tablename);
				write_log("INFO",buf);
				m_gszSSTATUS[0]='2';
				g_succrows=0;
				g_totalrows=0;
				g_failrows=0;
				updatestatistics();
				patchdata();
				write_log("INFO","长途比多处理完成");
				sprintf(buf,"总行数：%d,成功行数:%d,失败行数:%d",g_totalrows,g_succrows,g_failrows);
				write_log("INFO",buf);
				if(((g_totalrows-g_succrows)/g_totalrows*1.00)>0.1)
				{
					m_gszSSTATUS[0]='e';
				}
				else
				{
					m_gszSSTATUS[0]='3';
				}
				updatestatistics();
			}
			if(m_gszSSTATUS[0]=='2'||m_gszSSTATUS[0]=='e')
			{
				write_log("INFO","开始进行长途去话的处理");
				sprintf(buf,"%s,%s,%s,%s",m_gszDATA_KIND,m_gszPERIODS,m_gszBEGIN_DATE,m_gszEND_DATE);
				g_succrows=0;
				g_totalrows=0;
				g_failrows=0;
				patchdata();

				write_log("INFO","长途去话处理完成");
				sprintf(buf,"总行数：%d,成功行数:%d,失败行数:%d",g_totalrows,g_succrows,g_failrows);
				write_log("INFO",buf);
				if(((g_totalrows-g_succrows)/g_totalrows*1.00)>0.1)
				{
					m_gszSSTATUS[0]='e';
				}
				else
				{
					m_gszSSTATUS[0]='3';
				}
				updatestatistics();
			}
		}
		else
		{
			sleep(300);
		}
	}



	EXEC SQL DISCONNECT connectionsybase;

	exit (STDEXIT);

	return 0;
}

int getstatistics()
{
	EXEC SQL at connectionsybase SELECT STAT_TYPE,PERIODS,DATA_KIND,CONVERT(VARCHAR,BEGIN_DATE,112),
		CONVERT(VARCHAR,END_DATE,112),STATUS
INTO :m_gszSTAT_TYPE, :m_gszPERIODS, :m_gszDATA_KIND, :m_gszBEGIN_DATE, :m_gszEND_DATE, :m_gszSSTATUS
	  FROM STATISTICS_INFO WHERE STAT_TYPE='LDD' AND DATA_KIND IN ('DIS_1','DIS_2') 
	  AND ISNULL(STATUS,'0') IN ('1','2','e','E') ORDER BY STATUS DESC,ISNULL(PRIORITY,0) DESC,BEGIN_DATE ASC;

	if (sqlca.sqlcode == 100) 
	{
		return 0;
	}

	return 1;
}

void updatestatistics()
{
	EXEC SQL at connectionsybase UPDATE STATISTICS_INFO SET STATUS=:m_gszSSTATUS,ISSUE_DATE=getdate()
		WHERE STAT_TYPE=:m_gszSTAT_TYPE AND DATA_KIND=:m_gszDATA_KIND AND PERIODS=:m_gszPERIODS 
		AND BEGIN_DATE=:m_gszBEGIN_DATE	AND END_DATE=:m_gszEND_DATE;
}

void drawdata()
{
	sprintf(g_sql,"INSERT INTO %s(ACC_NBR,DIS_TYPE,CALL_IN_TIMES,CALL_IN_TOTAL,CALL_OUT_TIMES,CALL_OUT_TOTAL,BEGIN_DATE,END_DATE,CREATE_DATE) "
		"SELECT NUM as ACC_NBR,DIS_TYPE,CALL_IN_TIMES,CALL_IN_TOTAL,CALL_OUT_TIMES,CALL_OUT_TOTAL,TJ_BEGIN_DATE,TJ_END_DATE,GETDATE() FROM JKT_LONG_DIS "
		"WHERE DIS_TYPE='%s' AND TJ_BEGIN_DATE='%s' AND TJ_END_DATE='%s' AND (CALL_IN_TIMES+CALL_OUT_TIMES)>=%d AND (CALL_IN_TOTAL+CALL_OUT_TOTAL)>=%d",
		g_tablename,m_gszBEGIN_DATE,m_gszEND_DATE,m_gszDATA_KIND,m_gszBEGIN_DATE,m_gszEND_DATE,m_giCALL_TIME_LIMIT,m_giCALL_TOTAL_LIMIT);

	EXEC SQL at connectionsybase EXECUTE IMMEDIATE :g_sql;
	EXEC SQL at connectionsybase COMMIT WORK;

	EXEC SQL at connectionsybase DELETE FROM JKT_LONG_DIS
		WHERE DIS_TYPE=:m_gszDATA_KIND AND TJ_BEGIN_DATE=:m_gszBEGIN_DATE AND TJ_END_DATE=:m_gszEND_DATE;
	EXEC SQL at connectionsybase COMMIT WORK;
}

void patchdata()
{
	sprintf(g_sql,"SELECT ACC_NBR,CALL_IN_TIMES,CALL_IN_TOTAL,CALL_OUT_TIMES,CALL_OUT_TOTAL FROM %s WHERE DIS_TYPE='%s' AND BEGIN_DATE='%s' AND END_DATE='%s' AND ISNULL(STATUS,'0') IN ('0','E')",
		g_tablename,m_gszDATA_KIND,m_gszBEGIN_DATE,m_gszEND_DATE);
	EXEC SQL PREPARE select_stmt FROM :g_sql;

	EXEC SQL DECLARE ldd CURSOR FOR select_stmt;


	EXEC SQL OPEN ldd;

	for (int i=0;;i++)
	{
		if(i%500==0)
		{
			sprintf(buf,"%s,%s达到提交点，已处理数据%d条",m_gszSTAT_TYPE,m_gszDATA_KIND,i);
			write_log("INFO",buf);
		}
		InitialDataInfo();
		EXEC SQL at connectionsybase FETCH ldd INTO :m_gszACC_NBR, :m_giCALL_IN_TIMES, :m_giCALL_IN_TOTAL, :m_giCALL_OUT_TIMES, :m_giCALL_OUT_TOTAL;
		g_totalrows++;
		if (sqlca.sqlcode == 100)
		{
			break;
		}
		if(GetDataInfo())
		{
			updatedata();
			g_succrows++;
		}
		else
		{
			if(g_failrows>500)
			{
				g_runflag=0;
				return;
			}
			continue;
		}

	}

	EXEC SQL at connectionsybase CLOSE ldd;
	EXEC SQL at connectionsybase DEALLOCATE CURSOR ldd;
	EXEC SQL DEALLOCATE PREPARE select_stmt;
}


void updatedata()
{
	sprintf(g_sql,"UPDATE %s SET CALL_TIMES_SCALE='%s',CALL_TOTAL_SCALE='%s',"
		"DISTRICT_NO='%s',DISTRICT_NAME='%s',BRANCH_NO='%s',BRANCH_NAME='%s',"
		"SUB_BRANCH_NO='%s',SUB_BRANCH_NAME='%s',BUILD_NO='%s',BUILD_NAME='%s',LINE_TEST_NO='%s',"
		"LINE_TEST_NAME='%s',INCOME_BRANCH_NO='%s',INCOME_BRANCH_NAME='%s',SERV_NBR='%s',PROD_NAME='%s',"
		"CUST_NAME='%s',CUST_ADDRESS='%s',CUST_NBR='%s',CUST_PROP='%s',CUST_CLASS_DL='%s',CUST_CLASS_XL='%s',"
		"CERT_TYPE='%s',CERT_ID='%s',RELA_MAN='%s',RELA_PHONE='%s',CUST_TYPE='%s',CUST_TYPE_DESC='%s',"
		"CUST_MANAGER_ID='%s',CUST_MANAGER_NAME='%s',SYSTEM_NBR='%s',LINE_BOX_NBR='%s',CROSS_BOX_NBR='%s',"
		"BLACK_AREA='%s',STATUS='2' WHERE ACC_NBR='%s'",g_tablename,
		m_gszCALL_TIMES_SCALE,m_gszCALL_TOTAL_SCALE,
		m_gszDISTRICT_NO,m_gszDISTRICT_NAME,m_gszBRANCH_NO,m_gszBRANCH_NAME,m_gszSUB_BRANCH_NO,m_gszSUB_BRANCH_NAME,
		m_gszBUILD_NO,m_gszBUILD_NAME,m_gszLINE_TEST_NO,m_gszLINE_TEST_NAME,m_gszINCOME_BRANCH_NO,m_gszINCOME_BRANCH_NAME,
		m_gszSERV_NBR,m_gszPROD_NAME,m_gszCUST_NAME,m_gszCUST_ADDRESS,m_gszCUST_NBR,m_gszCUST_PROP,
		m_gszCUST_CLASS_DL,m_gszCUST_CLASS_XL,m_gszCERT_TYPE,m_gszCERT_ID,m_gszRELA_MAN,m_gszRELA_PHONE,
		m_gszCUST_TYPE,m_gszCUST_TYPE_DESC,m_gszCUST_MANAGER_ID,m_gszCUST_MANAGER_NAME,m_gszSYSTEM_NBR,
		m_gszLINE_BOX_NBR,m_gszCROSS_BOX_NBR,m_gszBLACK_AREA,m_gszACC_NBR);
	EXEC SQL at connectionsybase EXECUTE IMMEDIATE :g_sql;

	EXEC SQL at connectionsybase COMMIT WORK;
}

int GetDataInfo()
{
	EXEC SQL at connectionsybase 
		SELECT SERV_NBR,ISNULL(LTRIM(RTRIM(PROD_ID)),''),EXCHANGE_ID,ISNULL(INCOMEORGID,0),
		ISNULL(LTRIM(RTRIM(CUST_NAME)),''),ISNULL(LTRIM(RTRIM(CUST_ADDRESS)),''),
		ISNULL(LTRIM(RTRIM(CERT_TYPE)),''),ISNULL(LTRIM(RTRIM(CERT_ID)),''),
		ISNULL(LTRIM(RTRIM(CUST_CLASS_DL)),''),ISNULL(LTRIM(RTRIM(CUST_CLASS_XL)),''),
		ISNULL(LTRIM(RTRIM(RELA_MAN)),''),ISNULL(LTRIM(RTRIM(RELA_PHONE)),''),
		ISNULL(LTRIM(RTRIM(CUST_VIP_CODE)),''),ISNULL(LTRIM(RTRIM(CUST_PROP)),''),
		ISNULL(LTRIM(RTRIM(SYSTEM_NBR)),''),ISNULL(LTRIM(RTRIM(LINE_BOX_NBR)),''),
		ISNULL(LTRIM(RTRIM(CROSS_BOX_NBR)),''),ISNULL(LTRIM(RTRIM(BLACK_AREA)),''),
		ISNULL(LTRIM(RTRIM(CUST_TYPE)),''),ISNULL(LTRIM(RTRIM(CUST_MANAGER_ID)),''),
		ISNULL(LTRIM(RTRIM(CUST_MANAGER_NAME)),'') 
INTO	:m_gszSERV_NBR, :m_gszPROD_ID, :m_giEXCHANGE_ID, :m_giINCOME_ORG_ID, 
		 :m_gszCUST_NAME, :m_gszCUST_ADDRESS, :m_gszCERT_TYPE_ID,:m_gszCERT_ID, 
		 :m_gszCUST_CLASS_DL_ID, :m_gszCUST_CLASS_XL_ID,:m_gszRELA_MAN, :m_gszRELA_PHONE, 
		 :m_gszCUST_NBR, :m_gszCUST_PROP_ID, :m_gszSYSTEM_NBR, :m_gszLINE_BOX_NBR, 
		 :m_gszCROSS_BOX_NBR, :m_gszBLACK_AREA, :m_gszCUST_TYPE, :m_gszCUST_MANAGER_ID,
		 :m_gszCUST_MANAGER_NAME FROM SERV_INFO 
		 WHERE	ACC_NBR=:m_gszACC_NBR AND STATUS!='DEL';

	if (sqlca.sqlcode == 100) 
	{
		return 1;
	}
	else if(sqlca.sqlcode !=0)
	{
		sprintf(buf,"%s获取服务数据出错",m_gszACC_NBR);
		write_log("ERROR",buf);
		g_failrows++;
		return 0;
	}

	EXEC SQL at connectionsybase 
		SELECT CONVERT(VARCHAR,CONVERT(INT,:m_giCALL_IN_TIMES*100/(:m_giCALL_IN_TIMES+:m_giCALL_OUT_TIMES)*1.00))+'%' INTO :m_gszCALL_TIMES_SCALE;

	EXEC SQL at connectionsybase 
		SELECT CONVERT(VARCHAR,CONVERT(INT,:m_giCALL_IN_TOTAL*100/(:m_giCALL_IN_TOTAL+:m_giCALL_OUT_TOTAL)*1.00))+'%' INTO :m_gszCALL_TOTAL_SCALE;



	MatchOrgan(m_giEXCHANGE_ID,m_giINCOME_ORG_ID,&g_org);
	strcpy(m_gszDISTRICT_NO,g_org.DISTRICT_NO);
	strcpy(m_gszDISTRICT_NAME,g_org.DISTRICT_NAME);
	strcpy(m_gszBRANCH_NO,g_org.BRANCH_NO);
	strcpy(m_gszBRANCH_NAME,g_org.BRANCH_NAME);
	strcpy(m_gszSUB_BRANCH_NO,g_org.SUB_BRANCH_NO);
	strcpy(m_gszSUB_BRANCH_NAME,g_org.SUB_BRANCH_NAME);
	strcpy(m_gszBUILD_NO,g_org.BUILD_NO);
	strcpy(m_gszBUILD_NAME,g_org.BUILD_NAME);
	strcpy(m_gszLINE_TEST_NO,g_org.LINE_TEST_NO);
	strcpy(m_gszLINE_TEST_NAME,g_org.LINE_TEST_NAME);
	strcpy(m_gszINCOME_BRANCH_NO,g_org.INCOME_BRANCH_NO);
	strcpy(m_gszINCOME_BRANCH_NAME,g_org.INCOME_BRANCH_NAME);

	if(m_gszCUST_TYPE[0]!=' ')
	{
		GetStaticValue(m_gszCUST_TYPE,"CUST_TYPE",rp);
		strcpy(m_gszCUST_TYPE_DESC,rp);
	}
	if(m_gszPROD_ID[0]!=' ')
	{
		GetStaticValue(m_gszPROD_ID,"PROD_ID",rp);
		strcpy(m_gszPROD_NAME,rp);
	}
	if(m_gszCUST_PROP_ID[0]!=' ')
	{
		GetStaticValue(m_gszCUST_PROP_ID,"CUST_PROP",rp);
		strcpy(m_gszCUST_PROP,rp);
	}

	if(m_gszCUST_CLASS_DL_ID[0]!=' ')
	{
		GetStaticValue(m_gszCUST_CLASS_DL_ID,"CUST_CLASS_DL",rp);
		strcpy(m_gszCUST_CLASS_DL,rp);
	}
	if(m_gszCUST_CLASS_XL_ID[0]!= ' ')
	{
		GetStaticValue(m_gszCUST_CLASS_XL_ID,"CUST_CLASS_XL",rp);
		strcpy(m_gszCUST_CLASS_XL,rp);
	}
	if(m_gszCERT_TYPE_ID[0]!=' ')
	{
		GetStaticValue(m_gszCERT_TYPE_ID,"CERT_TYPE",rp);
		strcpy(m_gszCERT_TYPE,rp);
	}
	return 1;
}

void InitialOrganView()
{
	EXEC SQL BEGIN DECLARE SECTION;
	CS_INT	m_iDISTRICT_NO;
	CS_CHAR m_szDISTRICT_NAME[40];
	CS_INT	m_iBRANCH_NO;
	CS_CHAR m_szBRANCH_NAME[40];
	CS_INT	m_iSUB_BRANCH_NO;
	CS_CHAR m_szSUB_BRANCH_NAME[40];
	CS_INT	m_iBUILD_NO;
	CS_CHAR m_szBUILD_NAME[40];
	CS_INT	m_iLINE_TEST_NO;
	CS_CHAR m_szLINE_TEST_NAME[40];
	EXEC SQL END DECLARE SECTION;

	EXEC SQL DECLARE oraganview CURSOR FOR 
		SELECT DISTRICT_NO,DISTRICT_NAME,BRANCH_NO1,BRANCH_NAME1,BRANCH_NO2,BRANCH_NAME2, 
		BUILD_NO,BUILD_NAME,LINE_TEST_NO,LINE_TEST_NAME FROM ORGAN_VIEW;

	EXEC SQL OPEN oraganview;


	for (int i=0;i<ORGAN_VIEW_SIZE;i++)
	{
		EXEC SQL at connectionsybase FETCH oraganview INTO :m_iDISTRICT_NO,:m_szDISTRICT_NAME,
			:m_iBRANCH_NO,:m_szBRANCH_NAME,:m_iSUB_BRANCH_NO,:m_szSUB_BRANCH_NAME,
			:m_iBUILD_NO,:m_szBUILD_NAME,:m_iLINE_TEST_NO,:m_szLINE_TEST_NAME;
		g_organview[i].DISTRICT_NO=m_iDISTRICT_NO;
		strcpy(g_organview[i].DISTRICT_NAME,m_szDISTRICT_NAME);
		g_organview[i].BRANCH_NO=m_iBRANCH_NO;
		strcpy(g_organview[i].BRANCH_NAME,m_szBRANCH_NAME);
		g_organview[i].SUB_BRANCH_NO=m_iSUB_BRANCH_NO;
		strcpy(g_organview[i].SUB_BRANCH_NAME,m_szSUB_BRANCH_NAME);
		g_organview[i].BUILD_NO=m_iBUILD_NO;
		strcpy(g_organview[i].BUILD_NAME,m_szBUILD_NAME);
		g_organview[i].LINE_TEST_NO=m_iLINE_TEST_NO;
		strcpy(g_organview[i].LINE_TEST_NAME,m_szLINE_TEST_NAME);
		if (sqlca.sqlcode == 100)
			break;
	}
	EXEC SQL at connectionsybase CLOSE oraganview;
	EXEC SQL at connectionsybase DEALLOCATE CURSOR oraganview;
	printf("InitialOrganView Complete \n");

}

void InitialOrgan()
{
	EXEC SQL BEGIN DECLARE SECTION;
	CS_INT	m_iORG_ID;
	CS_CHAR m_szORG_NAME[40];
	CS_INT	m_iORG_PARENTID;
	CS_CHAR m_szORG_TYPEID[10];
	EXEC SQL END DECLARE SECTION;

	EXEC SQL DECLARE oragan CURSOR FOR 
		SELECT ORG_ID,ORG_NAME,ORG_PARENTID,ORG_TYPEID FROM ORGAN 
		WHERE ORG_TYPEID IN('OT0011','OT0005','OT0004','OT0003','OT0012','OT0001') ORDER BY ORG_ID;

	EXEC SQL OPEN oragan;

	// ORGAN* pORGAN = (ORGAN*)malloc(sizeof(ORGAN)*ORGAN_SIZE);

	for (int i=0;i<ORGAN_SIZE;i++)
	{
		EXEC SQL at connectionsybase FETCH oragan INTO 
			:m_iORG_ID,:m_szORG_NAME,
			:m_iORG_PARENTID,:m_szORG_TYPEID;

		g_organ[i].ORG_ID=m_iORG_ID;
		strcpy(g_organ[i].ORG_NAME,m_szORG_NAME);
		g_organ[i].ORG_PARENTID=m_iORG_PARENTID;
		strcpy(g_organ[i].ORG_TYPEID,m_szORG_TYPEID);
		//printf("%d ,%s \n",g_organ[i].ORG_ID,g_organ[i].ORG_NAME);
		if (sqlca.sqlcode == 100)
			break;
	}
	EXEC SQL at connectionsybase CLOSE oragan;
	EXEC SQL at connectionsybase DEALLOCATE CURSOR oragan;
	printf("InitialOrgan Complete \n");

}

void InitialIncomeOrgan()
{
	EXEC SQL BEGIN DECLARE SECTION;
	CS_INT  m_iORG_ID;
	CS_CHAR m_szBRANCH_NO[10];
	CS_CHAR m_szBRANCH_NAME[20];
	EXEC SQL END DECLARE SECTION;

	EXEC SQL DECLARE incomeorgan CURSOR FOR 
		SELECT ORG_ID,BRANCH_NO,BRANCH_NAME FROM ORGAN_INCOME; 

	EXEC SQL OPEN incomeorgan;
	for (int i=0;i<INCOME_ORGAN_SIZE;i++)
	{
		EXEC SQL at connectionsybase FETCH incomeorgan INTO 
			:m_iORG_ID,:m_szBRANCH_NO,
			:m_szBRANCH_NAME;

		g_incomeorgan[i].ORG_ID=m_iORG_ID;
		strcpy(g_incomeorgan[i].BRANCH_NO,m_szBRANCH_NO);
		strcpy(g_incomeorgan[i].BRANCH_NAME,m_szBRANCH_NAME);
		//printf("%d ,%s \n",g_organ[i].ORG_ID,g_organ[i].ORG_NAME);
		if (sqlca.sqlcode == 100)
			break;
	}
	EXEC SQL at connectionsybase CLOSE incomeorgan;
	EXEC SQL at connectionsybase DEALLOCATE CURSOR incomeorgan;
	printf("InitialOrgan Complete \n");
}

void InitialStaticData()
{

	EXEC SQL BEGIN DECLARE SECTION;
	CS_CHAR m_szDICT_ID[30];
	CS_CHAR m_szDICT_CODE[20];
	CS_CHAR m_szDICT_NAME[200];
	EXEC SQL END DECLARE SECTION;

	EXEC SQL DECLARE staticdata CURSOR FOR 
		SELECT DICT_ID,DICT_CODE,DICT_NAME FROM STATIC_DATA 
		WHERE DICT_ID IN ('PROD_ID','CUST_PROP','CUST_TYPE','CUST_CLASS_DL','CUST_CLASS_XL','CERT_TYPE') 
		AND ISNULL(ENABLE,'0')!='0' ORDER BY DICT_ID,DICT_CODE;

	EXEC SQL OPEN staticdata;


	for (int i=0;i<STATIC_DATA_SIZE;i++)
	{
		EXEC SQL at connectionsybase FETCH staticdata INTO 
			:m_szDICT_ID,:m_szDICT_CODE,:m_szDICT_NAME;
		strcpy(g_staticdata[i].DICT_ID,m_szDICT_ID);
		strcpy(g_staticdata[i].DICT_CODE,m_szDICT_CODE);
		strcpy(g_staticdata[i].DICT_NAME,m_szDICT_NAME);
		if (sqlca.sqlcode == 100)
			break;
	}
	EXEC SQL at connectionsybase CLOSE staticdata;
	EXEC SQL at connectionsybase DEALLOCATE CURSOR staticdata;
}

void InitialOrganStruct(ORGAN_STRUCT* organstruct)
{
	organstruct->DISTRICT_NO[0]        ='\0';
	organstruct->DISTRICT_NAME[0]      ='\0';
	organstruct->BRANCH_NO[0]          ='\0';
	organstruct->BRANCH_NAME[0]        ='\0';
	organstruct->SUB_BRANCH_NO[0]      ='\0';
	organstruct->SUB_BRANCH_NAME[0]    ='\0';
	organstruct->BUILD_NO[0]           ='\0';
	organstruct->BUILD_NAME[0]         ='\0';
	organstruct->LINE_TEST_NO[0]       ='\0';
	organstruct->LINE_TEST_NAME[0]     ='\0';
	organstruct->INCOME_BRANCH_NO[0]   ='\0';
	organstruct->INCOME_BRANCH_NAME[0] ='\0';
}

void InitialDataInfo()
{
	m_gszACC_NBR[0]          ='\0';
	m_giEXCHANGE_ID          =0;
	m_giINCOME_ORG_ID        =0;
	m_gszDISTRICT_NO[0]      ='\0';
	m_gszDISTRICT_NAME[0]    ='\0';
	m_gszBRANCH_NO[0]        ='\0';
	m_gszBRANCH_NAME[0]      ='\0';
	m_gszSUB_BRANCH_NO[0]    ='\0';
	m_gszSUB_BRANCH_NAME[0]  ='\0';
	m_gszBUILD_NO[0]         ='\0';
	m_gszBUILD_NAME[0]       ='\0';
	m_gszLINE_TEST_NO[0]     ='\0';
	m_gszLINE_TEST_NAME[0]   ='\0';
	m_gszINCOME_BRANCH_NO[0] ='\0';
	m_gszINCOME_BRANCH_NAME[0]='\0';
	m_gszSERV_NBR[0]         ='\0';
	m_gszPROD_ID[0]          ='\0';
	m_gszPROD_NAME[0]        ='\0';
	m_gszCUST_NAME[0]        ='\0';
	m_gszCUST_ADDRESS[0]     ='\0';
	m_gszCUST_NBR[0]         ='\0';
	m_gszCUST_TYPE[0]        ='\0';
	m_gszCUST_TYPE_DESC[0]   ='\0';
	m_gszCUST_MANAGER_ID[0]  ='\0';
	m_gszCUST_MANAGER_NAME[0]='\0';
	m_gszCUST_PROP_ID[0]     ='\0';
	m_gszCUST_PROP[0]        ='\0';
	m_gszCUST_CLASS_DL_ID[0] ='\0';
	m_gszCUST_CLASS_DL[0]    ='\0';
	m_gszCUST_CLASS_XL[0]    ='\0';
	m_gszCUST_CLASS_XL_ID[0] ='\0';
	m_gszCERT_TYPE_ID[0]     ='\0';
	m_gszCERT_TYPE[0]        ='\0';
	m_gszCERT_ID[0]          ='\0';
	m_gszRELA_MAN[0]         ='\0';
	m_gszRELA_PHONE[0]       ='\0';
	m_gszSYSTEM_NBR[0]       ='\0';
	m_gszLINE_BOX_NBR[0]     ='\0';
	m_gszCROSS_BOX_NBR[0]    ='\0';
	m_gszBLACK_AREA[0]       ='\0';
	m_gszCALL_TIMES_SCALE[0] ='\0';
	m_gszCALL_TOTAL_SCALE[0] ='\0';
}


void MatchOrgan(CS_INT iEXCHANGE_ID,CS_INT iINCOME_ORGID,ORGAN_STRUCT* organstruct)
{
	InitialOrganStruct(organstruct);
	if(iEXCHANGE_ID==91001)
	{
		strcpy(organstruct->DISTRICT_NO,"1");
		strcpy(organstruct->DISTRICT_NAME,"广州本地网中心局");
		strcpy(organstruct->BRANCH_NO,"91001");
		strcpy(organstruct->BRANCH_NAME,"PHS分局");
		strcpy(organstruct->SUB_BRANCH_NO,"");
		strcpy(organstruct->SUB_BRANCH_NAME,"");
		strcpy(organstruct->BUILD_NO,"3");
		strcpy(organstruct->BUILD_NAME,"GZPHS机楼");
		strcpy(organstruct->LINE_TEST_NO,"4");
		strcpy(organstruct->LINE_TEST_NAME,"GZPHS测量");
		if(iINCOME_ORGID>0)
		{
			for(int k=0;k<INCOME_ORGAN_SIZE;k++)
			{
				if(g_incomeorgan[k].ORG_ID==iINCOME_ORGID)
				{
					strcpy(organstruct->INCOME_BRANCH_NO,g_incomeorgan[k].BRANCH_NO);
					strcpy(organstruct->INCOME_BRANCH_NAME,g_incomeorgan[k].BRANCH_NAME);
				}
			}
		}
		return;
	}
	for(int i=0;i<ORGAN_VIEW_SIZE;i++)
	{
		if(g_organview[i].LINE_TEST_NO==iEXCHANGE_ID)
		{
			sprintf(organstruct->LINE_TEST_NO,"%d",g_organview[i].LINE_TEST_NO);
			sprintf(organstruct->BUILD_NO,"%d",g_organview[i].BUILD_NO);
			sprintf(organstruct->SUB_BRANCH_NO,"%d",g_organview[i].SUB_BRANCH_NO);
			sprintf(organstruct->BRANCH_NO,"%d",g_organview[i].BRANCH_NO);
			sprintf(organstruct->DISTRICT_NO,"%d",g_organview[i].DISTRICT_NO);
			strcpy(organstruct->LINE_TEST_NAME,g_organview[i].LINE_TEST_NAME);
			strcpy(organstruct->BUILD_NAME,g_organview[i].BUILD_NAME);
			strcpy(organstruct->SUB_BRANCH_NAME,g_organview[i].SUB_BRANCH_NAME);
			strcpy(organstruct->BRANCH_NAME,g_organview[i].BRANCH_NAME);
			strcpy(organstruct->DISTRICT_NAME,g_organview[i].DISTRICT_NAME);
			return;
		}
	}
	int iLoop = 0;
	int bLoop = 1;
	CS_INT   iORG_ID;
	CS_CHAR  szORG_NAME[20];
	CS_INT   iORG_PARENTID=iEXCHANGE_ID;
	CS_CHAR  szORG_TYPEID[6];
	while(bLoop)
	{
		iLoop++;
		if( iLoop > 5 )
		{
			bLoop = 0;
			break;
		}
		iORG_ID=0;
		szORG_NAME[0]='\0';
		szORG_TYPEID[0]='\0';
		for(int j=0;j<ORGAN_SIZE;j++)
		{
			if(g_organ[j].ORG_ID==iORG_PARENTID)
			{
				iORG_ID      =g_organ[j].ORG_ID;
				strcpy(szORG_NAME,g_organ[j].ORG_NAME);
				iORG_PARENTID=g_organ[j].ORG_PARENTID;
				strcpy(szORG_TYPEID,g_organ[j].ORG_TYPEID);
				break;
			}
		}
		if(strcmp(szORG_TYPEID,"OT0011")==0)
		{
			sprintf(organstruct->LINE_TEST_NO,"%d",iORG_ID);
			strcpy(organstruct->LINE_TEST_NAME,szORG_NAME);
		}
		else if(strcmp(szORG_TYPEID,"OT0005")==0)
		{
			sprintf(organstruct->BUILD_NO,"%d",iORG_ID);
			strcpy(organstruct->BUILD_NAME,szORG_NAME);
		}
		else if(strcmp(szORG_TYPEID,"OT0004")==0)
		{
			sprintf(organstruct->SUB_BRANCH_NO,"%d",iORG_ID);
			strcpy(organstruct->SUB_BRANCH_NAME,szORG_NAME);
		}
		else if(strcmp(szORG_TYPEID,"OT0003")==0)
		{
			sprintf(organstruct->BRANCH_NO,"%d",iORG_ID);
			strcpy(organstruct->BUILD_NAME,szORG_NAME);
		}
		else if(strcmp(szORG_TYPEID,"OT0012")==0)
		{
			sprintf(organstruct->DISTRICT_NO,"%d",iORG_ID);
			strcpy(organstruct->DISTRICT_NAME,szORG_NAME);
		}
		else if(strcmp(szORG_TYPEID,"OT0001")==0 ||iORG_PARENTID==1)	//顶级
		{
			bLoop = 0;
			break;
		}
	}
}

void GetStaticValue(CS_CHAR* szSTATIC_CODE,const char* szSTATIC_TYPE,CS_CHAR* szrp)
{
	szrp[0]='\0';
	for(int i=0;i<STATIC_DATA_SIZE;i++)
	{
		if(strcmp(g_staticdata[i].DICT_ID,szSTATIC_TYPE)!=0)
		{
			continue;
		}
		if(strcmp(g_staticdata[i].DICT_CODE,szSTATIC_CODE)==0)
		{
			strcpy(szrp, (g_staticdata[i]).DICT_NAME);
			return;
		}
	}
}

void printDataInfo()
{
	printf("m_gszACC_NBR:%s\n",m_gszACC_NBR);
	printf("m_giEXCHANGE_ID:%d\n",m_giEXCHANGE_ID);
	printf("m_gszDISTRICT_NO:%s\n",m_gszDISTRICT_NO);
	printf("m_gszDISTRICT_NAME:%s\n",m_gszDISTRICT_NAME);
	printf("m_gszBRANCH_NO:%s\n",m_gszBRANCH_NO);
	printf("m_gszBRANCH_NAME:%s\n",m_gszBRANCH_NAME);
	printf("m_gszSUB_BRANCH_NO:%s\n",m_gszSUB_BRANCH_NO);
	printf("m_gszSUB_BRANCH_NAME:%s\n",m_gszSUB_BRANCH_NAME);
	printf("m_gszBUILD_NO:%s\n",m_gszBUILD_NO);
	printf("m_gszBUILD_NAME:%s\n",m_gszBUILD_NAME);
	printf("m_gszLINE_TEST_NO:%s\n",m_gszLINE_TEST_NO);
	printf("m_gszLINE_TEST_NAME:%s\n",m_gszLINE_TEST_NAME);
	printf("m_gszSERV_NBR:%s\n",m_gszSERV_NBR);
	printf("m_gszPROD_ID:%s\n",m_gszPROD_ID);
	printf("m_gszPROD_NAME:%s\n",m_gszPROD_NAME);
	printf("m_gszCUST_NAME:%s\n",m_gszCUST_NAME);
	printf("m_gszCUST_ADDRESS:%s\n",m_gszCUST_ADDRESS);
	printf("m_gszCUST_NBR:%s\n",m_gszCUST_NBR);
	printf("m_gszCUST_PROP_ID:%s\n",m_gszCUST_PROP_ID);
	printf("m_gszCUST_PROP:%s\n",m_gszCUST_PROP);
	printf("m_gszCUST_CLASS_DL_ID:%s\n",m_gszCUST_CLASS_DL_ID);
	printf("m_gszCUST_CLASS_DL:%s\n",m_gszCUST_CLASS_DL);
	printf("m_gszCUST_CLASS_XL_ID:%s\n",m_gszCUST_CLASS_XL_ID);
	printf("m_gszCUST_CLASS_XL:%s\n",m_gszCUST_CLASS_XL);
	printf("m_gszCERT_TYPE_ID:%s\n",m_gszCERT_TYPE_ID);
	printf("m_gszCERT_TYPE:%s\n",m_gszCERT_TYPE);
	printf("m_gszCERT_ID:%s\n",m_gszCERT_ID);
	printf("m_gszRELA_MAN:%s\n",m_gszRELA_MAN);
	printf("m_gszRELA_PHONE:%s\n",m_gszRELA_PHONE);
	printf("m_gszSYSTEM_NBR:%s\n",m_gszSYSTEM_NBR);
	printf("m_gszLINE_BOX_NBR:%s\n",m_gszLINE_BOX_NBR);
	printf("m_gszCROSS_BOX_NBR:%s\n",m_gszCROSS_BOX_NBR);
	printf("m_gszBLACK_AREA:%s\n",m_gszBLACK_AREA);
}

void error_handler()
{

	char  sqlInfo[1024];
	char  sqlInfoToken[1024];

	strcpy(sqlInfo, "");
	sprintf( sqlInfoToken, "SQLCODE       = %ld\n", sqlca.sqlcode);
	strcat( sqlInfo, sqlInfoToken);		
	//printf("%s\n",sqlInfo);
	//printf("%s\n",sqlca.sqlerrm.sqlerrmc);
	sprintf(buf,"%s,%s",sqlInfo,sqlca.sqlerrm.sqlerrmc);
	write_log("ERROR",buf);
}

void warning_handler()
{
	char  sqlInfo[1024];

	strcpy(sqlInfo, "");
	if (sqlca.sqlwarn[0]=='W')
		strcat( sqlInfo, "One Or more warning conditions occurred!\n");	
	if (sqlca.sqlwarn[1]=='W')
		strcat( sqlInfo, "You designated in a fetch statement was too short to store the statement's result data,so the result data was truncated or designated no indicator variable to receive the original length of the data that was truncated.!\n");	
	if (sqlca.sqlwarn[2]=='W')
		strcat( sqlInfo, "The input sent to adaptive Server contained a null value in an illegal context,such as in an expression or as an input value to a table than prohibits null values.!\n");	
	if (sqlca.sqlwarn[3]=='W')
		strcat( sqlInfo, "The numbers of columns in a select statement's result set exceeds the number of host variables in the statement's into clause!\n");	
	if (sqlca.sqlwarn[5]=='W')
		strcat( sqlInfo, "SQL Server generated a conversion error while attempting to execute this statement.\n");	
	//printf("%s\n",sqlInfo);
	sprintf(buf,"%s",sqlInfo);
	write_log("ERROR",buf);
}

char *getdate8 (char *buff)
{
	struct tm     *tm_now;
	time_t        time_now;
	static char   sbuff[20];

	time_now = time (NULL);
	tm_now = localtime (&time_now);
	if (buff != NULL)  {
		sprintf (buff, "%04d%02d%02d", tm_now->tm_year + 1900,
			tm_now->tm_mon + 1, tm_now->tm_mday);
		return (buff);
	} else  {
		sprintf (sbuff, "%04d%02d%02d", tm_now->tm_year + 1900,
			tm_now->tm_mon + 1, tm_now->tm_mday);
		return (sbuff);
	}
}

char *gettime1 (char *buff)
{
	struct tm     *tm_now;
	time_t        time_now;
	static char   sbuff[20];

	time_now = time (NULL);
	tm_now = localtime (&time_now);
	if (buff != NULL)  {
		sprintf (buff, "%02d:%02d:%02d", tm_now->tm_hour, tm_now->tm_min,
			tm_now->tm_sec);
		return (buff);
	} else  {
		sprintf (sbuff, "%02d:%02d:%02d", tm_now->tm_hour, tm_now->tm_min,
			tm_now->tm_sec);
		return (sbuff);
	}
}


void write_log (const char *level,const char * msg)
{
	FILE          *fp;
	char          w_buff1[20], w_buff2[20];
	strcpy(g_logpath,"../log/LDDIO");
	strcat(g_logpath,getdate8(w_buff1));
	fp = fopen (g_logpath, "a+");
	if (fp != NULL)  {
		fprintf (fp, "%s;%s;[%s];%s;\n", getdate8(w_buff1), gettime1(w_buff2),level,msg);
	}
	fclose (fp);
}