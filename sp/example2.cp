/*
**    example2.cp
**
**	This example displays and allows user to edit
**	rows in the authors table in the pubs2 database. 
*/
#include <stdio.h>
#include "sybsqlex.h"

/* Declare the SQLCA. */
EXEC SQL INCLUDE SQLCA;

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
	EXEC SQL BEGIN DECLARE SECTION;
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
	EXEC SQL END DECLARE SECTION;

	/* buffer for responses */
	char	buf[10];


	EXEC SQL WHENEVER SQLERROR CALL error_handler();
	EXEC SQL WHENEVER SQLWARNING CALL warning_handler();
	EXEC SQL WHENEVER NOT FOUND CALL notfound_handler();

	/* 
	** Copy the user name and password defined in sybsqlex.h to
	** the variables declared for them in the declare section. 
	*/
	strcpy(username, USER);
	strcpy(password, PASSWORD);
	strcpy(buf,"");

	EXEC SQL CONNECT :username IDENTIFIED BY :password;
		

	EXEC SQL USE pubs2;

	EXEC SQL 
	DECLARE authors CURSOR FOR
		SELECT	au_id, au_lname, au_fname, 
			phone, address, city, state, 
			postalcode
		FROM 	authors;

	EXEC SQL OPEN authors;

	/*
	** This loop controls the entry.
	*/

	while ( MoreRows )
	{
		if (*buf == 'Q' || *buf == 'q')
			break;

		EXEC SQL 
		FETCH authors INTO
			:m_au_id, :m_au_lname, :m_au_fname, 
			:m_phone, :m_address, :m_city, 
			:m_state, :m_zip;

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
					EXEC SQL 
					UPDATE authors SET
						au_lname = :m_au_lname,
						au_fname = :m_au_fname,
						phone = :m_phone,
						address = :m_address,
						city = :m_city,
						state = :m_state,
						postalcode = :m_zip
					WHERE CURRENT OF authors;
				}
				printf("\n");
				break;
			case 'n':
			case 'N':
				break;
			}
		}
	}

	EXEC SQL DISCONNECT ALL;

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
