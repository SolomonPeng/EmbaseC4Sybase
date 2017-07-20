
/*
** Generated code begins here.
*/
# line 1 "example1.cp"

/*
** This file was generated on Tue May 15 16:24:32 2007
**  by Sybase Embedded SQL Preprocessor Sybase ESQL/C Precompiler/12.5/P/SPARC/
** Solaris 2.8/BUILD125-005/64bit/OPT/Sat May 19 07:50:03 2001
*/
# line 1 "example1.cp"
# line 1 "example1.cp"
#define _SQL_SCOPE extern
# line 1 "example1.cp"
#include <sybhesql.h>

/*
** Generated code ends here.
*/
# line 1 "example1.cp"
/*
**    example1.cp
**
**	This example is an interactive query program that 
**	guides the user through a series of prompts to select
**	a title from the titles table in the pubs2 database.
**	It uses cursors extensively to guide the query.
*/
#include <stdio.h>
#include "sybsqlex.h"

/* Declare the SQLCA. */

/*
** SQL STATEMENT: 1
** EXEC SQL INCLUDE SQLCA;

*/
# line 13 "example1.cp"
# line 13 "example1.cp"
SQLCA sqlca;

/*
** Generated code ends here.
*/
# line 13 "example1.cp"


/* 
** These tokens must be declared in a declare section
** because they are used in declare sections below.
*/

/*
** SQL STATEMENT: 1
** EXEC SQL BEGIN DECLARE SECTION;

*/
# line 19 "example1.cp"

#define TYPESIZE 	13
#define	TIDSIZE 	6

/*
** SQL STATEMENT: 2
** EXEC SQL END DECLARE SECTION;

*/
# line 22 "example1.cp"

/*
** Generated code ends here.
*/
# line 22 "example1.cp"


#define  EOLN	'\0'

/* 
** Forward declarations of the error and message handlers and
** other subroutines called from main().
*/
void	error_handler();
void	warning_handler();
int	get_type();
int	get_titleid();
void	show_book();

#define ISWORDSPACE(c) (c == ' ' || c == '\t')

void main()
{
	
           /*
           ** SQL STATEMENT: 2
           ** EXEC SQL BEGIN DECLARE SECTION;

           */
# line 40 "example1.cp"

	/* storage for login name and password. */
	char	username[30];
	char	password[30];
	
           /*
           ** SQL STATEMENT: 3
           ** EXEC SQL END DECLARE SECTION;

           */
# line 44 "example1.cp"

           /*
           ** Generated code ends here.
           */
# line 44 "example1.cp"


	char	u_type[TYPESIZE+1];
	char	u_titleid[TIDSIZE+1];

	
           /*
           ** SQL STATEMENT: 4
           ** EXEC SQL WHENEVER SQLERROR CALL error_handler();
           */
# line 49 "example1.cp"

	
           /*
           ** SQL STATEMENT: 5
           ** EXEC SQL WHENEVER SQLWARNING CALL warning_handler();
           */
# line 50 "example1.cp"

	
           /*
           ** SQL STATEMENT: 6
           ** EXEC SQL WHENEVER NOT FOUND CONTINUE;

           */
# line 51 "example1.cp"


	/* 
	** Copy the user name and password defined in sybsqlex.h to
	** the variables declared for them in the declare section. 
	*/
	strcpy(username, USER);
	strcpy(password, PASSWORD);

	
           /*
           ** SQL STATEMENT: 7
           ** EXEC SQL CONNECT :username IDENTIFIED BY :password;
           */
# line 60 "example1.cp"
# line 60 "example1.cp"
           {
# line 60 "example1.cp"
                _SQL_CT_HANDLES * _sql;
# line 60 "example1.cp"
               _sqlinitctx(&_sql, CS_VERSION_125, CS_TRUE, &sqlca, (long 
# line 60 "example1.cp"
                   *)NULL, (CS_CHAR *)NULL);
# line 60 "example1.cp"
               if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 60 "example1.cp"
               {
# line 60 "example1.cp"
                   _sql->stmtData.persistent = CS_FALSE;
# line 60 "example1.cp"
                   _sql->stmttype = SQL_NONANSI_CONNECT;
# line 60 "example1.cp"
                   _sql->connName.lnlen = 7;
# line 60 "example1.cp"
                   strcpy(_sql->connName.last_name, "DEFAULT");
# line 60 "example1.cp"
                   if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 60 "example1.cp"
                   {
# line 60 "example1.cp"
                       if (_sql->doDecl == CS_TRUE)
# line 60 "example1.cp"
                       {
# line 60 "example1.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 60 "example1.cp"
                           {
# line 60 "example1.cp"
                               _sql->retcode = 
# line 60 "example1.cp"
                                   ct_con_props(_sql->conn.connection, CS_SET, 
# line 60 "example1.cp"
                                   CS_USERNAME, username, CS_NULLTERM, NULL);
# line 60 "example1.cp"
                           }
# line 60 "example1.cp"
                           
# line 60 "example1.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 60 "example1.cp"
                           {
# line 60 "example1.cp"
                               _sql->retcode = 
# line 60 "example1.cp"
                                   ct_con_props(_sql->conn.connection, CS_SET, 
# line 60 "example1.cp"
                                   CS_PASSWORD, password, CS_NULLTERM, NULL);
# line 60 "example1.cp"
                           }
# line 60 "example1.cp"
                           
# line 60 "example1.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 60 "example1.cp"
                           {
# line 60 "example1.cp"
                               _sql->retcode = _sqlctdiag(_sql, CS_CLEAR, 
# line 60 "example1.cp"
                                   CS_UNUSED);
# line 60 "example1.cp"
                           }
# line 60 "example1.cp"
                           
# line 60 "example1.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 60 "example1.cp"
                           {
# line 60 "example1.cp"
                               _sql->retcode = 
# line 60 "example1.cp"
                                   ct_capability(_sql->conn.connection, CS_SET,
# line 60 "example1.cp"
                                    CS_CAP_RESPONSE, CS_RES_NOSTRIPBLANKS, 
# line 60 "example1.cp"
                                   &_sql->cstrue);
# line 60 "example1.cp"
                           }
# line 60 "example1.cp"
                           
# line 60 "example1.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 60 "example1.cp"
                           {
# line 60 "example1.cp"
                               _sql->retcode = 
# line 60 "example1.cp"
                                   ct_con_props(_sql->conn.connection, CS_SET, 
# line 60 "example1.cp"
                                   CS_EXTRA_INF, &_sql->cstrue, CS_UNUSED, 
# line 60 "example1.cp"
                                   NULL);
# line 60 "example1.cp"
                           }
# line 60 "example1.cp"
                           
# line 60 "example1.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 60 "example1.cp"
                           {
# line 60 "example1.cp"
                               _sql->retcode = 
# line 60 "example1.cp"
                                   ct_con_props(_sql->conn.connection, CS_SET, 
# line 60 "example1.cp"
                                   CS_ANSI_BINDS, &_sql->cstrue, CS_UNUSED, 
# line 60 "example1.cp"
                                   NULL);
# line 60 "example1.cp"
                           }
# line 60 "example1.cp"
                           
# line 60 "example1.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 60 "example1.cp"
                           {
# line 60 "example1.cp"
                               _sql->retcode = 
# line 60 "example1.cp"
                                   ct_connect(_sql->conn.connection, NULL, 0);
# line 60 "example1.cp"
                           }
# line 60 "example1.cp"
                           
# line 60 "example1.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 60 "example1.cp"
                           {
# line 60 "example1.cp"
                               _sql->retcode = 
# line 60 "example1.cp"
                                   ct_con_props(_sql->conn.connection, CS_GET, 
# line 60 "example1.cp"
                                   CS_TDS_VERSION, &_sql->temp_int, CS_UNUSED, 
# line 60 "example1.cp"
                                   &_sql->outlen);
# line 60 "example1.cp"
                               if (_sql->retcode == CS_SUCCEED)
# line 60 "example1.cp"
                               {
# line 60 "example1.cp"
                                   if (_sql->temp_int < CS_TDS_50)
# line 60 "example1.cp"
                                   {
# line 60 "example1.cp"
                                       _sqlsetintrerr(_sql, (CS_INT) 
# line 60 "example1.cp"
                                           _SQL_INTRERR_25013);
# line 60 "example1.cp"
                                   }
# line 60 "example1.cp"
                                   
# line 60 "example1.cp"
                               }
# line 60 "example1.cp"
                               
# line 60 "example1.cp"
                           }
# line 60 "example1.cp"
                           
# line 60 "example1.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 60 "example1.cp"
                           {
# line 60 "example1.cp"
                               _sql->retcode = 
# line 60 "example1.cp"
                                   ct_options(_sql->conn.connection, CS_SET, 
# line 60 "example1.cp"
                                   CS_OPT_ANSINULL, &_sql->cstrue, CS_UNUSED, 
# line 60 "example1.cp"
                                   NULL);
# line 60 "example1.cp"
                           }
# line 60 "example1.cp"
                           
# line 60 "example1.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 60 "example1.cp"
                           {
# line 60 "example1.cp"
                               _sql->retcode = 
# line 60 "example1.cp"
                                   ct_options(_sql->conn.connection, CS_SET, 
# line 60 "example1.cp"
                                   CS_OPT_ANSIPERM, &_sql->cstrue, CS_UNUSED, 
# line 60 "example1.cp"
                                   NULL);
# line 60 "example1.cp"
                               _sql->retcode = CS_SUCCEED;
# line 60 "example1.cp"
                           }
# line 60 "example1.cp"
                           
# line 60 "example1.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 60 "example1.cp"
                           {
# line 60 "example1.cp"
                               _sql->retcode = 
# line 60 "example1.cp"
                                   ct_options(_sql->conn.connection, CS_SET, 
# line 60 "example1.cp"
                                   CS_OPT_STR_RTRUNC, &_sql->cstrue, CS_UNUSED,
# line 60 "example1.cp"
                                    NULL);
# line 60 "example1.cp"
                               _sql->retcode = CS_SUCCEED;
# line 60 "example1.cp"
                           }
# line 60 "example1.cp"
                           
# line 60 "example1.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 60 "example1.cp"
                           {
# line 60 "example1.cp"
                               _sql->retcode = 
# line 60 "example1.cp"
                                   ct_options(_sql->conn.connection, CS_SET, 
# line 60 "example1.cp"
                                   CS_OPT_ARITHABORT, &_sql->csfalse, 
# line 60 "example1.cp"
                                   CS_UNUSED, NULL);
# line 60 "example1.cp"
                           }
# line 60 "example1.cp"
                           
# line 60 "example1.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 60 "example1.cp"
                           {
# line 60 "example1.cp"
                               _sql->retcode = 
# line 60 "example1.cp"
                                   ct_options(_sql->conn.connection, CS_SET, 
# line 60 "example1.cp"
                                   CS_OPT_TRUNCIGNORE, &_sql->cstrue, 
# line 60 "example1.cp"
                                   CS_UNUSED, NULL);
# line 60 "example1.cp"
                           }
# line 60 "example1.cp"
                           
# line 60 "example1.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 60 "example1.cp"
                           {
# line 60 "example1.cp"
                               _sql->retcode = 
# line 60 "example1.cp"
                                   ct_options(_sql->conn.connection, CS_SET, 
# line 60 "example1.cp"
                                   CS_OPT_ARITHIGNORE, &_sql->csfalse, 
# line 60 "example1.cp"
                                   CS_UNUSED, NULL);
# line 60 "example1.cp"
                           }
# line 60 "example1.cp"
                           
# line 60 "example1.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 60 "example1.cp"
                           {
# line 60 "example1.cp"
                               _sql->retcode = 
# line 60 "example1.cp"
                                   ct_options(_sql->conn.connection, CS_SET, 
# line 60 "example1.cp"
                                   CS_OPT_ISOLATION, &_sql->Level3, CS_UNUSED, 
# line 60 "example1.cp"
                                   NULL);
# line 60 "example1.cp"
                           }
# line 60 "example1.cp"
                           
# line 60 "example1.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 60 "example1.cp"
                           {
# line 60 "example1.cp"
                               _sql->retcode = 
# line 60 "example1.cp"
                                   ct_options(_sql->conn.connection, CS_SET, 
# line 60 "example1.cp"
                                   CS_OPT_CHAINXACTS, &_sql->cstrue, CS_UNUSED,
# line 60 "example1.cp"
                                    NULL);
# line 60 "example1.cp"
                           }
# line 60 "example1.cp"
                           
# line 60 "example1.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 60 "example1.cp"
                           {
# line 60 "example1.cp"
                               _sql->retcode = 
# line 60 "example1.cp"
                                   ct_options(_sql->conn.connection, CS_SET, 
# line 60 "example1.cp"
                                   CS_OPT_CURCLOSEONXACT, &_sql->cstrue, 
# line 60 "example1.cp"
                                   CS_UNUSED, NULL);
# line 60 "example1.cp"
                           }
# line 60 "example1.cp"
                           
# line 60 "example1.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 60 "example1.cp"
                           {
# line 60 "example1.cp"
                               _sql->retcode = 
# line 60 "example1.cp"
                                   ct_options(_sql->conn.connection, CS_SET, 
# line 60 "example1.cp"
                                   CS_OPT_QUOTED_IDENT, &_sql->cstrue, 
# line 60 "example1.cp"
                                   CS_UNUSED, NULL);
# line 60 "example1.cp"
                           }
# line 60 "example1.cp"
                           
# line 60 "example1.cp"
                           _sql->retcode = _sqlepilog(_sql);
# line 60 "example1.cp"
                       }
# line 60 "example1.cp"
                       
# line 60 "example1.cp"
                   }
# line 60 "example1.cp"
                   
# line 60 "example1.cp"
                   if (sqlca.sqlcode < 0)
# line 60 "example1.cp"
                   {
# line 60 "example1.cp"
                       error_handler();
# line 60 "example1.cp"
                   }
# line 60 "example1.cp"
                   
# line 60 "example1.cp"
                   if (sqlca.sqlwarn[0] == 'W')
# line 60 "example1.cp"
                   {
# line 60 "example1.cp"
                       warning_handler();
# line 60 "example1.cp"
                   }
# line 60 "example1.cp"
                   
# line 60 "example1.cp"
               }
# line 60 "example1.cp"
               
# line 60 "example1.cp"
           }
# line 60 "example1.cp"
           

           /*
           ** Generated code ends here.
           */
# line 60 "example1.cp"


	
           /*
           ** SQL STATEMENT: 8
           ** EXEC SQL USE pubs2;

           */
# line 62 "example1.cp"
# line 62 "example1.cp"
           {
# line 62 "example1.cp"
                _SQL_CT_HANDLES * _sql;
# line 62 "example1.cp"
               _sqlinitctx(&_sql, CS_VERSION_125, CS_TRUE, &sqlca, (long 
# line 62 "example1.cp"
                   *)NULL, (CS_CHAR *)NULL);
# line 62 "example1.cp"
               if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 62 "example1.cp"
               {
# line 62 "example1.cp"
                   _sql->stmtIdlen = CS_UNUSED;
# line 62 "example1.cp"
                   _sql->stmtData.persistent = CS_FALSE;
# line 62 "example1.cp"
                   _sql->stmttype = SQL_MISC;
# line 62 "example1.cp"
                   _sql->connName.lnlen = CS_UNUSED;
# line 62 "example1.cp"
                   if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 62 "example1.cp"
                   {
# line 62 "example1.cp"
                       _sql->retcode = ct_command(_sql->conn.command, 
# line 62 "example1.cp"
                           CS_LANG_CMD, "USE pubs2", 9, CS_UNUSED);
# line 62 "example1.cp"
                       _sql->retcode = ct_send(_sql->conn.command);
# line 62 "example1.cp"
                       _sql->retcode = _sqlResults(_sql);
# line 62 "example1.cp"
                       _sql->retcode = _sqlepilog(_sql);
# line 62 "example1.cp"
                   }
# line 62 "example1.cp"
                   
# line 62 "example1.cp"
                   if (sqlca.sqlcode < 0)
# line 62 "example1.cp"
                   {
# line 62 "example1.cp"
                       error_handler();
# line 62 "example1.cp"
                   }
# line 62 "example1.cp"
                   
# line 62 "example1.cp"
                   if (sqlca.sqlwarn[0] == 'W')
# line 62 "example1.cp"
                   {
# line 62 "example1.cp"
                       warning_handler();
# line 62 "example1.cp"
                   }
# line 62 "example1.cp"
                   
# line 62 "example1.cp"
               }
# line 62 "example1.cp"
               
# line 62 "example1.cp"
           }
# line 62 "example1.cp"
           

           /*
           ** Generated code ends here.
           */
# line 62 "example1.cp"


	/*
	** This loop controls the query.
	*/
	while (get_type(u_type))
	{
		while (get_titleid(u_titleid, u_type))
		{
			show_book(u_titleid);
		}
	}

	
           /*
           ** SQL STATEMENT: 9
           ** EXEC SQL DISCONNECT DEFAULT;

           */
# line 75 "example1.cp"
# line 75 "example1.cp"
           {
# line 75 "example1.cp"
                _SQL_CT_HANDLES * _sql;
# line 75 "example1.cp"
               _sqlinitctx(&_sql, CS_VERSION_125, CS_TRUE, &sqlca, (long 
# line 75 "example1.cp"
                   *)NULL, (CS_CHAR *)NULL);
# line 75 "example1.cp"
               if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 75 "example1.cp"
               {
# line 75 "example1.cp"
                   _sql->stmtData.persistent = CS_FALSE;
# line 75 "example1.cp"
                   _sql->stmttype = SQL_DISCONNECT;
# line 75 "example1.cp"
                   _sql->connName.lnlen = 7;
# line 75 "example1.cp"
                   strcpy(_sql->connName.last_name, "DEFAULT");
# line 75 "example1.cp"
                   if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 75 "example1.cp"
                   {
# line 75 "example1.cp"
                       _sql->retcode = _sqlepilog(_sql);
# line 75 "example1.cp"
                   }
# line 75 "example1.cp"
                   
# line 75 "example1.cp"
                   if (sqlca.sqlcode < 0)
# line 75 "example1.cp"
                   {
# line 75 "example1.cp"
                       error_handler();
# line 75 "example1.cp"
                   }
# line 75 "example1.cp"
                   
# line 75 "example1.cp"
                   if (sqlca.sqlwarn[0] == 'W')
# line 75 "example1.cp"
                   {
# line 75 "example1.cp"
                       warning_handler();
# line 75 "example1.cp"
                   }
# line 75 "example1.cp"
                   
# line 75 "example1.cp"
               }
# line 75 "example1.cp"
               
# line 75 "example1.cp"
           }
# line 75 "example1.cp"
           

           /*
           ** Generated code ends here.
           */
# line 75 "example1.cp"


	exit (STDEXIT);

}

