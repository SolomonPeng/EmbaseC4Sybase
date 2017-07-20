
/*
** Generated code begins here.
*/
# line 1 "example2.cp"

/*
** This file was generated on Tue May 15 16:35:19 2007
**  by Sybase Embedded SQL Preprocessor Sybase ESQL/C Precompiler/12.5/P/SPARC/
** Solaris 2.8/BUILD125-005/64bit/OPT/Sat May 19 07:50:03 2001
*/
# line 1 "example2.cp"
# line 1 "example2.cp"
#define _SQL_SCOPE extern
# line 1 "example2.cp"
#include <sybhesql.h>

/*
** Generated code ends here.
*/
# line 1 "example2.cp"
/*
**    example2.cp
**
**	This example displays and allows user to edit
**	rows in the authors table in the pubs2 database. 
*/
#include <stdio.h>
#include "sybsqlex.h"

/* Declare the SQLCA. */

/*
** SQL STATEMENT: 1
** EXEC SQL INCLUDE SQLCA;

*/
# line 11 "example2.cp"
# line 11 "example2.cp"
SQLCA sqlca;

/*
** Generated code ends here.
*/
# line 11 "example2.cp"


#define  EOLN	'\0'

int 	MoreRows = 1;

/* 
** Forward declarations of the error and message handlers and
** other subroutines.
*/
void	error_handler();
void	warning_handler();
void	notfound_handler();
void	put_field();
void	get_field();


