include $(ORACLE_HOME)/precomp/lib/env_precomp.mk

PROC=proc
CC=/opt/SUNWspro/bin/cc
LOCALFLAGS= sqlcheck=full userid=ibss/ibss@CMMS MODE=ORACLE CODE=ANSI_C ORACA=YES def_sqlcode=YES char_map=string  UNSAFE_NULL=YES DBMS=v8
LOCALFLAGSHMG = sqlcheck=full userid=voip003/h9zvy2wg81@ics MODE=ORACLE CODE=ANSI_C ORACA=YES def_sqlcode=YES char_map=string  UNSAFE_NULL=YES DBMS=v8
ORACLE_LIB=$(LLIBCLNTSH)
ORALIB=-I$(ORACLE_HOME)/precomp/public
ORADBMS=-I$(ORACLE_HOME)/rdbms/public
ORAPLSQL=-I$(ORACLE_HOME)/plsql/public
ORANETWORK=-I$(ORACLE_HOME)/network/public
ORADEMO=-I$(ORACLE_HOME)/rdbms/demo
DFLAGS= -DPRECOMP -DLINUX -D_GNU_SOURCE -DSLTS_ENABLE -DSLMXMX_ENABLE -D_REENTRANT -DNS_THREADS
LIBPATH= -L$(ORACLE_HOME)/lib/
LIBS=-lclntsh 'cat $(ORACLE_HOME)/lib/sysliblist' -ldl -lm

all: clean cmms.c cmms 

cmms: cmmsTest.c cmms.c
	$(CC) $(CFLAGS64) -o $@ cmmsTest.c $@.c -I$(ORACLE_HOME)/precomp/public -L$(ORACLE_HOME)/lib -lclntsh $(LIBPATH)
		
cmms.c: cmms.pc
	$(PROC) $(LOCALFLAGS) iname=$*.pc oname=$*.c

#hmg.c: hmg.pc
#	$(PROC) $(LOCALFLAGSHMG) iname=$*.pc oname=$*.c
        
clean: 
	rm -f *.o cmms cmms.c hmg.c