/*
** int get_type(type) 
**
**	Displays a list of book types from the titles
**	table and lets the user enter one. 
*/
int get_type(type)
char *type;
{
	/* 
	** Declare a character string to hold types fetched
	** from the titles table.
	*/ 
	
           /*
           ** SQL STATEMENT: 9
           ** EXEC SQL BEGIN DECLARE SECTION;

           */
# line 94 "example1.cp"

	char	a_type[TYPESIZE+1];
	
           /*
           ** SQL STATEMENT: 10
           ** EXEC SQL END DECLARE SECTION;

           */
# line 96 "example1.cp"

           /*
           ** Generated code ends here.
           */
# line 96 "example1.cp"


	/* A buffer to hold user's gets() entry. */
	char	buf[128];

	/* Declare a cursor to select a list of book types. */
	
           /*
           ** SQL STATEMENT: 11
           ** EXEC SQL DECLARE typelist CURSOR FOR
           ** 	SELECT DISTINCT type FROM titles;

           */
# line 103 "example1.cp"


	/* Open the cursor. */
	
           /*
           ** SQL STATEMENT: 12
           ** EXEC SQL OPEN typelist;

           */
# line 106 "example1.cp"
# line 106 "example1.cp"
           {
# line 106 "example1.cp"
                _SQL_CT_HANDLES * _sql;
# line 106 "example1.cp"
               _sqlinitctx(&_sql, CS_VERSION_125, CS_TRUE, &sqlca, (long 
# line 106 "example1.cp"
                   *)NULL, (CS_CHAR *)NULL);
# line 106 "example1.cp"
               if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 106 "example1.cp"
               {
# line 106 "example1.cp"
                   _sql->stmtData.persistent = CS_FALSE;
# line 106 "example1.cp"
                   _sql->moreData.curData.norebind = CS_FALSE;
# line 106 "example1.cp"
                   _sql->stmttype = SQL_OPEN_STMT;
# line 106 "example1.cp"
                   _sql->connName.lnlen = CS_UNUSED;
# line 106 "example1.cp"
                   _sql->curName.fnlen = 8;
# line 106 "example1.cp"
                   strcpy(_sql->curName.first_name, "typelist");
# line 106 "example1.cp"
                   if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 106 "example1.cp"
                   {
# line 106 "example1.cp"
                       if (_sql->doDecl == CS_TRUE)
# line 106 "example1.cp"
                       {
# line 106 "example1.cp"
                           _sql->retcode = ct_cursor(_sql->conn.command, 
# line 106 "example1.cp"
                               CS_CURSOR_DECLARE, "typelist", 8, "SELECT DISTIN"
"CT type FROM titles", 32, CS_UNUSED);
# line 106 "example1.cp"
                       }
# line 106 "example1.cp"
                       
# line 106 "example1.cp"
                       if (_sql->retcode == CS_SUCCEED)
# line 106 "example1.cp"
                       {
# line 106 "example1.cp"
                           if (_sql->stmtData.persistent == CS_TRUE)
# line 106 "example1.cp"
                           {
# line 106 "example1.cp"
                               _sql->retcode = ct_cursor(_sql->conn.command, 
# line 106 "example1.cp"
                                   CS_CURSOR_OPEN, NULL, CS_UNUSED, NULL, 
# line 106 "example1.cp"
                                   CS_UNUSED, CS_RESTORE_OPEN);
# line 106 "example1.cp"
                               }
# line 106 "example1.cp"
                                else {
# line 106 "example1.cp"
                               _sql->retcode = ct_cursor(_sql->conn.command, 
# line 106 "example1.cp"
                                   CS_CURSOR_OPEN, NULL, CS_UNUSED, NULL, 
# line 106 "example1.cp"
                                   CS_UNUSED, CS_UNUSED);
# line 106 "example1.cp"
                           }
# line 106 "example1.cp"
                           
# line 106 "example1.cp"
                       }
# line 106 "example1.cp"
                       
# line 106 "example1.cp"
                       if (_sql->retcode == CS_SUCCEED)
# line 106 "example1.cp"
                       {
# line 106 "example1.cp"
                           _sql->retcode = ct_send(_sql->conn.command);
# line 106 "example1.cp"
                       }
# line 106 "example1.cp"
                       
# line 106 "example1.cp"
                       _sql->resloop = CS_TRUE;
# line 106 "example1.cp"
                       while ((_sql->resloop == CS_TRUE) && (_sql->retcode = 
# line 106 "example1.cp"
                           ct_results(_sql->conn.command, &_sql->restype)) == 
# line 106 "example1.cp"
                       CS_SUCCEED)
# line 106 "example1.cp"
                       {
# line 106 "example1.cp"
                           switch ( _sql->restype )
# line 106 "example1.cp"
                           {
# line 106 "example1.cp"
                           case CS_COMPUTE_RESULT:
# line 106 "example1.cp"
                               _sqlsetintrerr(_sql, (CS_INT) 
# line 106 "example1.cp"
                                   _SQL_INTRERR_25003);
# line 106 "example1.cp"
                               _sql->retcode = ct_cancel(NULL, 
# line 106 "example1.cp"
                                   _sql->conn.command, CS_CANCEL_CURRENT);
# line 106 "example1.cp"
                           break;
# line 106 "example1.cp"
                           case CS_CURSOR_RESULT:
# line 106 "example1.cp"
                               _sql->resloop = CS_FALSE;
# line 106 "example1.cp"
                           break;
# line 106 "example1.cp"
                           case CS_PARAM_RESULT:
# line 106 "example1.cp"
                               _sqlsetintrerr(_sql, (CS_INT) 
# line 106 "example1.cp"
                                   _SQL_INTRERR_25005);
# line 106 "example1.cp"
                               _sql->retcode = ct_cancel(NULL, 
# line 106 "example1.cp"
                                   _sql->conn.command, CS_CANCEL_CURRENT);
# line 106 "example1.cp"
                           break;
# line 106 "example1.cp"
                           case CS_ROW_RESULT:
# line 106 "example1.cp"
                               _sqlsetintrerr(_sql, (CS_INT) 
# line 106 "example1.cp"
                                   _SQL_INTRERR_25006);
# line 106 "example1.cp"
                               _sql->retcode = ct_cancel(NULL, 
# line 106 "example1.cp"
                                   _sql->conn.command, CS_CANCEL_CURRENT);
# line 106 "example1.cp"
                           break;
# line 106 "example1.cp"
                           case CS_STATUS_RESULT:
# line 106 "example1.cp"
                               _sqlsetintrerr(_sql, (CS_INT) 
# line 106 "example1.cp"
                                   _SQL_INTRERR_25009);
# line 106 "example1.cp"
                               _sql->retcode = ct_cancel(NULL, 
# line 106 "example1.cp"
                                   _sql->conn.command, CS_CANCEL_CURRENT);
# line 106 "example1.cp"
                           break;
# line 106 "example1.cp"
                           case CS_DESCRIBE_RESULT:
# line 106 "example1.cp"
                               _sqlsetintrerr(_sql, (CS_INT) 
# line 106 "example1.cp"
                                   _SQL_INTRERR_25010);
# line 106 "example1.cp"
                           break;
# line 106 "example1.cp"
                           }
# line 106 "example1.cp"
                           
# line 106 "example1.cp"
                       }
# line 106 "example1.cp"
                       
# line 106 "example1.cp"
                       _sql->retcode = _sqlepilog(_sql);
# line 106 "example1.cp"
                   }
# line 106 "example1.cp"
                   
# line 106 "example1.cp"
                   if (sqlca.sqlcode < 0)
# line 106 "example1.cp"
                   {
# line 106 "example1.cp"
                       error_handler();
# line 106 "example1.cp"
                   }
# line 106 "example1.cp"
                   
# line 106 "example1.cp"
                   if (sqlca.sqlwarn[0] == 'W')
# line 106 "example1.cp"
                   {
# line 106 "example1.cp"
                       warning_handler();
# line 106 "example1.cp"
                   }
# line 106 "example1.cp"
                   
# line 106 "example1.cp"
               }
# line 106 "example1.cp"
               
# line 106 "example1.cp"
           }
# line 106 "example1.cp"
           

           /*
           ** Generated code ends here.
           */
# line 106 "example1.cp"


	/*
	** List the book types on the screen. Break out of the
	** loop when a FETCH sets sqlca.sqlcode to 100.
	*/
	printf("\n\nSelect a Book Type:\n\n");
	for (;;)
	{
		
           /*
           ** SQL STATEMENT: 13
           ** EXEC SQL FETCH typelist INTO :a_type;
           */
# line 115 "example1.cp"
# line 115 "example1.cp"
           {
# line 115 "example1.cp"
                _SQL_CT_HANDLES * _sql;
# line 115 "example1.cp"
               _sqlinitctx(&_sql, CS_VERSION_125, CS_TRUE, &sqlca, (long 
# line 115 "example1.cp"
                   *)NULL, (CS_CHAR *)NULL);
# line 115 "example1.cp"
               if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 115 "example1.cp"
               {
# line 115 "example1.cp"
                   _sql->stmtData.persistent = CS_FALSE;
# line 115 "example1.cp"
                   _sql->stmttype = SQL_FETCH_STMT;
# line 115 "example1.cp"
                   _sql->connName.lnlen = CS_UNUSED;
# line 115 "example1.cp"
                   _sql->curName.fnlen = 8;
# line 115 "example1.cp"
                   strcpy(_sql->curName.first_name, "typelist");
# line 115 "example1.cp"
                   if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 115 "example1.cp"
                   {
# line 115 "example1.cp"
                       _sql->doDecl = CS_FALSE;
# line 115 "example1.cp"
                       if ((_sql->stmtData.bind == CS_TRUE) ||
# line 115 "example1.cp"
                       (_sql->moreData.curData.norebind == CS_FALSE))
# line 115 "example1.cp"
                       {
# line 115 "example1.cp"
                           _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 115 "example1.cp"
                           _sql->dfmtCS_CHAR_TYPE.format = (CS_FMT_NULLTERM | 
# line 115 "example1.cp"
                               CS_FMT_PADBLANK);
# line 115 "example1.cp"
                           _sql->dfmtCS_CHAR_TYPE.maxlength = TYPESIZE+1;
# line 115 "example1.cp"
                               _sql->retcode = ct_bind(_sql->conn.command, 1, 
# line 115 "example1.cp"
                                   &_sql->dfmtCS_CHAR_TYPE, a_type, NULL, 
# line 115 "example1.cp"
                                   NULL);
# line 115 "example1.cp"
                           if (_sql->stmtData.bind == CS_TRUE)
# line 115 "example1.cp"
                           {
# line 115 "example1.cp"
                               _sql->stmtData.bind = CS_FALSE;
# line 115 "example1.cp"
                               _sql->doDecl = CS_TRUE;
# line 115 "example1.cp"
                           }
# line 115 "example1.cp"
                           
# line 115 "example1.cp"
                       }
# line 115 "example1.cp"
                       
# line 115 "example1.cp"
                       _sql->retcode = ct_fetch(_sql->conn.command, CS_UNUSED, 
# line 115 "example1.cp"
                           CS_UNUSED, CS_UNUSED, &_sql->rowsread);
# line 115 "example1.cp"
                       if (_sql->retcode == CS_END_DATA)
# line 115 "example1.cp"
                       {
# line 115 "example1.cp"
                           _sql->retcode = _sqlResults(_sql);
# line 115 "example1.cp"
                       }
# line 115 "example1.cp"
                       
# line 115 "example1.cp"
                       _sql->retcode = _sqlepilog(_sql);
# line 115 "example1.cp"
                   }
# line 115 "example1.cp"
                   
# line 115 "example1.cp"
                   if (sqlca.sqlcode < 0)
# line 115 "example1.cp"
                   {
# line 115 "example1.cp"
                       error_handler();
# line 115 "example1.cp"
                   }
# line 115 "example1.cp"
                   
# line 115 "example1.cp"
                   if (sqlca.sqlwarn[0] == 'W')
# line 115 "example1.cp"
                   {
# line 115 "example1.cp"
                       warning_handler();
# line 115 "example1.cp"
                   }
# line 115 "example1.cp"
                   
# line 115 "example1.cp"
               }
# line 115 "example1.cp"
               
# line 115 "example1.cp"
           }
# line 115 "example1.cp"
           

           /*
           ** Generated code ends here.
           */
# line 115 "example1.cp"

		if (sqlca.sqlcode == 100)
			break;
		printf("\t%s\n", a_type);
	}
	/*
	** Prompt the user for the book type. We're using gets() 
	** for the input function. Since gets() doesn't check the 
	** length of entry, we have the user enter into a large 
	** temporary buffer, then copy the correct number of bytes
	** into the variable passed from main().
	*/
	printf("\nbook type? ");
	gets(buf);
	type[TYPESIZE] = EOLN;
	strncpy(type, buf, TYPESIZE);

	/*
	** Close the cursor and return the length of the type string.
	*/
	
           /*
           ** SQL STATEMENT: 14
           ** EXEC SQL CLOSE typelist;

           */
# line 135 "example1.cp"
# line 135 "example1.cp"
           {
# line 135 "example1.cp"
                _SQL_CT_HANDLES * _sql;
# line 135 "example1.cp"
               _sqlinitctx(&_sql, CS_VERSION_125, CS_TRUE, &sqlca, (long 
# line 135 "example1.cp"
                   *)NULL, (CS_CHAR *)NULL);
# line 135 "example1.cp"
               if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 135 "example1.cp"
               {
# line 135 "example1.cp"
                   _sql->stmtData.persistent = CS_FALSE;
# line 135 "example1.cp"
                   _sql->stmttype = SQL_CLOSE_STMT;
# line 135 "example1.cp"
                   _sql->connName.lnlen = CS_UNUSED;
# line 135 "example1.cp"
                   _sql->curName.fnlen = 8;
# line 135 "example1.cp"
                   strcpy(_sql->curName.first_name, "typelist");
# line 135 "example1.cp"
                   if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 135 "example1.cp"
                   {
# line 135 "example1.cp"
                       _sql->retcode = _sqlepilog(_sql);
# line 135 "example1.cp"
                   }
# line 135 "example1.cp"
                   
# line 135 "example1.cp"
                   if (sqlca.sqlcode < 0)
# line 135 "example1.cp"
                   {
# line 135 "example1.cp"
                       error_handler();
# line 135 "example1.cp"
                   }
# line 135 "example1.cp"
                   
# line 135 "example1.cp"
                   if (sqlca.sqlwarn[0] == 'W')
# line 135 "example1.cp"
                   {
# line 135 "example1.cp"
                       warning_handler();
# line 135 "example1.cp"
                   }
# line 135 "example1.cp"
                   
# line 135 "example1.cp"
               }
# line 135 "example1.cp"
               
# line 135 "example1.cp"
           }
# line 135 "example1.cp"
           

           /*
           ** Generated code ends here.
           */
# line 135 "example1.cp"

	return (strlen(type));	
}