main()
{
	
           /*
           ** SQL STATEMENT: 1
           ** EXEC SQL BEGIN DECLARE SECTION;

           */
# line 30 "example2.cp"

	/* Storage for login name and password. */
	char	username[30];
	char	password[30];

	/* Storage for columns in the authors table. */
	char	m_au_id[13];
	char	m_au_lname[41];
	char	m_au_fname[21];
	char	m_phone[13];
	char	m_address[41];
	char	m_city[21];
	char	m_state[3];
	char	m_zip[11];
	
           /*
           ** SQL STATEMENT: 2
           ** EXEC SQL END DECLARE SECTION;

           */
# line 44 "example2.cp"

           /*
           ** Generated code ends here.
           */
# line 44 "example2.cp"


	/* buffer for responses */
	char	buf[10];


	
           /*
           ** SQL STATEMENT: 3
           ** EXEC SQL WHENEVER SQLERROR CALL error_handler();
           */
# line 50 "example2.cp"

	
           /*
           ** SQL STATEMENT: 4
           ** EXEC SQL WHENEVER SQLWARNING CALL warning_handler();
           */
# line 51 "example2.cp"

	
           /*
           ** SQL STATEMENT: 5
           ** EXEC SQL WHENEVER NOT FOUND CALL notfound_handler();
           */
# line 52 "example2.cp"


	/* 
	** Copy the user name and password defined in sybsqlex.h to
	** the variables declared for them in the declare section. 
	*/
	strcpy(username, USER);
	strcpy(password, PASSWORD);
	strcpy(buf,"");

	
           /*
           ** SQL STATEMENT: 6
           ** EXEC SQL CONNECT :username IDENTIFIED BY :password;
           */
# line 62 "example2.cp"
# line 62 "example2.cp"
           {
# line 62 "example2.cp"
                _SQL_CT_HANDLES * _sql;
# line 62 "example2.cp"
               _sqlinitctx(&_sql, CS_VERSION_125, CS_TRUE, &sqlca, (long 
# line 62 "example2.cp"
                   *)NULL, (CS_CHAR *)NULL);
# line 62 "example2.cp"
               if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 62 "example2.cp"
               {
# line 62 "example2.cp"
                   _sql->stmtData.persistent = CS_FALSE;
# line 62 "example2.cp"
                   _sql->stmttype = SQL_NONANSI_CONNECT;
# line 62 "example2.cp"
                   _sql->connName.lnlen = 7;
# line 62 "example2.cp"
                   strcpy(_sql->connName.last_name, "DEFAULT");
# line 62 "example2.cp"
                   if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 62 "example2.cp"
                   {
# line 62 "example2.cp"
                       if (_sql->doDecl == CS_TRUE)
# line 62 "example2.cp"
                       {
# line 62 "example2.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 62 "example2.cp"
                           {
# line 62 "example2.cp"
                               _sql->retcode = 
# line 62 "example2.cp"
                                   ct_con_props(_sql->conn.connection, CS_SET, 
# line 62 "example2.cp"
                                   CS_USERNAME, username, CS_NULLTERM, NULL);
# line 62 "example2.cp"
                           }
# line 62 "example2.cp"
                           
# line 62 "example2.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 62 "example2.cp"
                           {
# line 62 "example2.cp"
                               _sql->retcode = 
# line 62 "example2.cp"
                                   ct_con_props(_sql->conn.connection, CS_SET, 
# line 62 "example2.cp"
                                   CS_PASSWORD, password, CS_NULLTERM, NULL);
# line 62 "example2.cp"
                           }
# line 62 "example2.cp"
                           
# line 62 "example2.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 62 "example2.cp"
                           {
# line 62 "example2.cp"
                               _sql->retcode = _sqlctdiag(_sql, CS_CLEAR, 
# line 62 "example2.cp"
                                   CS_UNUSED);
# line 62 "example2.cp"
                           }
# line 62 "example2.cp"
                           
# line 62 "example2.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 62 "example2.cp"
                           {
# line 62 "example2.cp"
                               _sql->retcode = 
# line 62 "example2.cp"
                                   ct_capability(_sql->conn.connection, CS_SET,
# line 62 "example2.cp"
                                    CS_CAP_RESPONSE, CS_RES_NOSTRIPBLANKS, 
# line 62 "example2.cp"
                                   &_sql->cstrue);
# line 62 "example2.cp"
                           }
# line 62 "example2.cp"
                           
# line 62 "example2.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 62 "example2.cp"
                           {
# line 62 "example2.cp"
                               _sql->retcode = 
# line 62 "example2.cp"
                                   ct_con_props(_sql->conn.connection, CS_SET, 
# line 62 "example2.cp"
                                   CS_EXTRA_INF, &_sql->cstrue, CS_UNUSED, 
# line 62 "example2.cp"
                                   NULL);
# line 62 "example2.cp"
                           }
# line 62 "example2.cp"
                           
# line 62 "example2.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 62 "example2.cp"
                           {
# line 62 "example2.cp"
                               _sql->retcode = 
# line 62 "example2.cp"
                                   ct_con_props(_sql->conn.connection, CS_SET, 
# line 62 "example2.cp"
                                   CS_ANSI_BINDS, &_sql->cstrue, CS_UNUSED, 
# line 62 "example2.cp"
                                   NULL);
# line 62 "example2.cp"
                           }
# line 62 "example2.cp"
                           
# line 62 "example2.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 62 "example2.cp"
                           {
# line 62 "example2.cp"
                               _sql->retcode = 
# line 62 "example2.cp"
                                   ct_connect(_sql->conn.connection, NULL, 0);
# line 62 "example2.cp"
                           }
# line 62 "example2.cp"
                           
# line 62 "example2.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 62 "example2.cp"
                           {
# line 62 "example2.cp"
                               _sql->retcode = 
# line 62 "example2.cp"
                                   ct_con_props(_sql->conn.connection, CS_GET, 
# line 62 "example2.cp"
                                   CS_TDS_VERSION, &_sql->temp_int, CS_UNUSED, 
# line 62 "example2.cp"
                                   &_sql->outlen);
# line 62 "example2.cp"
                               if (_sql->retcode == CS_SUCCEED)
# line 62 "example2.cp"
                               {
# line 62 "example2.cp"
                                   if (_sql->temp_int < CS_TDS_50)
# line 62 "example2.cp"
                                   {
# line 62 "example2.cp"
                                       _sqlsetintrerr(_sql, (CS_INT) 
# line 62 "example2.cp"
                                           _SQL_INTRERR_25013);
# line 62 "example2.cp"
                                   }
# line 62 "example2.cp"
                                   
# line 62 "example2.cp"
                               }
# line 62 "example2.cp"
                               
# line 62 "example2.cp"
                           }
# line 62 "example2.cp"
                           
# line 62 "example2.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 62 "example2.cp"
                           {
# line 62 "example2.cp"
                               _sql->retcode = 
# line 62 "example2.cp"
                                   ct_options(_sql->conn.connection, CS_SET, 
# line 62 "example2.cp"
                                   CS_OPT_ANSINULL, &_sql->cstrue, CS_UNUSED, 
# line 62 "example2.cp"
                                   NULL);
# line 62 "example2.cp"
                           }
# line 62 "example2.cp"
                           
# line 62 "example2.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 62 "example2.cp"
                           {
# line 62 "example2.cp"
                               _sql->retcode = 
# line 62 "example2.cp"
                                   ct_options(_sql->conn.connection, CS_SET, 
# line 62 "example2.cp"
                                   CS_OPT_ANSIPERM, &_sql->cstrue, CS_UNUSED, 
# line 62 "example2.cp"
                                   NULL);
# line 62 "example2.cp"
                               _sql->retcode = CS_SUCCEED;
# line 62 "example2.cp"
                           }
# line 62 "example2.cp"
                           
# line 62 "example2.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 62 "example2.cp"
                           {
# line 62 "example2.cp"
                               _sql->retcode = 
# line 62 "example2.cp"
                                   ct_options(_sql->conn.connection, CS_SET, 
# line 62 "example2.cp"
                                   CS_OPT_STR_RTRUNC, &_sql->cstrue, CS_UNUSED,
# line 62 "example2.cp"
                                    NULL);
# line 62 "example2.cp"
                               _sql->retcode = CS_SUCCEED;
# line 62 "example2.cp"
                           }
# line 62 "example2.cp"
                           
# line 62 "example2.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 62 "example2.cp"
                           {
# line 62 "example2.cp"
                               _sql->retcode = 
# line 62 "example2.cp"
                                   ct_options(_sql->conn.connection, CS_SET, 
# line 62 "example2.cp"
                                   CS_OPT_ISOLATION, &_sql->Level3, CS_UNUSED, 
# line 62 "example2.cp"
                                   NULL);
# line 62 "example2.cp"
                           }
# line 62 "example2.cp"
                           
# line 62 "example2.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 62 "example2.cp"
                           {
# line 62 "example2.cp"
                               _sql->retcode = 
# line 62 "example2.cp"
                                   ct_options(_sql->conn.connection, CS_SET, 
# line 62 "example2.cp"
                                   CS_OPT_CURCLOSEONXACT, &_sql->cstrue, 
# line 62 "example2.cp"
                                   CS_UNUSED, NULL);
# line 62 "example2.cp"
                           }
# line 62 "example2.cp"
                           
# line 62 "example2.cp"
                           if (_sql->retcode == CS_SUCCEED)
# line 62 "example2.cp"
                           {
# line 62 "example2.cp"
                               _sql->retcode = 
# line 62 "example2.cp"
                                   ct_options(_sql->conn.connection, CS_SET, 
# line 62 "example2.cp"
                                   CS_OPT_QUOTED_IDENT, &_sql->cstrue, 
# line 62 "example2.cp"
                                   CS_UNUSED, NULL);
# line 62 "example2.cp"
                           }
# line 62 "example2.cp"
                           
# line 62 "example2.cp"
                           _sql->retcode = _sqlepilog(_sql);
# line 62 "example2.cp"
                       }
# line 62 "example2.cp"
                       
# line 62 "example2.cp"
                   }
# line 62 "example2.cp"
                   
# line 62 "example2.cp"
                   if (sqlca.sqlcode < 0)
# line 62 "example2.cp"
                   {
# line 62 "example2.cp"
                       error_handler();
# line 62 "example2.cp"
                   }
# line 62 "example2.cp"
                   
# line 62 "example2.cp"
                   if (sqlca.sqlwarn[0] == 'W')
# line 62 "example2.cp"
                   {
# line 62 "example2.cp"
                       warning_handler();
# line 62 "example2.cp"
                   }
# line 62 "example2.cp"
                   
# line 62 "example2.cp"
                   if (sqlca.sqlcode == 100)
# line 62 "example2.cp"
                   {
# line 62 "example2.cp"
                       notfound_handler();
# line 62 "example2.cp"
                   }
# line 62 "example2.cp"
                   
# line 62 "example2.cp"
               }
# line 62 "example2.cp"
               
# line 62 "example2.cp"
           }
# line 62 "example2.cp"
           

           /*
           ** Generated code ends here.
           */
# line 62 "example2.cp"

		

	
           /*
           ** SQL STATEMENT: 7
           ** EXEC SQL USE pubs2;

           */
# line 65 "example2.cp"
# line 65 "example2.cp"
           {
# line 65 "example2.cp"
                _SQL_CT_HANDLES * _sql;
# line 65 "example2.cp"
               _sqlinitctx(&_sql, CS_VERSION_125, CS_TRUE, &sqlca, (long 
# line 65 "example2.cp"
                   *)NULL, (CS_CHAR *)NULL);
# line 65 "example2.cp"
               if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 65 "example2.cp"
               {
# line 65 "example2.cp"
                   _sql->stmtIdlen = CS_UNUSED;
# line 65 "example2.cp"
                   _sql->stmtData.persistent = CS_FALSE;
# line 65 "example2.cp"
                   _sql->stmttype = SQL_MISC;
# line 65 "example2.cp"
                   _sql->connName.lnlen = CS_UNUSED;
# line 65 "example2.cp"
                   if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 65 "example2.cp"
                   {
# line 65 "example2.cp"
                       _sql->retcode = ct_command(_sql->conn.command, 
# line 65 "example2.cp"
                           CS_LANG_CMD, "USE pubs2", 9, CS_UNUSED);
# line 65 "example2.cp"
                       _sql->retcode = ct_send(_sql->conn.command);
# line 65 "example2.cp"
                       _sql->retcode = _sqlResults(_sql);
# line 65 "example2.cp"
                       _sql->retcode = _sqlepilog(_sql);
# line 65 "example2.cp"
                   }
# line 65 "example2.cp"
                   
# line 65 "example2.cp"
                   if (sqlca.sqlcode < 0)
# line 65 "example2.cp"
                   {
# line 65 "example2.cp"
                       error_handler();
# line 65 "example2.cp"
                   }
# line 65 "example2.cp"
                   
# line 65 "example2.cp"
                   if (sqlca.sqlwarn[0] == 'W')
# line 65 "example2.cp"
                   {
# line 65 "example2.cp"
                       warning_handler();
# line 65 "example2.cp"
                   }
# line 65 "example2.cp"
                   
# line 65 "example2.cp"
                   if (sqlca.sqlcode == 100)
# line 65 "example2.cp"
                   {
# line 65 "example2.cp"
                       notfound_handler();
# line 65 "example2.cp"
                   }
# line 65 "example2.cp"
                   
# line 65 "example2.cp"
               }
# line 65 "example2.cp"
               
# line 65 "example2.cp"
           }
# line 65 "example2.cp"
           

           /*
           ** Generated code ends here.
           */
# line 65 "example2.cp"


	
              /*
              ** SQL STATEMENT: 8
              ** EXEC SQL 
              ** 	DECLARE authors CURSOR FOR
              ** 		SELECT	au_id, au_lname, au_fname, 
              ** 			phone, address, city, state, 
              ** 			postalcode
              ** 		FROM 	authors;

              */
# line 72 "example2.cp"


	
              /*
              ** SQL STATEMENT: 9
              ** EXEC SQL OPEN authors;

              */
# line 74 "example2.cp"
# line 74 "example2.cp"
              {
# line 74 "example2.cp"
                   _SQL_CT_HANDLES * _sql;
# line 74 "example2.cp"
                  _sqlinitctx(&_sql, CS_VERSION_125, CS_TRUE, &sqlca, (long 
# line 74 "example2.cp"
                      *)NULL, (CS_CHAR *)NULL);
# line 74 "example2.cp"
                  if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 74 "example2.cp"
                  {
# line 74 "example2.cp"
                      _sql->stmtData.persistent = CS_FALSE;
# line 74 "example2.cp"
                      _sql->moreData.curData.norebind = CS_FALSE;
# line 74 "example2.cp"
                      _sql->stmttype = SQL_OPEN_STMT;
# line 74 "example2.cp"
                      _sql->connName.lnlen = CS_UNUSED;
# line 74 "example2.cp"
                      _sql->curName.fnlen = 7;
# line 74 "example2.cp"
                      strcpy(_sql->curName.first_name, "authors");
# line 74 "example2.cp"
                      if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 74 "example2.cp"
                      {
# line 74 "example2.cp"
                          if (_sql->doDecl == CS_TRUE)
# line 74 "example2.cp"
                          {
# line 74 "example2.cp"
                              _sql->retcode = ct_cursor(_sql->conn.command, 
# line 74 "example2.cp"
                                  CS_CURSOR_DECLARE, "authors", 7, "SELECT"
"	au_id, au_lname, au_fname,  			phone, address, city, "
"state,  			postalcode 		FROM 	authors", 97, 
# line 74 "example2.cp"
                                  CS_UNUSED);
# line 74 "example2.cp"
                          }
# line 74 "example2.cp"
                          
# line 74 "example2.cp"
                          if (_sql->retcode == CS_SUCCEED)
# line 74 "example2.cp"
                          {
# line 74 "example2.cp"
                              if (_sql->stmtData.persistent == CS_TRUE)
# line 74 "example2.cp"
                              {
# line 74 "example2.cp"
                                  _sql->retcode = ct_cursor(_sql->conn.command,
# line 74 "example2.cp"
                                       CS_CURSOR_OPEN, NULL, CS_UNUSED, NULL, 
# line 74 "example2.cp"
                                      CS_UNUSED, CS_RESTORE_OPEN);
# line 74 "example2.cp"
                                  }
# line 74 "example2.cp"
                                   else {
# line 74 "example2.cp"
                                  _sql->retcode = ct_cursor(_sql->conn.command,
# line 74 "example2.cp"
                                       CS_CURSOR_OPEN, NULL, CS_UNUSED, NULL, 
# line 74 "example2.cp"
                                      CS_UNUSED, CS_UNUSED);
# line 74 "example2.cp"
                              }
# line 74 "example2.cp"
                              
# line 74 "example2.cp"
                          }
# line 74 "example2.cp"
                          
# line 74 "example2.cp"
                          if (_sql->retcode == CS_SUCCEED)
# line 74 "example2.cp"
                          {
# line 74 "example2.cp"
                              _sql->retcode = ct_send(_sql->conn.command);
# line 74 "example2.cp"
                          }
# line 74 "example2.cp"
                          
# line 74 "example2.cp"
                          _sql->resloop = CS_TRUE;
# line 74 "example2.cp"
                          while ((_sql->resloop == CS_TRUE) && (_sql->retcode 
# line 74 "example2.cp"
                              = ct_results(_sql->conn.command, 
# line 74 "example2.cp"
                              &_sql->restype)) == CS_SUCCEED)
# line 74 "example2.cp"
                          {
# line 74 "example2.cp"
                              switch ( _sql->restype )
# line 74 "example2.cp"
                              {
# line 74 "example2.cp"
                              case CS_COMPUTE_RESULT:
# line 74 "example2.cp"
                                  _sqlsetintrerr(_sql, (CS_INT) 
# line 74 "example2.cp"
                                      _SQL_INTRERR_25003);
# line 74 "example2.cp"
                                  _sql->retcode = ct_cancel(NULL, 
# line 74 "example2.cp"
                                      _sql->conn.command, CS_CANCEL_CURRENT);
# line 74 "example2.cp"
                              break;
# line 74 "example2.cp"
                              case CS_CURSOR_RESULT:
# line 74 "example2.cp"
                                  _sql->resloop = CS_FALSE;
# line 74 "example2.cp"
                              break;
# line 74 "example2.cp"
                              case CS_PARAM_RESULT:
# line 74 "example2.cp"
                                  _sqlsetintrerr(_sql, (CS_INT) 
# line 74 "example2.cp"
                                      _SQL_INTRERR_25005);
# line 74 "example2.cp"
                                  _sql->retcode = ct_cancel(NULL, 
# line 74 "example2.cp"
                                      _sql->conn.command, CS_CANCEL_CURRENT);
# line 74 "example2.cp"
                              break;
# line 74 "example2.cp"
                              case CS_ROW_RESULT:
# line 74 "example2.cp"
                                  _sqlsetintrerr(_sql, (CS_INT) 
# line 74 "example2.cp"
                                      _SQL_INTRERR_25006);
# line 74 "example2.cp"
                                  _sql->retcode = ct_cancel(NULL, 
# line 74 "example2.cp"
                                      _sql->conn.command, CS_CANCEL_CURRENT);
# line 74 "example2.cp"
                              break;
# line 74 "example2.cp"
                              case CS_STATUS_RESULT:
# line 74 "example2.cp"
                                  _sqlsetintrerr(_sql, (CS_INT) 
# line 74 "example2.cp"
                                      _SQL_INTRERR_25009);
# line 74 "example2.cp"
                                  _sql->retcode = ct_cancel(NULL, 
# line 74 "example2.cp"
                                      _sql->conn.command, CS_CANCEL_CURRENT);
# line 74 "example2.cp"
                              break;
# line 74 "example2.cp"
                              case CS_DESCRIBE_RESULT:
# line 74 "example2.cp"
                                  _sqlsetintrerr(_sql, (CS_INT) 
# line 74 "example2.cp"
                                      _SQL_INTRERR_25010);
# line 74 "example2.cp"
                              break;
# line 74 "example2.cp"
                              }
# line 74 "example2.cp"
                              
# line 74 "example2.cp"
                          }
# line 74 "example2.cp"
                          
# line 74 "example2.cp"
                          _sql->retcode = _sqlepilog(_sql);
# line 74 "example2.cp"
                      }
# line 74 "example2.cp"
                      
# line 74 "example2.cp"
                      if (sqlca.sqlcode < 0)
# line 74 "example2.cp"
                      {
# line 74 "example2.cp"
                          error_handler();
# line 74 "example2.cp"
                      }
# line 74 "example2.cp"
                      
# line 74 "example2.cp"
                      if (sqlca.sqlwarn[0] == 'W')
# line 74 "example2.cp"
                      {
# line 74 "example2.cp"
                          warning_handler();
# line 74 "example2.cp"
                      }
# line 74 "example2.cp"
                      
# line 74 "example2.cp"
                      if (sqlca.sqlcode == 100)
# line 74 "example2.cp"
                      {
# line 74 "example2.cp"
                          notfound_handler();
# line 74 "example2.cp"
                      }
# line 74 "example2.cp"
                      
# line 74 "example2.cp"
                  }
# line 74 "example2.cp"
                  
# line 74 "example2.cp"
              }
# line 74 "example2.cp"
              

              /*
              ** Generated code ends here.
              */
# line 74 "example2.cp"


	/*
	** This loop controls the entry.
	*/

	while ( MoreRows )
	{
		if (*buf == 'Q' || *buf == 'q')
			break;

		
              /*
              ** SQL STATEMENT: 10
              ** EXEC SQL 
              ** 		FETCH authors INTO
              ** 			:m_au_id, :m_au_lname, :m_au_fname, 
              ** 			:m_phone, :m_address, :m_city, 
              ** 			:m_state, :m_zip;
              */
# line 89 "example2.cp"
# line 85 "example2.cp"
              {
# line 85 "example2.cp"
                   _SQL_CT_HANDLES * _sql;
# line 85 "example2.cp"
                  _sqlinitctx(&_sql, CS_VERSION_125, CS_TRUE, &sqlca, (long 
# line 85 "example2.cp"
                      *)NULL, (CS_CHAR *)NULL);
# line 85 "example2.cp"
                  if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 85 "example2.cp"
                  {
# line 85 "example2.cp"
                      _sql->stmtData.persistent = CS_FALSE;
# line 85 "example2.cp"
                      _sql->stmttype = SQL_FETCH_STMT;
# line 85 "example2.cp"
                      _sql->connName.lnlen = CS_UNUSED;
# line 85 "example2.cp"
                      _sql->curName.fnlen = 7;
# line 85 "example2.cp"
                      strcpy(_sql->curName.first_name, "authors");
# line 85 "example2.cp"
                      if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 85 "example2.cp"
                      {
# line 85 "example2.cp"
                          _sql->doDecl = CS_FALSE;
# line 85 "example2.cp"
                          if ((_sql->stmtData.bind == CS_TRUE) ||
# line 85 "example2.cp"
                          (_sql->moreData.curData.norebind == CS_FALSE))
# line 85 "example2.cp"
                          {
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.format = (CS_FMT_NULLTERM 
# line 85 "example2.cp"
                                  | CS_FMT_PADBLANK);
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.maxlength = 13;
# line 85 "example2.cp"
                                  _sql->retcode = ct_bind(_sql->conn.command, 
# line 85 "example2.cp"
                                      1, &_sql->dfmtCS_CHAR_TYPE, m_au_id, 
# line 85 "example2.cp"
                                      NULL, NULL);
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.format = (CS_FMT_NULLTERM 
# line 85 "example2.cp"
                                  | CS_FMT_PADBLANK);
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.maxlength = 41;
# line 85 "example2.cp"
                                  _sql->retcode = ct_bind(_sql->conn.command, 
# line 85 "example2.cp"
                                      2, &_sql->dfmtCS_CHAR_TYPE, m_au_lname, 
# line 85 "example2.cp"
                                      NULL, NULL);
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.format = (CS_FMT_NULLTERM 
# line 85 "example2.cp"
                                  | CS_FMT_PADBLANK);
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.maxlength = 21;
# line 85 "example2.cp"
                                  _sql->retcode = ct_bind(_sql->conn.command, 
# line 85 "example2.cp"
                                      3, &_sql->dfmtCS_CHAR_TYPE, m_au_fname, 
# line 85 "example2.cp"
                                      NULL, NULL);
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.format = (CS_FMT_NULLTERM 
# line 85 "example2.cp"
                                  | CS_FMT_PADBLANK);
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.maxlength = 13;
# line 85 "example2.cp"
                                  _sql->retcode = ct_bind(_sql->conn.command, 
# line 85 "example2.cp"
                                      4, &_sql->dfmtCS_CHAR_TYPE, m_phone, 
# line 85 "example2.cp"
                                      NULL, NULL);
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.format = (CS_FMT_NULLTERM 
# line 85 "example2.cp"
                                  | CS_FMT_PADBLANK);
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.maxlength = 41;
# line 85 "example2.cp"
                                  _sql->retcode = ct_bind(_sql->conn.command, 
# line 85 "example2.cp"
                                      5, &_sql->dfmtCS_CHAR_TYPE, m_address, 
# line 85 "example2.cp"
                                      NULL, NULL);
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.format = (CS_FMT_NULLTERM 
# line 85 "example2.cp"
                                  | CS_FMT_PADBLANK);
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.maxlength = 21;
# line 85 "example2.cp"
                                  _sql->retcode = ct_bind(_sql->conn.command, 
# line 85 "example2.cp"
                                      6, &_sql->dfmtCS_CHAR_TYPE, m_city, NULL,
# line 85 "example2.cp"
                                       NULL);
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.format = (CS_FMT_NULLTERM 
# line 85 "example2.cp"
                                  | CS_FMT_PADBLANK);
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.maxlength = 3;
# line 85 "example2.cp"
                                  _sql->retcode = ct_bind(_sql->conn.command, 
# line 85 "example2.cp"
                                      7, &_sql->dfmtCS_CHAR_TYPE, m_state, 
# line 85 "example2.cp"
                                      NULL, NULL);
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.format = (CS_FMT_NULLTERM 
# line 85 "example2.cp"
                                  | CS_FMT_PADBLANK);
# line 85 "example2.cp"
                              _sql->dfmtCS_CHAR_TYPE.maxlength = 11;
# line 85 "example2.cp"
                                  _sql->retcode = ct_bind(_sql->conn.command, 
# line 85 "example2.cp"
                                      8, &_sql->dfmtCS_CHAR_TYPE, m_zip, NULL, 
# line 85 "example2.cp"
                                      NULL);
# line 85 "example2.cp"
                              if (_sql->stmtData.bind == CS_TRUE)
# line 85 "example2.cp"
                              {
# line 85 "example2.cp"
                                  _sql->stmtData.bind = CS_FALSE;
# line 85 "example2.cp"
                                  _sql->doDecl = CS_TRUE;
# line 85 "example2.cp"
                              }
# line 85 "example2.cp"
                              
# line 85 "example2.cp"
                          }
# line 85 "example2.cp"
                          
# line 85 "example2.cp"
                          _sql->retcode = ct_fetch(_sql->conn.command, 
# line 85 "example2.cp"
                              CS_UNUSED, CS_UNUSED, CS_UNUSED, 
# line 85 "example2.cp"
                              &_sql->rowsread);
# line 85 "example2.cp"
                          if (_sql->retcode == CS_END_DATA)
# line 85 "example2.cp"
                          {
# line 85 "example2.cp"
                              _sql->retcode = _sqlResults(_sql);
# line 85 "example2.cp"
                          }
# line 85 "example2.cp"
                          
# line 85 "example2.cp"
                          _sql->retcode = _sqlepilog(_sql);
# line 85 "example2.cp"
                      }
# line 85 "example2.cp"
                      
# line 85 "example2.cp"
                      if (sqlca.sqlcode < 0)
# line 85 "example2.cp"
                      {
# line 85 "example2.cp"
                          error_handler();
# line 85 "example2.cp"
                      }
# line 85 "example2.cp"
                      
# line 85 "example2.cp"
                      if (sqlca.sqlwarn[0] == 'W')
# line 85 "example2.cp"
                      {
# line 85 "example2.cp"
                          warning_handler();
# line 85 "example2.cp"
                      }
# line 85 "example2.cp"
                      
# line 85 "example2.cp"
                      if (sqlca.sqlcode == 100)
# line 85 "example2.cp"
                      {
# line 85 "example2.cp"
                          notfound_handler();
# line 85 "example2.cp"
                      }
# line 85 "example2.cp"
                      
# line 85 "example2.cp"
                  }
# line 85 "example2.cp"
                  
# line 85 "example2.cp"
              }
# line 85 "example2.cp"
              

              /*
              ** Generated code ends here.
              */
# line 89 "example2.cp"


		if ( MoreRows )
		{
			put_field("au_id",  m_au_id);	
			put_field("au_lname", m_au_lname);
			put_field("au_fname", m_au_fname);
			put_field("phone", m_phone);
			put_field("address", m_address);
			put_field("city", m_city);
			put_field("state", m_state);
			put_field("zip", m_zip);

			printf("\n\n[E]dit, [N]ext, [Q]uit ");
			gets(buf);
			switch (*buf)
			{
			case 'e':
			case 'E':
				put_field("au_id",  m_au_id);	
				get_field("au_lname", m_au_lname);
				get_field("au_fname", m_au_fname);
				get_field("phone", m_phone);
				get_field("address", m_address);
				get_field("city", m_city);
				get_field("state", m_state);
				get_field("zip", m_zip);
	
				printf("\n\n");
				put_field("au_id",  m_au_id);	
				put_field("au_lname", m_au_lname);
				put_field("au_fname", m_au_fname);
				put_field("phone", m_phone);
				put_field("address", m_address);
				put_field("city", m_city);
				put_field("state", m_state);
				put_field("zip", m_zip);
				printf("\n\nUpdate? ");
				gets(buf);
				if (*buf == 'Y' || *buf == 'y')
				{
					
                 /*
                 ** SQL STATEMENT: 11
                 ** EXEC SQL 
                 ** 					UPDATE authors SET
                 ** 						au_lname = :m_au_lname,
                 ** 						au_fname = :m_au_fname,
                 ** 						phone = :m_phone,
                 ** 						address = :m_address,
                 ** 						city = :m_city,
                 ** 						state = :m_state,
                 ** 						postalcode = :m_zip
                 ** 					WHERE CURRENT OF authors;

                 */
# line 139 "example2.cp"
# line 130 "example2.cp"
                 {
# line 130 "example2.cp"
                      _SQL_CT_HANDLES * _sql;
# line 130 "example2.cp"
                     _sqlinitctx(&_sql, CS_VERSION_125, CS_TRUE, &sqlca, (long 
# line 130 "example2.cp"
                         *)NULL, (CS_CHAR *)NULL);
# line 130 "example2.cp"
                     if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 130 "example2.cp"
                     {
# line 130 "example2.cp"
                         _sql->stmtData.persistent = CS_FALSE;
# line 130 "example2.cp"
                         _sql->stmttype = SQL_UPDATE_POSITIONED;
# line 130 "example2.cp"
                         _sql->connName.lnlen = CS_UNUSED;
# line 130 "example2.cp"
                         _sql->curName.fnlen = 7;
# line 130 "example2.cp"
                         strcpy(_sql->curName.first_name, "authors");
# line 130 "example2.cp"
                         if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 130 "example2.cp"
                         {
# line 130 "example2.cp"
                             if (_sql->stmtData.param != _SQL_PARAM_UPDATE)
# line 130 "example2.cp"
                             {
# line 130 "example2.cp"
                                 _sql->retcode = ct_cursor(_sql->conn.command, 
# line 130 "example2.cp"
                                     CS_CURSOR_UPDATE, "authors", 7, "UPDATE au"
"thors SET au_lname = @sql0_m_au_lname , 				"
"		au_fname = @sql1_m_au_fname , 				"
"		phone = @sql2_m_phone , 				"
"		address = @sql3_m_address , 				"
"		city = @sql4_m_city , 					"
"	state = @sql5_m_state , 					"
"	postalcode = @sql6_m_zip ", 238, CS_UNUSED);
# line 130 "example2.cp"
                             }
# line 130 "example2.cp"
                             
# line 130 "example2.cp"
                             if (_sql->stmtData.param != _SQL_PARAM_UPDATE)
# line 130 "example2.cp"
                             {
# line 130 "example2.cp"
                                 if (_sql->retcode == CS_SUCCEED)
# line 130 "example2.cp"
                                 {
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.format = 
# line 130 "example2.cp"
                                         (CS_FMT_NULLTERM | CS_FMT_PADBLANK);
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.maxlength = 41;
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.status = 
# line 130 "example2.cp"
                                         CS_INPUTVALUE;
# line 130 "example2.cp"
                                     if (_sql->stmtData.persistent == CS_TRUE)
# line 130 "example2.cp"
                                     {
# line 130 "example2.cp"
                                         _sql->retcode = 
# line 130 "example2.cp"
                                             ct_setparam(_sql->conn.command, 
# line 130 "example2.cp"
                                             &_sql->dfmtCS_CHAR_TYPE, 
# line 130 "example2.cp"
                                             _sqlcheckstr(_sql, 
# line 130 "example2.cp"
                                         SQLNULLSTR(m_au_lname)), 
# line 130 "example2.cp"
                                             &(_sql->csnullterm), 
# line 130 "example2.cp"
                                             &(_sql->cszeroind));
# line 130 "example2.cp"
                                         }
# line 130 "example2.cp"
                                          else {
# line 130 "example2.cp"
                                         _sql->retcode = 
# line 130 "example2.cp"
                                             ct_param(_sql->conn.command, 
# line 130 "example2.cp"
                                             &_sql->dfmtCS_CHAR_TYPE, 
# line 130 "example2.cp"
                                             _sqlcheckstr(_sql, 
# line 130 "example2.cp"
                                         SQLNULLSTR(m_au_lname)), (CS_INT) 
# line 130 "example2.cp"
                                             _sql->csnullterm, (CS_SMALLINT) 
# line 130 "example2.cp"
                                             _sql->cszeroind);
# line 130 "example2.cp"
                                     }
# line 130 "example2.cp"
                                     
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.status = 0;
# line 130 "example2.cp"
                                 }
# line 130 "example2.cp"
                                 
# line 130 "example2.cp"
                                 if (_sql->retcode == CS_SUCCEED)
# line 130 "example2.cp"
                                 {
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.format = 
# line 130 "example2.cp"
                                         (CS_FMT_NULLTERM | CS_FMT_PADBLANK);
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.maxlength = 21;
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.status = 
# line 130 "example2.cp"
                                         CS_INPUTVALUE;
# line 130 "example2.cp"
                                     if (_sql->stmtData.persistent == CS_TRUE)
# line 130 "example2.cp"
                                     {
# line 130 "example2.cp"
                                         _sql->retcode = 
# line 130 "example2.cp"
                                             ct_setparam(_sql->conn.command, 
# line 130 "example2.cp"
                                             &_sql->dfmtCS_CHAR_TYPE, 
# line 130 "example2.cp"
                                             _sqlcheckstr(_sql, 
# line 130 "example2.cp"
                                         SQLNULLSTR(m_au_fname)), 
# line 130 "example2.cp"
                                             &(_sql->csnullterm), 
# line 130 "example2.cp"
                                             &(_sql->cszeroind));
# line 130 "example2.cp"
                                         }
# line 130 "example2.cp"
                                          else {
# line 130 "example2.cp"
                                         _sql->retcode = 
# line 130 "example2.cp"
                                             ct_param(_sql->conn.command, 
# line 130 "example2.cp"
                                             &_sql->dfmtCS_CHAR_TYPE, 
# line 130 "example2.cp"
                                             _sqlcheckstr(_sql, 
# line 130 "example2.cp"
                                         SQLNULLSTR(m_au_fname)), (CS_INT) 
# line 130 "example2.cp"
                                             _sql->csnullterm, (CS_SMALLINT) 
# line 130 "example2.cp"
                                             _sql->cszeroind);
# line 130 "example2.cp"
                                     }
# line 130 "example2.cp"
                                     
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.status = 0;
# line 130 "example2.cp"
                                 }
# line 130 "example2.cp"
                                 
# line 130 "example2.cp"
                                 if (_sql->retcode == CS_SUCCEED)
# line 130 "example2.cp"
                                 {
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.format = 
# line 130 "example2.cp"
                                         (CS_FMT_NULLTERM | CS_FMT_PADBLANK);
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.maxlength = 13;
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.status = 
# line 130 "example2.cp"
                                         CS_INPUTVALUE;
# line 130 "example2.cp"
                                     if (_sql->stmtData.persistent == CS_TRUE)
# line 130 "example2.cp"
                                     {
# line 130 "example2.cp"
                                         _sql->retcode = 
# line 130 "example2.cp"
                                             ct_setparam(_sql->conn.command, 
# line 130 "example2.cp"
                                             &_sql->dfmtCS_CHAR_TYPE, 
# line 130 "example2.cp"
                                             _sqlcheckstr(_sql, 
# line 130 "example2.cp"
                                         SQLNULLSTR(m_phone)), 
# line 130 "example2.cp"
                                             &(_sql->csnullterm), 
# line 130 "example2.cp"
                                             &(_sql->cszeroind));
# line 130 "example2.cp"
                                         }
# line 130 "example2.cp"
                                          else {
# line 130 "example2.cp"
                                         _sql->retcode = 
# line 130 "example2.cp"
                                             ct_param(_sql->conn.command, 
# line 130 "example2.cp"
                                             &_sql->dfmtCS_CHAR_TYPE, 
# line 130 "example2.cp"
                                             _sqlcheckstr(_sql, 
# line 130 "example2.cp"
                                         SQLNULLSTR(m_phone)), (CS_INT) 
# line 130 "example2.cp"
                                             _sql->csnullterm, (CS_SMALLINT) 
# line 130 "example2.cp"
                                             _sql->cszeroind);
# line 130 "example2.cp"
                                     }
# line 130 "example2.cp"
                                     
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.status = 0;
# line 130 "example2.cp"
                                 }
# line 130 "example2.cp"
                                 
# line 130 "example2.cp"
                                 if (_sql->retcode == CS_SUCCEED)
# line 130 "example2.cp"
                                 {
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.format = 
# line 130 "example2.cp"
                                         (CS_FMT_NULLTERM | CS_FMT_PADBLANK);
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.maxlength = 41;
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.status = 
# line 130 "example2.cp"
                                         CS_INPUTVALUE;
# line 130 "example2.cp"
                                     if (_sql->stmtData.persistent == CS_TRUE)
# line 130 "example2.cp"
                                     {
# line 130 "example2.cp"
                                         _sql->retcode = 
# line 130 "example2.cp"
                                             ct_setparam(_sql->conn.command, 
# line 130 "example2.cp"
                                             &_sql->dfmtCS_CHAR_TYPE, 
# line 130 "example2.cp"
                                             _sqlcheckstr(_sql, 
# line 130 "example2.cp"
                                         SQLNULLSTR(m_address)), 
# line 130 "example2.cp"
                                             &(_sql->csnullterm), 
# line 130 "example2.cp"
                                             &(_sql->cszeroind));
# line 130 "example2.cp"
                                         }
# line 130 "example2.cp"
                                          else {
# line 130 "example2.cp"
                                         _sql->retcode = 
# line 130 "example2.cp"
                                             ct_param(_sql->conn.command, 
# line 130 "example2.cp"
                                             &_sql->dfmtCS_CHAR_TYPE, 
# line 130 "example2.cp"
                                             _sqlcheckstr(_sql, 
# line 130 "example2.cp"
                                         SQLNULLSTR(m_address)), (CS_INT) 
# line 130 "example2.cp"
                                             _sql->csnullterm, (CS_SMALLINT) 
# line 130 "example2.cp"
                                             _sql->cszeroind);
# line 130 "example2.cp"
                                     }
# line 130 "example2.cp"
                                     
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.status = 0;
# line 130 "example2.cp"
                                 }
# line 130 "example2.cp"
                                 
# line 130 "example2.cp"
                                 if (_sql->retcode == CS_SUCCEED)
# line 130 "example2.cp"
                                 {
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.format = 
# line 130 "example2.cp"
                                         (CS_FMT_NULLTERM | CS_FMT_PADBLANK);
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.maxlength = 21;
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.status = 
# line 130 "example2.cp"
                                         CS_INPUTVALUE;
# line 130 "example2.cp"
                                     if (_sql->stmtData.persistent == CS_TRUE)
# line 130 "example2.cp"
                                     {
# line 130 "example2.cp"
                                         _sql->retcode = 
# line 130 "example2.cp"
                                             ct_setparam(_sql->conn.command, 
# line 130 "example2.cp"
                                             &_sql->dfmtCS_CHAR_TYPE, 
# line 130 "example2.cp"
                                             _sqlcheckstr(_sql, 
# line 130 "example2.cp"
                                         SQLNULLSTR(m_city)), 
# line 130 "example2.cp"
                                             &(_sql->csnullterm), 
# line 130 "example2.cp"
                                             &(_sql->cszeroind));
# line 130 "example2.cp"
                                         }
# line 130 "example2.cp"
                                          else {
# line 130 "example2.cp"
                                         _sql->retcode = 
# line 130 "example2.cp"
                                             ct_param(_sql->conn.command, 
# line 130 "example2.cp"
                                             &_sql->dfmtCS_CHAR_TYPE, 
# line 130 "example2.cp"
                                             _sqlcheckstr(_sql, 
# line 130 "example2.cp"
                                         SQLNULLSTR(m_city)), (CS_INT) 
# line 130 "example2.cp"
                                             _sql->csnullterm, (CS_SMALLINT) 
# line 130 "example2.cp"
                                             _sql->cszeroind);
# line 130 "example2.cp"
                                     }
# line 130 "example2.cp"
                                     
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.status = 0;
# line 130 "example2.cp"
                                 }
# line 130 "example2.cp"
                                 
# line 130 "example2.cp"
                                 if (_sql->retcode == CS_SUCCEED)
# line 130 "example2.cp"
                                 {
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.format = 
# line 130 "example2.cp"
                                         (CS_FMT_NULLTERM | CS_FMT_PADBLANK);
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.maxlength = 3;
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.status = 
# line 130 "example2.cp"
                                         CS_INPUTVALUE;
# line 130 "example2.cp"
                                     if (_sql->stmtData.persistent == CS_TRUE)
# line 130 "example2.cp"
                                     {
# line 130 "example2.cp"
                                         _sql->retcode = 
# line 130 "example2.cp"
                                             ct_setparam(_sql->conn.command, 
# line 130 "example2.cp"
                                             &_sql->dfmtCS_CHAR_TYPE, 
# line 130 "example2.cp"
                                             _sqlcheckstr(_sql, 
# line 130 "example2.cp"
                                         SQLNULLSTR(m_state)), 
# line 130 "example2.cp"
                                             &(_sql->csnullterm), 
# line 130 "example2.cp"
                                             &(_sql->cszeroind));
# line 130 "example2.cp"
                                         }
# line 130 "example2.cp"
                                          else {
# line 130 "example2.cp"
                                         _sql->retcode = 
# line 130 "example2.cp"
                                             ct_param(_sql->conn.command, 
# line 130 "example2.cp"
                                             &_sql->dfmtCS_CHAR_TYPE, 
# line 130 "example2.cp"
                                             _sqlcheckstr(_sql, 
# line 130 "example2.cp"
                                         SQLNULLSTR(m_state)), (CS_INT) 
# line 130 "example2.cp"
                                             _sql->csnullterm, (CS_SMALLINT) 
# line 130 "example2.cp"
                                             _sql->cszeroind);
# line 130 "example2.cp"
                                     }
# line 130 "example2.cp"
                                     
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.status = 0;
# line 130 "example2.cp"
                                 }
# line 130 "example2.cp"
                                 
# line 130 "example2.cp"
                                 if (_sql->retcode == CS_SUCCEED)
# line 130 "example2.cp"
                                 {
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.count = 0;
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.format = 
# line 130 "example2.cp"
                                         (CS_FMT_NULLTERM | CS_FMT_PADBLANK);
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.maxlength = 11;
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.status = 
# line 130 "example2.cp"
                                         CS_INPUTVALUE;
# line 130 "example2.cp"
                                     if (_sql->stmtData.persistent == CS_TRUE)
# line 130 "example2.cp"
                                     {
# line 130 "example2.cp"
                                         _sql->retcode = 
# line 130 "example2.cp"
                                             ct_setparam(_sql->conn.command, 
# line 130 "example2.cp"
                                             &_sql->dfmtCS_CHAR_TYPE, 
# line 130 "example2.cp"
                                             _sqlcheckstr(_sql, 
# line 130 "example2.cp"
                                         SQLNULLSTR(m_zip)), 
# line 130 "example2.cp"
                                             &(_sql->csnullterm), 
# line 130 "example2.cp"
                                             &(_sql->cszeroind));
# line 130 "example2.cp"
                                         }
# line 130 "example2.cp"
                                          else {
# line 130 "example2.cp"
                                         _sql->retcode = 
# line 130 "example2.cp"
                                             ct_param(_sql->conn.command, 
# line 130 "example2.cp"
                                             &_sql->dfmtCS_CHAR_TYPE, 
# line 130 "example2.cp"
                                             _sqlcheckstr(_sql, 
# line 130 "example2.cp"
                                         SQLNULLSTR(m_zip)), (CS_INT) 
# line 130 "example2.cp"
                                             _sql->csnullterm, (CS_SMALLINT) 
# line 130 "example2.cp"
                                             _sql->cszeroind);
# line 130 "example2.cp"
                                     }
# line 130 "example2.cp"
                                     
# line 130 "example2.cp"
                                     _sql->dfmtCS_CHAR_TYPE.status = 0;
# line 130 "example2.cp"
                                 }
# line 130 "example2.cp"
                                 
# line 130 "example2.cp"
                             }
# line 130 "example2.cp"
                             
# line 130 "example2.cp"
                             if (_sql->retcode == CS_SUCCEED)
# line 130 "example2.cp"
                             {
# line 130 "example2.cp"
                                 _sql->retcode = ct_send(_sql->conn.command);
# line 130 "example2.cp"
                             }
# line 130 "example2.cp"
                             
# line 130 "example2.cp"
                             _sql->retcode = _sqlResults(_sql);
# line 130 "example2.cp"
                             _sql->retcode = _sqlepilog(_sql);
# line 130 "example2.cp"
                         }
# line 130 "example2.cp"
                         
# line 130 "example2.cp"
                         if (sqlca.sqlcode < 0)
# line 130 "example2.cp"
                         {
# line 130 "example2.cp"
                             error_handler();
# line 130 "example2.cp"
                         }
# line 130 "example2.cp"
                         
# line 130 "example2.cp"
                         if (sqlca.sqlwarn[0] == 'W')
# line 130 "example2.cp"
                         {
# line 130 "example2.cp"
                             warning_handler();
# line 130 "example2.cp"
                         }
# line 130 "example2.cp"
                         
# line 130 "example2.cp"
                         if (sqlca.sqlcode == 100)
# line 130 "example2.cp"
                         {
# line 130 "example2.cp"
                             notfound_handler();
# line 130 "example2.cp"
                         }
# line 130 "example2.cp"
                         
# line 130 "example2.cp"
                     }
# line 130 "example2.cp"
                     
# line 130 "example2.cp"
                 }
# line 130 "example2.cp"
                 

                 /*
                 ** Generated code ends here.
                 */
# line 139 "example2.cp"

				}
				printf("\n");
				break;
			case 'n':
			case 'N':
				break;
			}
		}
	}

	
                 /*
                 ** SQL STATEMENT: 12
                 ** EXEC SQL DISCONNECT ALL;

                 */
# line 150 "example2.cp"
# line 150 "example2.cp"
                 {
# line 150 "example2.cp"
                      _SQL_CT_HANDLES * _sql;
# line 150 "example2.cp"
                     _sqlinitctx(&_sql, CS_VERSION_125, CS_TRUE, &sqlca, (long 
# line 150 "example2.cp"
                         *)NULL, (CS_CHAR *)NULL);
# line 150 "example2.cp"
                     if (_sql != (_SQL_CT_HANDLES *) NULL)
# line 150 "example2.cp"
                     {
# line 150 "example2.cp"
                         _sql->stmtData.persistent = CS_FALSE;
# line 150 "example2.cp"
                         _sql->stmttype = SQL_DISCONNECT_ALL;
# line 150 "example2.cp"
                         _sql->connName.lnlen = CS_UNUSED;
# line 150 "example2.cp"
                         if ((_sql->retcode = _sqlprolog(_sql)) == CS_SUCCEED)
# line 150 "example2.cp"
                         {
# line 150 "example2.cp"
                             _sql->retcode = _sqlepilog(_sql);
# line 150 "example2.cp"
                         }
# line 150 "example2.cp"
                         
# line 150 "example2.cp"
                         if (sqlca.sqlcode < 0)
# line 150 "example2.cp"
                         {
# line 150 "example2.cp"
                             error_handler();
# line 150 "example2.cp"
                         }
# line 150 "example2.cp"
                         
# line 150 "example2.cp"
                         if (sqlca.sqlwarn[0] == 'W')
# line 150 "example2.cp"
                         {
# line 150 "example2.cp"
                             warning_handler();
# line 150 "example2.cp"
                         }
# line 150 "example2.cp"
                         
# line 150 "example2.cp"
                         if (sqlca.sqlcode == 100)
# line 150 "example2.cp"
                         {
# line 150 "example2.cp"
                             notfound_handler();
# line 150 "example2.cp"
                         }
# line 150 "example2.cp"
                         
# line 150 "example2.cp"
                     }
# line 150 "example2.cp"
                     
# line 150 "example2.cp"
                 }
# line 150 "example2.cp"
                 

                 /*
                 ** Generated code ends here.
                 */
# line 150 "example2.cp"


	printf("\nbye\n");
	exit (STDEXIT);

}

void put_field(label, value)
char *label;
char *value;
{
	printf("\n\t%-9s: %s", label, value);
}

void get_field(label, value)
char *label;
char *value;
{
	char buf[128];

	printf("\n\t%-9s: %s", label, value);
	printf("\n\t         : ");
	gets(buf);
	if (*buf)
	{
		strcpy(value, buf);
	}
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
** void notfound_handler()
** 
**	Displays notfound messages.
*/
void notfound_handler()
{

	if (sqlca.sqlcode == 100)
	{
		MoreRows = 0;
	}	
	return;
}

                 /*
                 ** Generated code begins here.
                 */
# line 237 "example2.cp"

                 /*
                 ** Generated code ends here.
                 */
# line 237 "example2.cp"
