#include <stdio.h>
#include <string.h>
#include <alloc.h>
#include <sybhesql.h>
#include "sybsqlex.h"

	typedef	struct _ORGAN_VIEW
	{
		CS_INT   DISTRICT_NO;
		CS_CHAR  DISTIRCT_NAME[20];
		CS_INT   BRANCH_NO;
		CS_CHAR  BRANCH_NAME[20];
		CS_INT   SUB_BRANCH_NO;
		CS_CHAR  SUB_BRANCH_NAME[20];
		CS_INT   BUILD_NO;
		CS_CHAR  BUILD_NAME[20];
		CS_INT   LINE_TEST_NO;
		CS_CHAR  LINE_TEST_NAME[20];
	}ORGAN_VIEW;
	
	typedef	struct _ORGAN
	{
		CS_INT   ORG_ID;
		CS_CHAR  ORG_NAME[20];
		CS_INT   ORG_PARENTID;
		CS_CHAR  ORG_TYPEID[6];
	}ORGAN;
	
	typedef	struct _STATIC_DATA
	{
		CS_CHAR   DICT_ID[20];
		CS_CHAR   DICT_CODE[20];
		CS_CHAR   DICT_NAME[40];
	}STATIC_DATA;
	
	typedef struct _ORGAN_STRUCT
	{
		CS_CHAR  DISTRICT_NO[10];
		CS_CHAR  DISTIRCT_NAME[20];
		CS_CHAR  BRANCH_NO[10];
		CS_CHAR  BRANCH_NAME[20];
		CS_CHAR  SUB_BRANCH_NO[10];
		CS_CHAR  SUB_BRANCH_NAME[20];
		CS_CHAR  BUILD_NO[10];
		CS_CHAR  BUILD_NAME[20];
		CS_CHAR  LINE_TEST_NO[10];
		CS_CHAR  LINE_TEST_NAME[20];
	}ORGAN_STRUCT;
	
	typedef	struct _DATA_INFO
	{
		CS_INT   EXCHANGE_ID;
		CS_CHAR  DISTRICT_NO[10];
		CS_CHAR  DISTIRCT_NAME[20];
		CS_CHAR  BRANCH_NO[10];
		CS_CHAR  BRANCH_NAME[20];
		CS_CHAR  SUB_BRANCH_NO[10];
		CS_CHAR  SUB_BRANCH_NAME[20];
		CS_CHAR  BUILD_NO[10];
		CS_CHAR  BUILD_NAME[20];
		CS_CHAR  LINE_TEST_NO[10];
		CS_CHAR  LINE_TEST_NAME[20];
		CS_CHAR  SERV_NBR[30];
		CS_CHAR  PROD_ID[20];
		CS_CHAR  PROD_NAME[20];
		CS_CHAR  CUST_NAME[160];
		CS_CHAR  CUST_ADDRESS[160];
		CS_CHAR  CUST_NBR[30];
		CS_CHAR  CUST_PROP[20];
		CS_CHAR  CUST_TYPE[5];
		CS_CHAR  CUST_TYPE_DESC[20];
		CS_CHAR  CUST_CLASS_DL[30];
		CS_CHAR  CUST_CLASS_XL[40];
		CS_CHAR  CERT_TYPE[40];
		CS_CHAR  CERT_ID[80];
		CS_CHAR  RELA_MAN[80];
		CS_CHAR  RELA_PHONE[40];
		CS_CHAR  CUST_MANAGER_ID[10];
		CS_CHAR  CUST_MANAGER_NAME[60];
		CS_CHAR  SYSTEM_NBR[60];
		CS_CHAR  LINE_BOX_NBR[60];
		CS_CHAR  CROSS_BOX_NBR[60];
		CS_CHAR  BLACK_AREA[30];
		CS_CHAR  NOTES[100];
	}DATA_INFO;
	
	static ORGAN_VIEW* organview;
	static ORGAN* organ;
	static STATIC_DATA* staticdata;
	
	static ORGAN_VIEW* InitialOrganView()
	{
		EXEC SQL DECLARE oraganview CURSOR FOR 
		SELECT DISTRICT_NO,DISTIRCT_NAME,BRANCH_NO1,BRANCH_NAME1,BRANCH_NO2,BRANCH_NAME2, 
		BUILD_NO,BUILD_NAME,LINE_TEST_NO,LINE_TEST_NAME FROM ORGAN_VIEW;
		
		EXEC SQL OPEN oraganview;
		
		ORGAN_VIEW* pORGAN_VIEW = (ORGAN_VIEW*)malloc(sizeof(ORGAN_VIEW)*ORGAN_VIEW_SIZE);

		for (int i=0;i<ORGAN_VIEW_SIZE;i++)
		{
			EXEC SQL FETCH oraganview INTO 
				:pORGAN_VIEW[i]->DISTRICT_NO,:pORGAN_VIEW[i]->DISTIRCT_NAME,
				:pORGAN_VIEW[i]->BRANCH_NO,:pORGAN_VIEW[i]->BRANCH_NAME,
				:pORGAN_VIEW[i]->SUB_BRANCH_NO,:pORGAN_VIEW[i]->SUB_BRANCH_NAME,
				:pORGAN_VIEW[i]->BUILD_NO,:pORGAN_VIEW[i]->BUILD_NAME,
				:pORGAN_VIEW[i]->LINE_TEST_NO,:pORGAN_VIEW[i]->LINE_TEST_NAME;
			if (sqlca.sqlcode == 100)
				break;
		}
		EXEC SQL CLOSE oraganview;

		return pORGAN_VIEW;
	}
	
	static ORGAN* InitialOrgan()
	{
		EXEC SQL DECLARE oragan CURSOR FOR 
		SELECT ORG_ID,ORG_NAME,ORG_PARENTID,ORG_TYPEID FROM ORGAN_VIEW 
		WHERE ORG_TYPEID IN('OT0011','OT0005','OT0004','OT0003','OT0012','OT0001');
		
		EXEC SQL OPEN oragan;
		
		ORGAN* pORGAN = (ORGAN*)malloc(sizeof(ORGAN)*ORGAN_SIZE);

		for (int i=0;i<ORGAN_SIZE;i++)
		{
			EXEC SQL FETCH oragan INTO 
				:pORGAN[i]->ORG_ID,:pORGAN[i]->ORG_NAME,
				:pORGAN[i]->ORG_PARENTID,:pORGAN[i]->ORG_TYPEID;
			if (sqlca.sqlcode == 100)
				break;
		}
		EXEC SQL CLOSE oragan;

		return pORGAN;
	}
	
	static STATIC_DATA* InitialStaticData()
	{
		EXEC SQL DECLARE staticdata CURSOR FOR 
		SELECT DICT_ID,DICT_CODE,DICT_NAME FROM STATIC_DATA 
		WHERE IDICT_ID IN ('PROD_ID','CUST_PROP','CUST_TYPE','CUST_CLASS_DL','CUST_CLASS_XL','CERT_TYPE') 
		AND ISNULL(ENABLE,'0')!='0' ORDER BY DICT_ID,DICT_CODE;
		
		EXEC SQL OPEN staticdata;
		
		STATIC_DATA* pSTATIC_DATA = (STATIC_DATA*)malloc(sizeof(STATIC_DATA)*STATIC_DATA_SIZE);

		for (int i=0;i<STATIC_DATA_SIZE;i++)
		{
			EXEC SQL FETCH staticdata INTO 
				:pSTATIC_DATA[i]->DICT_ID,:pSTATIC_DATA[i]->DICT_CODE,
				:pSTATIC_DATA[i]->DICT_NAME,:pSTATIC_DATA[i]->ORG_TYPEID;
			if (sqlca.sqlcode == 100)
				break;
		}
		EXEC SQL CLOSE staticdata;

		return pSTATIC_DATA;
	}
	
	void InitialDataInfo(DATA_INFO& datainfo)
	{
		datainfo->EXCHANGE_ID         =0;
		datainfo->DISTRICT_NO[0]      ='\0';
		datainfo->DISTIRCT_NAME[0]    ='\0';
		datainfo->BRANCH_NO[0]        ='\0';
		datainfo->BRANCH_NAME[0]      ='\0';
		datainfo->SUB_BRANCH_NO[0]    ='\0';
		datainfo->SUB_BRANCH_NAME[0]  ='\0';
		datainfo->BUILD_NO[0]         ='\0';
		datainfo->BUILD_NAME[0]       ='\0';
		datainfo->LINE_TEST_NO[0]     ='\0';
		datainfo->LINE_TEST_NAME[0]   ='\0';
		datainfo->SERV_NBR[0]         ='\0';
		datainfo->PROD_ID[0]          ='\0';
		datainfo->PROD_NAME[0]        ='\0';
		datainfo->CUST_NAME[0]        ='\0';
		datainfo->CUST_ADDRESS[0]     ='\0';
		datainfo->CUST_NBR[0]         ='\0';
		datainfo->CUST_PROP[0]        ='\0';
		datainfo->CUST_TYPE[0]        ='\0';
		datainfo->CUST_TYPE_DESC[0]   ='\0';
		datainfo->CUST_CLASS_DL[0]    ='\0';
		datainfo->CUST_CLASS_XL[0]    ='\0';
		datainfo->CERT_TYPE[0]        ='\0';
		datainfo->CERT_ID[0]          ='\0';
		datainfo->RELA_MAN[0]         ='\0';
		datainfo->RELA_PHONE[0]       ='\0';
		datainfo->CUST_MANAGER_ID[0]  ='\0';
		datainfo->CUST_MANAGER_NAME[0]='\0';
		datainfo->SYSTEM_NBR[0]       ='\0';
		datainfo->LINE_BOX_NBR[0]     ='\0';
		datainfo->CROSS_BOX_NBR[0]    ='\0';
		datainfo->BLACK_AREA[0]       ='\0';
		datainfo->NOTES[0]            ='\0';
	}
	
	static ORGAN_STRUCT MatchOrgan(CS_INT iEXCHANGE_ID)
	{
		ORGAN_STRUCT organstruct;
		if(iEXCHANGE_ID==91001)
		{
			strcpy(organstruct.DISTRICT_NO,"1");
			strcpy(organstruct.DISTIRCT_NAME,"广州本地网中心局");
			strcpy(organstruct.BRANCH_NO,"91001");
			strcpy(organstruct.BRANCH_NAME,"PHS分局");
			strcpy(organstruct.SUB_BRANCH_NO,"");
			strcpy(organstruct.SUB_BRANCH_NAME,"");
			strcpy(organstruct.BUILD_NO,"3");
			strcpy(organstruct.BUILD_NAME,"GZPHS机楼");
			strcpy(organstruct.LINE_TEST_NO,"4");
			strcpy(organstruct.LINE_TEST_NAME,"GZPHS测量");
			return organstruct;
		}
		for(int i=0;i<ORGAN_VIEW_SIZE;i++)
		{
			if(organview[i]->LINE_TEST_NO==iEXCHANGE_ID)
			{
				sprintf(organstruct.LINE_TEST_NO,"%d",organview[i]->LINE_TEST_NO);
				sprintf(organstruct.BUILD_NO,"%d",organview[i]->BUILD_NO);
				sprintf(organstruct.SUB_BRANCH_NO,"%d",organview[i]->SUB_BRANCH_NO);
				sprintf(organstruct.BRANCH_NO,"%d",organview[i]->BRANCH_NO);
				sprintf(organstruct.DISTRICT_NO,"%d",organview[i]->DISTRICT_NO);
				strcpy(organstruct.LINE_TEST_NAME,organview[i]->LINE_TEST_NAME);
				strcpy(organstruct.BUILD_NAME,organview[i]->BUILD_NAME);
				strcpy(organstruct.SUB_BRANCH_NAME,organview[i]->SUB_BRANCH_NAME);
				strcpy(organstruct.BRANCH_NAME,organview[i]->BRANCH_NAME);
				strcpy(organstruct.DISTIRCT_NAME,organview[i]->DISTIRCT_NAME);
				return organstruct;
			}
		}
		int iLoop = 0;
		bool bLoop = true;
		CS_INT   iORG_ID;
		CS_CHAR  szORG_NAME[20];
		CS_INT   iORG_PARENTID=iEXCHANGE_ID;
		CS_CHAR  szORG_TYPEID[6];
		while(bLoop)
		{
			iLoop++;
			if( iLoop > 5 )
			{
				bLoop = false;
				break;
			}
			iORG_ID=0;
			szORG_NAME[0]='\0';
			szORG_TYPEID[0]='\0';
			for(int j=0;j<ORGAN_SIZE;j++)
			{
				if(organ[j]->ORG_ID==iORG_PARENTID)
				{
					iORG_ID      =organ[j]->ORG_ID;
					strcpy(szORG_NAME,organ[j]->ORG_NAME);
					iORG_PARENTID=organ[j]->ORG_PARENTID;
					strcpy(szORG_TYPEID,organ[j]->ORG_TYPEID);
					break;
				}
			}
			if(strcmp(szORG_TYPEID,"OT0011")==0)
			{
				sprintf(organstruct.LINE_TEST_NO,"%d",iORG_ID);
				strcpy(organstruct.LINE_TEST_NAME,szORG_NAME);
			}
			else if(strcmp(szORG_TYPEID,"OT0005")==0)
			{
				sprintf(organstruct.BUILD_NO,"%d",iORG_ID);
				strcpy(organstruct.BUILD_NAME,szORG_NAME);
			}
			else if(strcmp(szORG_TYPEID,"OT0004")==0)
			{
				sprintf(organstruct.SUB_BRANCH_NO,"%d",iORG_ID);
				strcpy(organstruct.SUB_BRANCH_NAME,szORG_NAME);
			}
			else if(strcmp(szORG_TYPEID,"OT0003")==0)
			{
				sprintf(organstruct.BRANCH_NO,"%d",iORG_ID);
				strcpy(organstruct.BUILD_NAME,szORG_NAME);
			}
			else if(strcmp(szORG_TYPEID,"OT0012")==0)
			{
				sprintf(organstruct.DISTRICT_NO,"%d",iORG_ID);
				strcpy(organstruct.DISTIRCT_NAME,szORG_NAME);
			}
			else if(strcmp(szORG_TYPEID,"OT0001")==0 ||iORG_PARENTID==1)	//顶级
			{
				bLoop = false;
				break;
			}
		}
		return organstruct;
	}
	
	static CS_CHAR* GetStaticValue(CS_CHAR* szSTATIC_CODE,char* szSTATIC_TYPE)
	{
		for(int i=0;i<STATIC_DATA_SIZE;i++)
		{
			if(strcmp(staticdata[i]->DICT_ID,szSTATIC_TYPE)!=0)
			{
				continue;
			}
			if(strcmp(staticdata[i]->DICT_CODE,szSTATIC_CODE)==0)
				return staticdata[i]->DICT_NAME;
		}
		return null;
	}