/*
**	Displays a list of title id's and titles that are
**	from the selected type. Lets the user enter a title id. 
**	Copies the entry into tid, and returns the number of 
**	characters entered.
*/
int get_titleid(tid, type)
char *tid;
char *type;
{
	/*
	** Declare destination variables for the fetch. 
	*/
	
           /*
           ** SQL STATEMENT: 14
           ** EXEC SQL BEGIN DECLARE SECTION;

           */
# line 152 "example1.cp"

	char	b_titleid[TIDSIZE+1];
	char	b_title[65];
	/* 
	** We need to make a copy of the type argument because
	** we can't put the formal argument in a declare section.
	*/
	char	b_type[TYPESIZE+1];
	
           /*
           ** SQL STATEMENT: 15
           ** EXEC SQL END DECLARE SECTION;

           */
# line 160 "example1.cp"

           /*
           ** Generated code ends here.
           */
# line 160 "example1.cp"


	/* A buffer to hold keyboard input. */
	char	buf[128];

	/* Copy the type into b_type so we can use it to declare
	** the cursor.
	*/
	strcpy(b_type, type);

	/* This cursor selects title_id and title to display
	** a list for the user. The substring() function truncates
	** titles, if necessary, so they'll fit on an 80 column
	** display.
	*/
	
           /*
           ** SQL STATEMENT: 16
           ** EXEC SQL DECLARE titlelist CURSOR FOR
           ** 	SELECT	title_id, substring(title,1,64) 
           ** 	FROM	titles
           ** 	WHERE	type LIKE :b_type;
           */
# line 178 "example1.cp"


	/* Set b_titleid to null so we'll know if no titles
	** were selected for the specified type.
	*/
	b_titleid[0] = EOLN;

	/* Open the cursor. */
	
           /*
           ** SQL STATEMENT: 17
           ** EXEC SQL OPEN titlelist;

           */
# line 186 "example1.cp"
# line 186 "example1.cp"
           {
# line 186 "example1.cp"
                _SQL_CT_HANDLES * _sql;
# line 186 "example1.cp"
               _sqlinitctx(&_sql, CS_VERSION_125, CS_TRUE, &sqlca, (long 
# line 186 "example1.cp"
                   *)NULL, (CS_CHAR *)NULL);
# line 186 "example1.cp"
               if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 186 "example1.cp"
               {
# line 186 "example1.cp"
                   _sql->stmtData.persistent = CS_FALSE;
# line 186 "example1.cp"
                   _sql->moreData.curData.norebind = CS_FALSE;
# line 186 "example1.cp"
                   _sql->stmttype = SQL_OPEN_STMT;
# line 186 "example1.cp"
                   _sql->connName.lnlen = CS_UNUSED;
# line 186 "example1.cp"
                   _sql->curName.fnlen = 9;
# line 186 "example1.cp"
                   strcpy(_sql->curName.first_name, "titlelist");
# line 186 "example1.cp"
                   if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 186 "example1.cp"
                   {
# line 186 "example1.cp"
                       if (_sql->doDecl == CS_TRUE)
# line 186 "example1.cp"
                       {
# line 186 "example1.cp"
                           _sql->retcode = ct_cursor(_sql->conn.command, 
# line 186 "example1.cp"
                               CS_CURSOR_DECLARE, "titlelist", 9, "SELECT"
"	title_id, substring(title,1,64)  	FROM	titles 	WHERE	type L"
"IKE @sql0_b_type ", 83, CS_UNUSED);
# line 186 "example1.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 186 "example1.cp"
                           {
# line 186 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 186 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.format = 
# line 186 "example1.cp"
                                   (CS_FMT_NULLTERM | CS_FMT_PADBLANK);
# line 186 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.maxlength = TYPESIZE+1;
# line 186 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.status = CS_INPUTVALUE;
# line 186 "example1.cp"
                               _sql->retcode = ct_param(_sql->conn.command, 
# line 186 "example1.cp"
                                   &_sql->dfmtCS_CHAR_TYPE, NULL, (CS_INT) 
# line 186 "example1.cp"
                                   CS_UNUSED, (CS_SMALLINT) 0);
# line 186 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.status = 0;
# line 186 "example1.cp"
                           }
# line 186 "example1.cp"
                           
# line 186 "example1.cp"
                       }
# line 186 "example1.cp"
                       
# line 186 "example1.cp"
                       if (_sql->retcode == CS_SUCCEED)
# line 186 "example1.cp"
                       {
# line 186 "example1.cp"
                           if (_sql->stmtData.persistent == CS_TRUE)
# line 186 "example1.cp"
                           {
# line 186 "example1.cp"
                               _sql->retcode = ct_cursor(_sql->conn.command, 
# line 186 "example1.cp"
                                   CS_CURSOR_OPEN, NULL, CS_UNUSED, NULL, 
# line 186 "example1.cp"
                                   CS_UNUSED, CS_RESTORE_OPEN);
# line 186 "example1.cp"
                               }
# line 186 "example1.cp"
                                else {
# line 186 "example1.cp"
                               _sql->retcode = ct_cursor(_sql->conn.command, 
# line 186 "example1.cp"
                                   CS_CURSOR_OPEN, NULL, CS_UNUSED, NULL, 
# line 186 "example1.cp"
                                   CS_UNUSED, CS_UNUSED);
# line 186 "example1.cp"
                           }
# line 186 "example1.cp"
                           
# line 186 "example1.cp"
                       }
# line 186 "example1.cp"
                       
# line 186 "example1.cp"
                       if (_sql->stmtData.param == CS_TRUE)
# line 186 "example1.cp"
                       {
# line 186 "example1.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 186 "example1.cp"
                           {
# line 186 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 186 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.format = 
# line 186 "example1.cp"
                                   (CS_FMT_NULLTERM | CS_FMT_PADBLANK);
# line 186 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.maxlength = TYPESIZE+1;
# line 186 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.status = CS_INPUTVALUE;
# line 186 "example1.cp"
                               if (_sql->stmtData.persistent == CS_TRUE)
# line 186 "example1.cp"
                               {
# line 186 "example1.cp"
                                   _sql->retcode = 
# line 186 "example1.cp"
                                       ct_setparam(_sql->conn.command, 
# line 186 "example1.cp"
                                       &_sql->dfmtCS_CHAR_TYPE, 
# line 186 "example1.cp"
                                       _sqlcheckstr(_sql, 
# line 186 "example1.cp"
                                   SQLNULLSTR(b_type)), &(_sql->csnullterm), 
# line 186 "example1.cp"
                                       &(_sql->cszeroind));
# line 186 "example1.cp"
                                   }
# line 186 "example1.cp"
                                    else {
# line 186 "example1.cp"
                                   _sql->retcode = ct_param(_sql->conn.command,
# line 186 "example1.cp"
                                        &_sql->dfmtCS_CHAR_TYPE, 
# line 186 "example1.cp"
                                       _sqlcheckstr(_sql, 
# line 186 "example1.cp"
                                   SQLNULLSTR(b_type)), (CS_INT) 
# line 186 "example1.cp"
                                       _sql->csnullterm, (CS_SMALLINT) 
# line 186 "example1.cp"
                                       _sql->cszeroind);
# line 186 "example1.cp"
                               }
# line 186 "example1.cp"
                               
# line 186 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.status = 0;
# line 186 "example1.cp"
                           }
# line 186 "example1.cp"
                           
# line 186 "example1.cp"
                       }
# line 186 "example1.cp"
                       
# line 186 "example1.cp"
                       if (_sql->retcode == CS_SUCCEED)
# line 186 "example1.cp"
                       {
# line 186 "example1.cp"
                           _sql->retcode = ct_send(_sql->conn.command);
# line 186 "example1.cp"
                       }
# line 186 "example1.cp"
                       
# line 186 "example1.cp"
                       _sql->resloop = CS_TRUE;
# line 186 "example1.cp"
                       while ((_sql->resloop == CS_TRUE) && (_sql->retcode = 
# line 186 "example1.cp"
                           ct_results(_sql->conn.command, &_sql->restype)) == 
# line 186 "example1.cp"
                       CS_SUCCEED)
# line 186 "example1.cp"
                       {
# line 186 "example1.cp"
                           switch ( _sql->restype )
# line 186 "example1.cp"
                           {
# line 186 "example1.cp"
                           case CS_COMPUTE_RESULT:
# line 186 "example1.cp"
                               _sqlsetintrerr(_sql, (CS_INT) 
# line 186 "example1.cp"
                                   _SQL_INTRERR_25003);
# line 186 "example1.cp"
                               _sql->retcode = ct_cancel(NULL, 
# line 186 "example1.cp"
                                   _sql->conn.command, CS_CANCEL_CURRENT);
# line 186 "example1.cp"
                           break;
# line 186 "example1.cp"
                           case CS_CURSOR_RESULT:
# line 186 "example1.cp"
                               _sql->resloop = CS_FALSE;
# line 186 "example1.cp"
                           break;
# line 186 "example1.cp"
                           case CS_PARAM_RESULT:
# line 186 "example1.cp"
                               _sqlsetintrerr(_sql, (CS_INT) 
# line 186 "example1.cp"
                                   _SQL_INTRERR_25005);
# line 186 "example1.cp"
                               _sql->retcode = ct_cancel(NULL, 
# line 186 "example1.cp"
                                   _sql->conn.command, CS_CANCEL_CURRENT);
# line 186 "example1.cp"
                           break;
# line 186 "example1.cp"
                           case CS_ROW_RESULT:
# line 186 "example1.cp"
                               _sqlsetintrerr(_sql, (CS_INT) 
# line 186 "example1.cp"
                                   _SQL_INTRERR_25006);
# line 186 "example1.cp"
                               _sql->retcode = ct_cancel(NULL, 
# line 186 "example1.cp"
                                   _sql->conn.command, CS_CANCEL_CURRENT);
# line 186 "example1.cp"
                           break;
# line 186 "example1.cp"
                           case CS_STATUS_RESULT:
# line 186 "example1.cp"
                               _sqlsetintrerr(_sql, (CS_INT) 
# line 186 "example1.cp"
                                   _SQL_INTRERR_25009);
# line 186 "example1.cp"
                               _sql->retcode = ct_cancel(NULL, 
# line 186 "example1.cp"
                                   _sql->conn.command, CS_CANCEL_CURRENT);
# line 186 "example1.cp"
                           break;
# line 186 "example1.cp"
                           case CS_DESCRIBE_RESULT:
# line 186 "example1.cp"
                               _sqlsetintrerr(_sql, (CS_INT) 
# line 186 "example1.cp"
                                   _SQL_INTRERR_25010);
# line 186 "example1.cp"
                           break;
# line 186 "example1.cp"
                           }
# line 186 "example1.cp"
                           
# line 186 "example1.cp"
                       }
# line 186 "example1.cp"
                       
# line 186 "example1.cp"
                       _sql->retcode = _sqlepilog(_sql);
# line 186 "example1.cp"
                   }
# line 186 "example1.cp"
                   
# line 186 "example1.cp"
                   if (sqlca.sqlcode < 0)
# line 186 "example1.cp"
                   {
# line 186 "example1.cp"
                       error_handler();
# line 186 "example1.cp"
                   }
# line 186 "example1.cp"
                   
# line 186 "example1.cp"
                   if (sqlca.sqlwarn[0] == 'W')
# line 186 "example1.cp"
                   {
# line 186 "example1.cp"
                       warning_handler();
# line 186 "example1.cp"
                   }
# line 186 "example1.cp"
                   
# line 186 "example1.cp"
               }
# line 186 "example1.cp"
               
# line 186 "example1.cp"
           }
# line 186 "example1.cp"
           

           /*
           ** Generated code ends here.
           */
# line 186 "example1.cp"


	/* Display the list of titles */ 
	printf("\n\nSelect a title:\n\n");
	for (;;)
	{
		
           /*
           ** SQL STATEMENT: 18
           ** EXEC SQL FETCH titlelist INTO :b_titleid, :b_title;
           */
# line 192 "example1.cp"
# line 192 "example1.cp"
           {
# line 192 "example1.cp"
                _SQL_CT_HANDLES * _sql;
# line 192 "example1.cp"
               _sqlinitctx(&_sql, CS_VERSION_125, CS_TRUE, &sqlca, (long 
# line 192 "example1.cp"
                   *)NULL, (CS_CHAR *)NULL);
# line 192 "example1.cp"
               if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 192 "example1.cp"
               {
# line 192 "example1.cp"
                   _sql->stmtData.persistent = CS_FALSE;
# line 192 "example1.cp"
                   _sql->stmttype = SQL_FETCH_STMT;
# line 192 "example1.cp"
                   _sql->connName.lnlen = CS_UNUSED;
# line 192 "example1.cp"
                   _sql->curName.fnlen = 9;
# line 192 "example1.cp"
                   strcpy(_sql->curName.first_name, "titlelist");
# line 192 "example1.cp"
                   if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 192 "example1.cp"
                   {
# line 192 "example1.cp"
                       _sql->doDecl = CS_FALSE;
# line 192 "example1.cp"
                       if ((_sql->stmtData.bind == CS_TRUE) ||
# line 192 "example1.cp"
                       (_sql->moreData.curData.norebind == CS_FALSE))
# line 192 "example1.cp"
                       {
# line 192 "example1.cp"
                           _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 192 "example1.cp"
                           _sql->dfmtCS_CHAR_TYPE.format = (CS_FMT_NULLTERM | 
# line 192 "example1.cp"
                               CS_FMT_PADBLANK);
# line 192 "example1.cp"
                           _sql->dfmtCS_CHAR_TYPE.maxlength = TIDSIZE+1;
# line 192 "example1.cp"
                               _sql->retcode = ct_bind(_sql->conn.command, 1, 
# line 192 "example1.cp"
                                   &_sql->dfmtCS_CHAR_TYPE, b_titleid, NULL, 
# line 192 "example1.cp"
                                   NULL);
# line 192 "example1.cp"
                           _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 192 "example1.cp"
                           _sql->dfmtCS_CHAR_TYPE.format = (CS_FMT_NULLTERM | 
# line 192 "example1.cp"
                               CS_FMT_PADBLANK);
# line 192 "example1.cp"
                           _sql->dfmtCS_CHAR_TYPE.maxlength = 65;
# line 192 "example1.cp"
                               _sql->retcode = ct_bind(_sql->conn.command, 2, 
# line 192 "example1.cp"
                                   &_sql->dfmtCS_CHAR_TYPE, b_title, NULL, 
# line 192 "example1.cp"
                                   NULL);
# line 192 "example1.cp"
                           if (_sql->stmtData.bind == CS_TRUE)
# line 192 "example1.cp"
                           {
# line 192 "example1.cp"
                               _sql->stmtData.bind = CS_FALSE;
# line 192 "example1.cp"
                               _sql->doDecl = CS_TRUE;
# line 192 "example1.cp"
                           }
# line 192 "example1.cp"
                           
# line 192 "example1.cp"
                       }
# line 192 "example1.cp"
                       
# line 192 "example1.cp"
                       _sql->retcode = ct_fetch(_sql->conn.command, CS_UNUSED, 
# line 192 "example1.cp"
                           CS_UNUSED, CS_UNUSED, &_sql->rowsread);
# line 192 "example1.cp"
                       if (_sql->retcode == CS_END_DATA)
# line 192 "example1.cp"
                       {
# line 192 "example1.cp"
                           _sql->retcode = _sqlResults(_sql);
# line 192 "example1.cp"
                       }
# line 192 "example1.cp"
                       
# line 192 "example1.cp"
                       _sql->retcode = _sqlepilog(_sql);
# line 192 "example1.cp"
                   }
# line 192 "example1.cp"
                   
# line 192 "example1.cp"
                   if (sqlca.sqlcode < 0)
# line 192 "example1.cp"
                   {
# line 192 "example1.cp"
                       error_handler();
# line 192 "example1.cp"
                   }
# line 192 "example1.cp"
                   
# line 192 "example1.cp"
                   if (sqlca.sqlwarn[0] == 'W')
# line 192 "example1.cp"
                   {
# line 192 "example1.cp"
                       warning_handler();
# line 192 "example1.cp"
                   }
# line 192 "example1.cp"
                   
# line 192 "example1.cp"
               }
# line 192 "example1.cp"
               
# line 192 "example1.cp"
           }
# line 192 "example1.cp"
           

           /*
           ** Generated code ends here.
           */
# line 192 "example1.cp"

		if (sqlca.sqlcode == 100)
			break;
		printf("   %-8s %s\n", b_titleid, b_title);
	}

	/* If b_titleid is still null, no titles were found, so 
	** we won't ask the user to select one. 
	*/
	if (!strlen(b_titleid))
	{
		printf("\nThere are no '%s' titles.\n", b_type);
		tid[0] = EOLN;
	}
	else
	{
		/* We use gets() as the input function. A title_id is
		** only 6 bytes long, and gets() doesn't check the 
		** length of the entry. Therefore, we'll gets() into
		** a longer buffer, and copy 6 bytes into the tid
		** variable.
		*/
		printf("\ntitle ID? ");
		gets(buf);
		tid[6] = EOLN;
		strncpy(tid, buf, 6);
	}

	/*
	** Close the cursor and return the number of characters entered.
	*/
	
           /*
           ** SQL STATEMENT: 19
           ** EXEC SQL CLOSE titlelist;

           */
# line 223 "example1.cp"
# line 223 "example1.cp"
           {
# line 223 "example1.cp"
                _SQL_CT_HANDLES * _sql;
# line 223 "example1.cp"
               _sqlinitctx(&_sql, CS_VERSION_125, CS_TRUE, &sqlca, (long 
# line 223 "example1.cp"
                   *)NULL, (CS_CHAR *)NULL);
# line 223 "example1.cp"
               if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 223 "example1.cp"
               {
# line 223 "example1.cp"
                   _sql->stmtData.persistent = CS_FALSE;
# line 223 "example1.cp"
                   _sql->stmttype = SQL_CLOSE_STMT;
# line 223 "example1.cp"
                   _sql->connName.lnlen = CS_UNUSED;
# line 223 "example1.cp"
                   _sql->curName.fnlen = 9;
# line 223 "example1.cp"
                   strcpy(_sql->curName.first_name, "titlelist");
# line 223 "example1.cp"
                   if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 223 "example1.cp"
                   {
# line 223 "example1.cp"
                       _sql->retcode = _sqlepilog(_sql);
# line 223 "example1.cp"
                   }
# line 223 "example1.cp"
                   
# line 223 "example1.cp"
                   if (sqlca.sqlcode < 0)
# line 223 "example1.cp"
                   {
# line 223 "example1.cp"
                       error_handler();
# line 223 "example1.cp"
                   }
# line 223 "example1.cp"
                   
# line 223 "example1.cp"
                   if (sqlca.sqlwarn[0] == 'W')
# line 223 "example1.cp"
                   {
# line 223 "example1.cp"
                       warning_handler();
# line 223 "example1.cp"
                   }
# line 223 "example1.cp"
                   
# line 223 "example1.cp"
               }
# line 223 "example1.cp"
               
# line 223 "example1.cp"
           }
# line 223 "example1.cp"
           

           /*
           ** Generated code ends here.
           */
# line 223 "example1.cp"

	return (strlen(tid));	
}

