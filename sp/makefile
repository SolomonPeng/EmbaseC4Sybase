# Make the Embedded SQL/C sample programs.
#
# Change the following definitions as appropriate for your site:
# MAKE = make CC="$(CC)" AS="$(AS)" LD="$(LD)" AR="$(AR)" CPP="$(CPP)" SYBPLATFORM="$(SYBPLATFORM)" 
#
SHELL       = /bin/sh
HEADERS     = ./sybsqlex.h
 
TARGET1     = example1
TARGET2     = example2
UNI_TARGET1 = uni_example1
UNI_TARGET2 = uni_example2
OCSBASE     = `sh sybopts.sh ocsbase`
INCLUDE     = -I. -I$${SYBASE}/$${SYBASE_OCS}/include
LIBFLAGS    = -L$${SYBASE}/$${SYBASE_OCS}/lib
SYBLIBDIR   = $(OCSBASE)/lib/
CFLAGS      = $(INCLUDE) $(LIBFLAGS)
PRECOMP     = `sh sybopts.sh precomp`
LINK.c	    = `sh sybopts.sh compile` $(CFLAGS)
 
SYBLIBS     = `sh sybopts.sh ct cs comlibs`
SYSLIBS     = `sh sybopts.sh syslibs` 


all: 	$(TARGET1) $(TARGET2)
 
uni: 	$(UNI_TARGET1) $(UNI_TARGET2)
 
$(TARGET1): $(HEADERS) example1.c
	$(LINK.c) -o $@ $(OCSBASE)/include/sybesql.c example1.c $(SYBLIBS) $(SYSLIBS)
 
example1.c: example1.cp
	$(PRECOMP) example1.cp

$(TARGET2): $(HEADERS) example2.c
	$(LINK.c) -o $@ $(OCSBASE)/include/sybesql.c example2.c $(SYBLIBS) $(SYSLIBS)
 
example2.c: example2.cp
	$(PRECOMP) -m example2.cp

$(UNI_TARGET1): $(HEADERS) uni_example1.c
	$(LINK.c) -o $@ $(OCSBASE)/include/sybesql.c uni_example1.c $(SYBLIBS) $(SYSLIBS)
 
uni_example1.c: uni_example1.cp
	$(PRECOMP) -m uni_example1.cp

$(UNI_TARGET2): $(HEADERS) uni_example2.c
	$(LINK.c) -o $@ $(OCSBASE)/include/sybesql.c uni_example2.c $(SYBLIBS) $(SYSLIBS)
 
uni_example2.c: uni_example2.cp
	$(PRECOMP) -m uni_example2.cp

clean: 
	rm -f *.o $(TARGET1) $(TARGET2) $(UNI_TARGET1) $(UNI_TARGET2) example1.c example2.c uni_example1.c uni_example2.c