/*
** void show_book(typeid) 
**
**	Displays information about the book with the specified
**	title id. A book can have coauthors, so we need a cursor
**	to list the authors.
*/
void show_book(titleid)
char *titleid;
{
	
           /*
           ** SQL STATEMENT: 19
           ** EXEC SQL BEGIN DECLARE SECTION;

           */
# line 237 "example1.cp"

	/* Destination variables for fetches. */
	char	m_titleid[7];
	char	m_title[65];
	char	m_pubname[41];
	char	m_pubcity[21];
	char	m_pubstate[3];	
	char	m_notes[201];
	char	m_author[62];
	/* An indicator variable for notes. */ 
	short	i_notes;
	
           /*
           ** SQL STATEMENT: 20
           ** EXEC SQL END DECLARE SECTION;

           */
# line 248 "example1.cp"

           /*
           ** Generated code ends here.
           */
# line 248 "example1.cp"


	/* These variables are used in the word-wrapping routine
	** that display the notes.
	*/
	char	*p, noteline[65];
	int	i, notelen;

	/* We need a local copy of the titleid to use in the
	** fetch.
	*/
	strcpy(m_titleid, titleid);	

	/* Fetch the information about the title and publisher. A
	** cursor is not needed because the title id is unique. 
	** No more than one row can be returned.
	*/
	
           /*
           ** SQL STATEMENT: 21
           ** EXEC SQL 
           ** 	SELECT	substring(title, 1, 64), notes, pub_name, city, state
           ** 	INTO	:m_title, :m_notes:i_notes, :m_pubname, :m_pubcity, :m_pubs
           ** tate
           ** 	FROM	titles, publishers
           ** 	WHERE	titles.pub_id = publishers.pub_id 
           ** 	AND	title_id = :m_titleid;
           */
# line 270 "example1.cp"
# line 265 "example1.cp"
           {
# line 265 "example1.cp"
                _SQL_CT_HANDLES * _sql;
# line 265 "example1.cp"
               _sqlinitctx(&_sql, CS_VERSION_125, CS_TRUE, &sqlca, (long 
# line 265 "example1.cp"
                   *)NULL, (CS_CHAR *)NULL);
# line 265 "example1.cp"
               if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 265 "example1.cp"
               {
# line 265 "example1.cp"
                   _sql->stmtIdlen = CS_UNUSED;
# line 265 "example1.cp"
                   _sql->stmtData.persistent = CS_FALSE;
# line 265 "example1.cp"
                   _sql->stmttype = SQL_SELECT_STMT;
# line 265 "example1.cp"
                   _sql->connName.lnlen = CS_UNUSED;
# line 265 "example1.cp"
                   if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 265 "example1.cp"
                   {
# line 265 "example1.cp"
                       _sql->retcode = ct_command(_sql->conn.command, 
# line 265 "example1.cp"
                           CS_LANG_CMD, "SELECT	substring(title, 1, 64), notes"
", pub_name, city, state 	FROM	titles, publishers 	WHERE	titles"
".pub_id = publishers.pub_id  	AND	title_id = @sql5_m_titleid ", 160, 
# line 265 "example1.cp"
                           CS_UNUSED);
# line 265 "example1.cp"
                       if (_sql->retcode == CS_SUCCEED)
# line 265 "example1.cp"
                       {
# line 265 "example1.cp"
                           _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 265 "example1.cp"
                           _sql->dfmtCS_CHAR_TYPE.format = (CS_FMT_NULLTERM | 
# line 265 "example1.cp"
                               CS_FMT_PADBLANK);
# line 265 "example1.cp"
                           _sql->dfmtCS_CHAR_TYPE.maxlength = 7;
# line 265 "example1.cp"
                           _sql->dfmtCS_CHAR_TYPE.status = CS_INPUTVALUE;
# line 265 "example1.cp"
                           _sql->retcode = ct_param(_sql->conn.command, 
# line 265 "example1.cp"
                               &_sql->dfmtCS_CHAR_TYPE, _sqlcheckstr(_sql, 
# line 265 "example1.cp"
                           SQLNULLSTR(m_titleid)), (CS_INT) CS_NULLTERM, 
# line 265 "example1.cp"
                               (CS_SMALLINT) 0);
# line 265 "example1.cp"
                           _sql->dfmtCS_CHAR_TYPE.status = 0;
# line 265 "example1.cp"
                       }
# line 265 "example1.cp"
                       
# line 265 "example1.cp"
                       _sql->retcode = ct_send(_sql->conn.command);
# line 265 "example1.cp"
                       _sql->resloop = CS_TRUE;
# line 265 "example1.cp"
                       while ((_sql->resloop == CS_TRUE) && (_sql->retcode = 
# line 265 "example1.cp"
                           ct_results(_sql->conn.command, &_sql->restype)) == 
# line 265 "example1.cp"
                       CS_SUCCEED)
# line 265 "example1.cp"
                       {
# line 265 "example1.cp"
                           switch ( _sql->restype )
# line 265 "example1.cp"
                           {
# line 265 "example1.cp"
                           case CS_COMPUTE_RESULT:
# line 265 "example1.cp"
                               _sqlsetintrerr(_sql, (CS_INT) 
# line 265 "example1.cp"
                                   _SQL_INTRERR_25003);
# line 265 "example1.cp"
                               _sql->retcode = ct_cancel(NULL, 
# line 265 "example1.cp"
                                   _sql->conn.command, CS_CANCEL_CURRENT);
# line 265 "example1.cp"
                           break;
# line 265 "example1.cp"
                           case CS_CURSOR_RESULT:
# line 265 "example1.cp"
                               _sqlsetintrerr(_sql, (CS_INT) 
# line 265 "example1.cp"
                                   _SQL_INTRERR_25004);
# line 265 "example1.cp"
                               _sql->retcode = ct_cancel(NULL, 
# line 265 "example1.cp"
                                   _sql->conn.command, CS_CANCEL_CURRENT);
# line 265 "example1.cp"
                           break;
# line 265 "example1.cp"
                           case CS_PARAM_RESULT:
# line 265 "example1.cp"
                               _sqlsetintrerr(_sql, (CS_INT) 
# line 265 "example1.cp"
                                   _SQL_INTRERR_25005);
# line 265 "example1.cp"
                               _sql->retcode = ct_cancel(NULL, 
# line 265 "example1.cp"
                                   _sql->conn.command, CS_CANCEL_CURRENT);
# line 265 "example1.cp"
                           break;
# line 265 "example1.cp"
                           case CS_ROW_RESULT:
# line 265 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 265 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.format = 
# line 265 "example1.cp"
                                   (CS_FMT_NULLTERM | CS_FMT_PADBLANK);
# line 265 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.maxlength = 65;
# line 265 "example1.cp"
                                   _sql->retcode = ct_bind(_sql->conn.command, 
# line 265 "example1.cp"
                                       1, &_sql->dfmtCS_CHAR_TYPE, m_title, 
# line 265 "example1.cp"
                                       NULL, NULL);
# line 265 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 265 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.format = 
# line 265 "example1.cp"
                                   (CS_FMT_NULLTERM | CS_FMT_PADBLANK);
# line 265 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.maxlength = 201;
# line 265 "example1.cp"
                                   _sql->retcode = ct_bind(_sql->conn.command, 
# line 265 "example1.cp"
                                       2, &_sql->dfmtCS_CHAR_TYPE, m_notes, 
# line 265 "example1.cp"
                                       NULL, &i_notes);
# line 265 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 265 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.format = 
# line 265 "example1.cp"
                                   (CS_FMT_NULLTERM | CS_FMT_PADBLANK);
# line 265 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.maxlength = 41;
# line 265 "example1.cp"
                                   _sql->retcode = ct_bind(_sql->conn.command, 
# line 265 "example1.cp"
                                       3, &_sql->dfmtCS_CHAR_TYPE, m_pubname, 
# line 265 "example1.cp"
                                       NULL, NULL);
# line 265 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 265 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.format = 
# line 265 "example1.cp"
                                   (CS_FMT_NULLTERM | CS_FMT_PADBLANK);
# line 265 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.maxlength = 21;
# line 265 "example1.cp"
                                   _sql->retcode = ct_bind(_sql->conn.command, 
# line 265 "example1.cp"
                                       4, &_sql->dfmtCS_CHAR_TYPE, m_pubcity, 
# line 265 "example1.cp"
                                       NULL, NULL);
# line 265 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 265 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.format = 
# line 265 "example1.cp"
                                   (CS_FMT_NULLTERM | CS_FMT_PADBLANK);
# line 265 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.maxlength = 3;
# line 265 "example1.cp"
                                   _sql->retcode = ct_bind(_sql->conn.command, 
# line 265 "example1.cp"
                                       5, &_sql->dfmtCS_CHAR_TYPE, m_pubstate, 
# line 265 "example1.cp"
                                       NULL, NULL);
# line 265 "example1.cp"
                               _sql->retcode = ct_fetch(_sql->conn.command, 
# line 265 "example1.cp"
                                   CS_UNUSED, CS_UNUSED, CS_UNUSED, 
# line 265 "example1.cp"
                                   &_sql->rowsread);
# line 265 "example1.cp"
                               if ((_sql->retcode == CS_SUCCEED) || 
# line 265 "example1.cp"
                                   (_sql->retcode == CS_ROW_FAIL))
# line 265 "example1.cp"
                               {
# line 265 "example1.cp"
                                   _sql->retcode = ct_bind(_sql->conn.command, 
# line 265 "example1.cp"
                                       CS_UNUSED, NULL, NULL, NULL, NULL);
# line 265 "example1.cp"
                                   _sql->retcode = ct_fetch(_sql->conn.command,
# line 265 "example1.cp"
                                        CS_UNUSED, CS_UNUSED, CS_UNUSED, 
# line 265 "example1.cp"
                                       &_sql->rowsread);
# line 265 "example1.cp"
                               }
# line 265 "example1.cp"
                               
# line 265 "example1.cp"
                           break;
# line 265 "example1.cp"
                           case CS_STATUS_RESULT:
# line 265 "example1.cp"
                               _sqlsetintrerr(_sql, (CS_INT) 
# line 265 "example1.cp"
                                   _SQL_INTRERR_25009);
# line 265 "example1.cp"
                               _sql->retcode = ct_cancel(NULL, 
# line 265 "example1.cp"
                                   _sql->conn.command, CS_CANCEL_CURRENT);
# line 265 "example1.cp"
                           break;
# line 265 "example1.cp"
                           case CS_DESCRIBE_RESULT:
# line 265 "example1.cp"
                               _sqlsetintrerr(_sql, (CS_INT) 
# line 265 "example1.cp"
                                   _SQL_INTRERR_25010);
# line 265 "example1.cp"
                           break;
# line 265 "example1.cp"
                           }
# line 265 "example1.cp"
                           
# line 265 "example1.cp"
                       }
# line 265 "example1.cp"
                       
# line 265 "example1.cp"
                       if ((_sql->retcode != CS_END_RESULTS) && (_sql->retcode 
# line 265 "example1.cp"
                           != CS_CANCELED) && (_sql->resloop != CS_FALSE))
# line 265 "example1.cp"
                       {
# line 265 "example1.cp"
                           _sql->retcode = ct_cancel(NULL, _sql->conn.command, 
# line 265 "example1.cp"
                               CS_CANCEL_ALL);
# line 265 "example1.cp"
                           }
# line 265 "example1.cp"
                            else {
# line 265 "example1.cp"
                           if (_sql->retcode != CS_CANCELED)
# line 265 "example1.cp"
                           {
# line 265 "example1.cp"
                               _sql->retcode = CS_SUCCEED;
# line 265 "example1.cp"
                           }
# line 265 "example1.cp"
                           
# line 265 "example1.cp"
                       }
# line 265 "example1.cp"
                       
# line 265 "example1.cp"
                       _sql->retcode = _sqlepilog(_sql);
# line 265 "example1.cp"
                   }
# line 265 "example1.cp"
                   
# line 265 "example1.cp"
                   if (sqlca.sqlcode < 0)
# line 265 "example1.cp"
                   {
# line 265 "example1.cp"
                       error_handler();
# line 265 "example1.cp"
                   }
# line 265 "example1.cp"
                   
# line 265 "example1.cp"
                   if (sqlca.sqlwarn[0] == 'W')
# line 265 "example1.cp"
                   {
# line 265 "example1.cp"
                       warning_handler();
# line 265 "example1.cp"
                   }
# line 265 "example1.cp"
                   
# line 265 "example1.cp"
               }
# line 265 "example1.cp"
               
# line 265 "example1.cp"
           }
# line 265 "example1.cp"
           

           /*
           ** Generated code ends here.
           */
# line 270 "example1.cp"


	/* sqlca.sqlcode is set to 100 if the title_id isn't found. */
	if (sqlca.sqlcode == 100) 
	{
		printf("\n\t** Can't find title '%s'.\n", m_titleid);
		return;
	}

	/* Display the title and publisher's name and address. */
	printf("\n\n%s", m_title);
	printf("\n\nPub:\t%s", m_pubname);
	printf("\n\t%s %s", m_pubcity, m_pubstate);

	/* There can be more than one author, so we need a cursor
	** to list them. We can let SQL Server combine the first
	** and last names so that only one column is returned.
	*/
	
           /*
           ** SQL STATEMENT: 22
           ** EXEC SQL DECLARE authors CURSOR FOR
           ** 	SELECT  au_fname + ' ' + au_lname 
           ** 	FROM	authors, titleauthor
           ** 	WHERE	authors.au_id = titleauthor.au_id
           ** 	AND	title_id = :m_titleid;
           */
# line 292 "example1.cp"


	/* Open the cursor. */
	
           /*
           ** SQL STATEMENT: 23
           ** EXEC SQL OPEN authors;

           */
# line 295 "example1.cp"
# line 295 "example1.cp"
           {
# line 295 "example1.cp"
                _SQL_CT_HANDLES * _sql;
# line 295 "example1.cp"
               _sqlinitctx(&_sql, CS_VERSION_125, CS_TRUE, &sqlca, (long 
# line 295 "example1.cp"
                   *)NULL, (CS_CHAR *)NULL);
# line 295 "example1.cp"
               if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 295 "example1.cp"
               {
# line 295 "example1.cp"
                   _sql->stmtData.persistent = CS_FALSE;
# line 295 "example1.cp"
                   _sql->moreData.curData.norebind = CS_FALSE;
# line 295 "example1.cp"
                   _sql->stmttype = SQL_OPEN_STMT;
# line 295 "example1.cp"
                   _sql->connName.lnlen = CS_UNUSED;
# line 295 "example1.cp"
                   _sql->curName.fnlen = 7;
# line 295 "example1.cp"
                   strcpy(_sql->curName.first_name, "authors");
# line 295 "example1.cp"
                   if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 295 "example1.cp"
                   {
# line 295 "example1.cp"
                       if (_sql->doDecl == CS_TRUE)
# line 295 "example1.cp"
                       {
# line 295 "example1.cp"
                           _sql->retcode = ct_cursor(_sql->conn.command, 
# line 295 "example1.cp"
                               CS_CURSOR_DECLARE, "authors", 7, "SELECT  au_fna"
"me + ' ' + au_lname  	FROM	authors, titleauthor 	WHERE	authors.au_id "
"= titleauthor.au_id 	AND	title_id = @sql0_m_titleid ", 135, CS_UNUSED);
# line 295 "example1.cp"
                           
# line 295 "example1.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 295 "example1.cp"
                           {
# line 295 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 295 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.format = 
# line 295 "example1.cp"
                                   (CS_FMT_NULLTERM | CS_FMT_PADBLANK);
# line 295 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.maxlength = 7;
# line 295 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.status = CS_INPUTVALUE;
# line 295 "example1.cp"
                               _sql->retcode = ct_param(_sql->conn.command, 
# line 295 "example1.cp"
                                   &_sql->dfmtCS_CHAR_TYPE, NULL, (CS_INT) 
# line 295 "example1.cp"
                                   CS_UNUSED, (CS_SMALLINT) 0);
# line 295 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.status = 0;
# line 295 "example1.cp"
                           }
# line 295 "example1.cp"
                           
# line 295 "example1.cp"
                       }
# line 295 "example1.cp"
                       
# line 295 "example1.cp"
                       if (_sql->retcode == CS_SUCCEED)
# line 295 "example1.cp"
                       {
# line 295 "example1.cp"
                           if (_sql->stmtData.persistent == CS_TRUE)
# line 295 "example1.cp"
                           {
# line 295 "example1.cp"
                               _sql->retcode = ct_cursor(_sql->conn.command, 
# line 295 "example1.cp"
                                   CS_CURSOR_OPEN, NULL, CS_UNUSED, NULL, 
# line 295 "example1.cp"
                                   CS_UNUSED, CS_RESTORE_OPEN);
# line 295 "example1.cp"
                               }
# line 295 "example1.cp"
                                else {
# line 295 "example1.cp"
                               _sql->retcode = ct_cursor(_sql->conn.command, 
# line 295 "example1.cp"
                                   CS_CURSOR_OPEN, NULL, CS_UNUSED, NULL, 
# line 295 "example1.cp"
                                   CS_UNUSED, CS_UNUSED);
# line 295 "example1.cp"
                           }
# line 295 "example1.cp"
                           
# line 295 "example1.cp"
                       }
# line 295 "example1.cp"
                       
# line 295 "example1.cp"
                       if (_sql->stmtData.param == CS_TRUE)
# line 295 "example1.cp"
                       {
# line 295 "example1.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 295 "example1.cp"
                           {
# line 295 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 295 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.format = 
# line 295 "example1.cp"
                                   (CS_FMT_NULLTERM | CS_FMT_PADBLANK);
# line 295 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.maxlength = 7;
# line 295 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.status = CS_INPUTVALUE;
# line 295 "example1.cp"
                               if (_sql->stmtData.persistent == CS_TRUE)
# line 295 "example1.cp"
                               {
# line 295 "example1.cp"
                                   _sql->retcode = 
# line 295 "example1.cp"
                                       ct_setparam(_sql->conn.command, 
# line 295 "example1.cp"
                                       &_sql->dfmtCS_CHAR_TYPE, 
# line 295 "example1.cp"
                                       _sqlcheckstr(_sql, 
# line 295 "example1.cp"
                                   SQLNULLSTR(m_titleid)), &(_sql->csnullterm),
# line 295 "example1.cp"
                                        &(_sql->cszeroind));
# line 295 "example1.cp"
                                   }
# line 295 "example1.cp"
                                    else {
# line 295 "example1.cp"
                                   _sql->retcode = ct_param(_sql->conn.command,
# line 295 "example1.cp"
                                        &_sql->dfmtCS_CHAR_TYPE, 
# line 295 "example1.cp"
                                       _sqlcheckstr(_sql, 
# line 295 "example1.cp"
                                   SQLNULLSTR(m_titleid)), (CS_INT) 
# line 295 "example1.cp"
                                       _sql->csnullterm, (CS_SMALLINT) 
# line 295 "example1.cp"
                                       _sql->cszeroind);
# line 295 "example1.cp"
                               }
# line 295 "example1.cp"
                               
# line 295 "example1.cp"
                               _sql->dfmtCS_CHAR_TYPE.status = 0;
# line 295 "example1.cp"
                           }
# line 295 "example1.cp"
                           
# line 295 "example1.cp"
                       }
# line 295 "example1.cp"
                       
# line 295 "example1.cp"
                       if (_sql->retcode == CS_SUCCEED)
# line 295 "example1.cp"
                       {
# line 295 "example1.cp"
                           _sql->retcode = ct_send(_sql->conn.command);
# line 295 "example1.cp"
                       }
# line 295 "example1.cp"
                       
# line 295 "example1.cp"
                       _sql->resloop = CS_TRUE;
# line 295 "example1.cp"
                       while ((_sql->resloop == CS_TRUE) && (_sql->retcode = 
# line 295 "example1.cp"
                           ct_results(_sql->conn.command, &_sql->restype)) == 
# line 295 "example1.cp"
                       CS_SUCCEED)
# line 295 "example1.cp"
                       {
# line 295 "example1.cp"
                           switch ( _sql->restype )
# line 295 "example1.cp"
                           {
# line 295 "example1.cp"
                           case CS_COMPUTE_RESULT:
# line 295 "example1.cp"
                               _sqlsetintrerr(_sql, (CS_INT) 
# line 295 "example1.cp"
                                   _SQL_INTRERR_25003);
# line 295 "example1.cp"
                               _sql->retcode = ct_cancel(NULL, 
# line 295 "example1.cp"
                                   _sql->conn.command, CS_CANCEL_CURRENT);
# line 295 "example1.cp"
                           break;
# line 295 "example1.cp"
                           case CS_CURSOR_RESULT:
# line 295 "example1.cp"
                               _sql->resloop = CS_FALSE;
# line 295 "example1.cp"
                           break;
# line 295 "example1.cp"
                           case CS_PARAM_RESULT:
# line 295 "example1.cp"
                               _sqlsetintrerr(_sql, (CS_INT) 
# line 295 "example1.cp"
                                   _SQL_INTRERR_25005);
# line 295 "example1.cp"
                               _sql->retcode = ct_cancel(NULL, 
# line 295 "example1.cp"
                                   _sql->conn.command, CS_CANCEL_CURRENT);
# line 295 "example1.cp"
                           break;
# line 295 "example1.cp"
                           case CS_ROW_RESULT:
# line 295 "example1.cp"
                               _sqlsetintrerr(_sql, (CS_INT) 
# line 295 "example1.cp"
                                   _SQL_INTRERR_25006);
# line 295 "example1.cp"
                               _sql->retcode = ct_cancel(NULL, 
# line 295 "example1.cp"
                                   _sql->conn.command, CS_CANCEL_CURRENT);
# line 295 "example1.cp"
                           break;
# line 295 "example1.cp"
                           case CS_STATUS_RESULT:
# line 295 "example1.cp"
                               _sqlsetintrerr(_sql, (CS_INT) 
# line 295 "example1.cp"
                                   _SQL_INTRERR_25009);
# line 295 "example1.cp"
                               _sql->retcode = ct_cancel(NULL, 
# line 295 "example1.cp"
                                   _sql->conn.command, CS_CANCEL_CURRENT);
# line 295 "example1.cp"
                           break;
# line 295 "example1.cp"
                           case CS_DESCRIBE_RESULT:
# line 295 "example1.cp"
                               _sqlsetintrerr(_sql, (CS_INT) 
# line 295 "example1.cp"
                                   _SQL_INTRERR_25010);
# line 295 "example1.cp"
                           break;
# line 295 "example1.cp"
                           }
# line 295 "example1.cp"
                           
# line 295 "example1.cp"
                       }
# line 295 "example1.cp"
                       
# line 295 "example1.cp"
                       _sql->retcode = _sqlepilog(_sql);
# line 295 "example1.cp"
                   }
# line 295 "example1.cp"
                   
# line 295 "example1.cp"
                   if (sqlca.sqlcode < 0)
# line 295 "example1.cp"
                   {
# line 295 "example1.cp"
                       error_handler();
# line 295 "example1.cp"
                   }
# line 295 "example1.cp"
                   
# line 295 "example1.cp"
                   if (sqlca.sqlwarn[0] == 'W')
# line 295 "example1.cp"
                   {
# line 295 "example1.cp"
                       warning_handler();
# line 295 "example1.cp"
                   }
# line 295 "example1.cp"
                   
# line 295 "example1.cp"
               }
# line 295 "example1.cp"
               
# line 295 "example1.cp"
           }
# line 295 "example1.cp"
           

           /*
           ** Generated code ends here.
           */
# line 295 "example1.cp"


	/* Each row fetched is an additional coauthor. */ 
	printf("\n\nBy:");
	for(;;)
	{
		
           /*
           ** SQL STATEMENT: 24
           ** EXEC SQL FETCH authors INTO :m_author;
           */
# line 301 "example1.cp"
# line 301 "example1.cp"
           {
# line 301 "example1.cp"
                _SQL_CT_HANDLES * _sql;
# line 301 "example1.cp"
               _sqlinitctx(&_sql, CS_VERSION_125, CS_TRUE, &sqlca, (long 
# line 301 "example1.cp"
                   *)NULL, (CS_CHAR *)NULL);
# line 301 "example1.cp"
               if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 301 "example1.cp"
               {
# line 301 "example1.cp"
                   _sql->stmtData.persistent = CS_FALSE;
# line 301 "example1.cp"
                   _sql->stmttype = SQL_FETCH_STMT;
# line 301 "example1.cp"
                   _sql->connName.lnlen = CS_UNUSED;
# line 301 "example1.cp"
                   _sql->curName.fnlen = 7;
# line 301 "example1.cp"
                   strcpy(_sql->curName.first_name, "authors");
# line 301 "example1.cp"
                   if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 301 "example1.cp"
                   {
# line 301 "example1.cp"
                       _sql->doDecl = CS_FALSE;
# line 301 "example1.cp"
                       if ((_sql->stmtData.bind == CS_TRUE) ||
# line 301 "example1.cp"
                       (_sql->moreData.curData.norebind == CS_FALSE))
# line 301 "example1.cp"
                       {
# line 301 "example1.cp"
                           _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 301 "example1.cp"
                           _sql->dfmtCS_CHAR_TYPE.format = (CS_FMT_NULLTERM | 
# line 301 "example1.cp"
                               CS_FMT_PADBLANK);
# line 301 "example1.cp"
                           _sql->dfmtCS_CHAR_TYPE.maxlength = 62;
# line 301 "example1.cp"
                               _sql->retcode = ct_bind(_sql->conn.command, 1, 
# line 301 "example1.cp"
                                   &_sql->dfmtCS_CHAR_TYPE, m_author, NULL, 
# line 301 "example1.cp"
                                   NULL);
# line 301 "example1.cp"
                           if (_sql->stmtData.bind == CS_TRUE)
# line 301 "example1.cp"
                           {
# line 301 "example1.cp"
                               _sql->stmtData.bind = CS_FALSE;
# line 301 "example1.cp"
                               _sql->doDecl = CS_TRUE;
# line 301 "example1.cp"
                           }
# line 301 "example1.cp"
                           
# line 301 "example1.cp"
                       }
# line 301 "example1.cp"
                       
# line 301 "example1.cp"
                       _sql->retcode = ct_fetch(_sql->conn.command, CS_UNUSED, 
# line 301 "example1.cp"
                           CS_UNUSED, CS_UNUSED, &_sql->rowsread);
# line 301 "example1.cp"
                       if (_sql->retcode == CS_END_DATA)
# line 301 "example1.cp"
                       {
# line 301 "example1.cp"
                           _sql->retcode = _sqlResults(_sql);
# line 301 "example1.cp"
                       }
# line 301 "example1.cp"
                       
# line 301 "example1.cp"
                       _sql->retcode = _sqlepilog(_sql);
# line 301 "example1.cp"
                   }
# line 301 "example1.cp"
                   
# line 301 "example1.cp"
                   if (sqlca.sqlcode < 0)
# line 301 "example1.cp"
                   {
# line 301 "example1.cp"
                       error_handler();
# line 301 "example1.cp"
                   }
# line 301 "example1.cp"
                   
# line 301 "example1.cp"
                   if (sqlca.sqlwarn[0] == 'W')
# line 301 "example1.cp"
                   {
# line 301 "example1.cp"
                       warning_handler();
# line 301 "example1.cp"
                   }
# line 301 "example1.cp"
                   
# line 301 "example1.cp"
               }
# line 301 "example1.cp"
               
# line 301 "example1.cp"
           }
# line 301 "example1.cp"
           

           /*
           ** Generated code ends here.
           */
# line 301 "example1.cp"

		if (sqlca.sqlcode == 100)
			break;
		printf("\t%s\n", m_author);
	}

	/* Close the cursor. */
	
           /*
           ** SQL STATEMENT: 25
           ** EXEC SQL CLOSE authors;

           */
# line 308 "example1.cp"
# line 308 "example1.cp"
           {
# line 308 "example1.cp"
                _SQL_CT_HANDLES * _sql;
# line 308 "example1.cp"
               _sqlinitctx(&_sql, CS_VERSION_125, CS_TRUE, &sqlca, (long 
# line 308 "example1.cp"
                   *)NULL, (CS_CHAR *)NULL);
# line 308 "example1.cp"
               if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 308 "example1.cp"
               {
# line 308 "example1.cp"
                   _sql->stmtData.persistent = CS_FALSE;
# line 308 "example1.cp"
                   _sql->stmttype = SQL_CLOSE_STMT;
# line 308 "example1.cp"
                   _sql->connName.lnlen = CS_UNUSED;
# line 308 "example1.cp"
                   _sql->curName.fnlen = 7;
# line 308 "example1.cp"
                   strcpy(_sql->curName.first_name, "authors");
# line 308 "example1.cp"
                   if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 308 "example1.cp"
                   {
# line 308 "example1.cp"
                       _sql->retcode = _sqlepilog(_sql);
# line 308 "example1.cp"
                   }
# line 308 "example1.cp"
                   
# line 308 "example1.cp"
                   if (sqlca.sqlcode < 0)
# line 308 "example1.cp"
                   {
# line 308 "example1.cp"
                       error_handler();
# line 308 "example1.cp"
                   }
# line 308 "example1.cp"
                   
# line 308 "example1.cp"
                   if (sqlca.sqlwarn[0] == 'W')
# line 308 "example1.cp"
                   {
# line 308 "example1.cp"
                       warning_handler();
# line 308 "example1.cp"
                   }
# line 308 "example1.cp"
                   
# line 308 "example1.cp"
               }
# line 308 "example1.cp"
               
# line 308 "example1.cp"
           }
# line 308 "example1.cp"
           

           /*
           ** Generated code ends here.
           */
# line 308 "example1.cp"

		
	/* This routine prints the notes column on multiple lines
	** with word wrapping. Nothing is printed if the indicator
	** variable was set to -1.
	*/
	if (i_notes != -1)
	{
		register  char  *q;

		printf("\nNotes:");
		notelen = strlen(m_notes);
		p = m_notes;
		while (notelen > 64)
		{
			noteline[64] = EOLN;
			strncpy(noteline, p, 64);
			for (i = strlen(noteline), q = noteline + i; 
				i  &&  ! (*q == ' ' || *q == '\t'); 
				i--, q--);
			noteline[i] = EOLN;
			notelen -= strlen(noteline);
			printf("\t%s\n", noteline);
			p += (strlen(noteline)+1);
		}
		if (notelen)
			printf("\t%s\n", p);
	}

	/* Pause before returning so the user can read the display. */
	printf("\npress return...");
	getchar();
	return;
}

/*
** void error_handler()
** 
**	Displays error codes and numbers from the SQLCA and exits with
**	an ERREXIT status. 
*/
void error_handler()
{
	fprintf(stderr, "\n** SQLCODE=(%ld)", sqlca.sqlcode);

	if (sqlca.sqlerrm.sqlerrml)
	{
		fprintf(stderr, "\n** SQL Server Error ");
		fprintf(stderr, "\n** %s", sqlca.sqlerrm.sqlerrmc);
	}

	fprintf(stderr, "\n\n");

	exit(ERREXIT);
}

/*
** void warning_handler()
** 
**	Displays warning messages.
*/
void warning_handler()
{

	if (sqlca.sqlwarn[1] == 'W')
	{
		fprintf(stderr, 
			"\n** Data truncated.\n");
	}

	if (sqlca.sqlwarn[3] == 'W')
	{
		fprintf(stderr, 
			"\n** Insufficient host variables to store results.\n");
	}	
	return;
}


           /*
           ** Generated code begins here.
           */
# line 386 "example1.cp"

           /*
           ** Generated code ends here.
           */
# line 386 "example1.cp"
