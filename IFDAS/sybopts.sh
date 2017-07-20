#!/bin/sh
###########################################################################
#
# sybopts.sh -- Helper script for UNIX makefiles that build Open Client
#    and Open Server applications. This script uses the value of
#    the SYBPLATFORM environment variable to determine what platform
#    specific libraries must be linked with the application.
#
# Usage:
#  sybopts.sh <args>
#
#  where <args> can be one or more of the following:
#
#     compile -- Based on SYBPLATFORM, echoes the compiler command
#	and platform-specific compile flags. For example, if
#       SYBPLATFORM indicates a platform with support for 
#	multithreading, the compile flag "-D_REENTRANT" might be 
#	required.
#     comlibs -- Based on SYBPLATFORM, echoes the list of required
#	lower-layer Sybase libraries that must be linked with the
#	application.
#     syslibs -- Based on SYBPLATFORM, echoes the list of required
#	system (i.e., non-Sybase) libraries that must be linked with the
#	application.
#     ct, cs, blk, srv (respectively) -- Based on SYBPLATFORM, echoes 
#	the name of the archive for Client-Library, CS-Library, 
#	Bulk-Library, or Server-Library routines.
#     verify -- Check SYBPLATFORM setting, if ok, echoes the library
#	names that will be used. If not ok, returns non-zero. This
#	argument must appear by itself with no other arguments.
#     verify_threaded -- Returns non-zero if SYBPLATFORM indicates
# 	a version of Client-Library without multi-threaded support.
#     verify_krb -- Returns non-zero if SYBPLATFORM value is a platform
#       for which we currently do *not* support CyberSAFE Kerberos.  Note
#       that Kerberos is currently only supported on the following UNIX
#       SYBPLATFORMs: sun_svr4, nthread_sun_svr4, hpux, and nthread_hpux
#
# Example:
# 	COMPILE = `sh sybopts.sh compile` $(INCLUDE) $(DEFS)
#
###########################################################################

SET_SYBPLATFORM_MSG="Unknown machine type. Please set SYBPLATFORM variable"
BAD_ARGUMENT_MSG="Unknown argument"
THREAD_SUPPORT_MSG="This target requires multi-threaded support."
KRB_SUPPORT_MSG="This target requires that CyberSAFE Kerberos be installed and running."
SYBPLATFORM_MSG="Check the value of your SYBPLATFORM environment variable."
SYBPLATFORM=sun_svr464
#
# First find the libraries:
if [ "${SYBASE_OCS}" = "" ]
  then
	OCSBASE="${SYBASE}"
  else
	if [ -d ${SYBASE}/${SYBASE_OCS} ]
	  then
		OCSBASE="${SYBASE}/${SYBASE_OCS}"
	  else
		OCSBASE="${SYBASE}"
	fi
fi

SYBLIB="${OCSBASE}/lib"
SYBBIN="${OCSBASE}/bin"
SYBINC="${OCSBASE}/include"

#
# CC: Compiler/Linker name and compile/link flags. Please note your compiler
# version may be different, specifically on sun_svr4.
#
case "${SYBPLATFORM}" in 
	sun_svr4) 		CC="cc -g " ;;
	nthread_sun_svr4) 	CC="/opt/SUNWspro/bin/cc -g -D_REENTRANT " ;;
	sun_svr464) 		CC="/opt/SUNWspro/bin/cc -g -DSYB_LP64 -xarch=v9 " ;; 
	nthread_sun_svr464) 	CC="/opt/SUNWspro/bin/cc -g -DSYB_LP64 -D_REENTRANT -xarch=v9 " ;; 
	hpux) 			CC="cc -g -Ae +Z +DA1.1 +DS2.0 " ;;
	nthread_hpux) 		CC="cc -O -Ae +Z +DA1.1 +DS2.0 -D_POSIX_C_SOURCE=199506L -D_POSIX_D10_THREADS " ;;
	hpux64)			CC="cc -g -DSYB_LP64 -Ae -DANSI_VARARGS +Z +DA2.0W +DS2.0 -Wp,-H256000 " ;;
	nthread_hpux64) 	CC="cc -g -DSYB_LP64 -Ae -DANSI_VARARGS +Z +DA2.0W +DS2.0 -Wp,-H256000 " ;; 
	linux)			CC="cc -g " ;;
	nthread_linux)		CC="cc -g -D_REENTRANT " ;;
	rs6000) 		CC="xlc -g " ;;
	nthread_rs6000) 	CC="xlc_r -g -D_THREAD_SAFE " ;;
	rs600064) 		CC="xlc -g -q64 -qarch=ppc64 -qtune=620 -DSYB_LP64 " ;;
	nthread_rs600064) 	CC="xlc_r -g -q64 -qarch=ppc64 -qtune=620 -DSYB_LP64 -D_THREAD_SAFE " ;;
	sgi|nthread_sgi)	CC="cc -g -n32 -mips4 -B static " ;;
	sgi64|nthread_sgi64)	CC="cc -g -64 -mips4  -B static " ;;
	axposf)			CC="cc -g " ;;
	nthread_axposf)		CC="cc -g -threads " ;;
	*) 			CC="cc -g ";;
esac ;

#
# CPRE: C precompiler name
case "${SYBPLATFORM}" in
	nthread_*)		PRECOMP="${SYBBIN}/cpre_r" ;;
	*)			PRECOMP="${SYBBIN}/cpre" ;;
esac ;

case "${SYBPLATFORM}" in
	*rs6000*)		PRECOMP="${PRECOMP} -l" ;;
esac ;

#
# COMLIBS:
# The list of lower-layer Sybase libraries that are required in order 
# to build a Sybase Open Client/Server application, in the order in 
# which they must be linked.
case "${SYBPLATFORM}" in
	axposf|hpux|rs6000|sun_svr4|sgi)
		COMLIBS=" -ltcl -lcomn -lintl" ;;
	linux)
	   	COMLIBS=" -lsybtcl -lcomn -lintl" ;;
	nthread_linux) 
		COMLIBS=" -lsybtcl_r -lcomn_r -lintl_r" ;;
	hpux64|sun_svr464|sgi64|rs600064)
		COMLIBS=" -ltcl64 -lcomn64 -lintl64" ;;
	nthread_sun_svr4|nthread_axposf|nthread_rs6000|nthread_hpux)
		COMLIBS=" -ltcl_r -lcomn_r -lintl_r" ;;
	nthread_sgi)
		COMLIBS=" -ltcl_r -lcomn_r -lintl_r" ;;
	nthread_hpux64|nthread_sun_svr464|nthread_sgi64|nthread_rs600064)
		COMLIBS=" -ltcl_r64 -lcomn_r64 -lintl_r64" ;;
	*)
		echo " $SET_SYBPLATFORM_MSG "; exit 1;;
esac ;

#
# SYSLIBS:
# The list of system libraries that are required in order 
# to build a Sybase Open Client/Server application, in the order in 
# which they must be linked.
case "${SYBPLATFORM}" in 
	axposf)				SYSLIBS=" -oldstyle_liblookup -lm" ;;
	hpux) 				SYSLIBS=" -Wl -lcl -lm -lBSD -ldld -Wl,-E,+s" ;; 
	hpux64) 			SYSLIBS=" -Wl -lcl -lm -ldld -Wl,-E,+s" ;; 
	linux) 				SYSLIBS=" -rdynamic -ldl -lnsl -lm" ;; 
	nthread_linux)			SYSLIBS=" -rdynamic -ldl -lpthread -lnsl -lm" ;; 
	nthread_sgi|nthread_sgi64)	SYSLIBS=" -B dynamic -lpthread -lm" ;;
	nthread_sun_svr4) 		SYSLIBS=" -B dynamic -lnsl -ldl -lpthread -lm" ;; 
	nthread_sun_svr464) 		SYSLIBS=" -B dynamic -lnsl -ldl -lpthread -lm" ;; 
	nthread_hpux) 			SYSLIBS=" -lpthread -lrt -lm -lcl -ldld" ;; 
	nthread_hpux64) 		SYSLIBS=" -lpthread -lrt -lm -lcl -ldld -Wl,-E,+s " ;; 
	nthread_rs6000)			SYSLIBS=" -lm" ;;
	nthread_axposf)			SYSLIBS=" -threads -oldstyle_liblookup -lrt" ;;
	rs6000) 			SYSLIBS=" -lm" ;; 
	rs600064) 			SYSLIBS=" -lm" ;; 
	nthread_rs600064) 		SYSLIBS=" -lm" ;; 
	sgi|sgi64)			SYSLIBS=" -B dynamic " ;;
	sun_svr4) 			SYSLIBS=" -B dynamic -lnsl -ldl -lm" ;; 
	sun_svr464) 			SYSLIBS=" -B dynamic -lnsl -ldl -lm" ;; 
	*) 				echo " $SET_SYBPLATFORM_MSG "; exit 1;; 
esac ;

#
# CTLIB, CSLIB, BLKLIB, SRVLIB:
# The names of exposed libraries. These come in multi-threaded
# and single-threaded versions.
case "${SYBPLATFORM}" in
	sgi64) 		CTLIB="-lct64"; CSLIB="-lcs64";
	 		BLKLIB="-lblk64"; SRVLIB="-lsrv64"
			;;
	nthread_sgi64) 	CTLIB="-lct_r64"; CSLIB="-lcs_r64";
	 		BLKLIB="-lblk_r64"; SRVLIB="-lsrv_r64"
			;;
	sun_svr464)	CTLIB="-lct64"; CSLIB="-lcs64";
	 		BLKLIB="-lblk64"; SRVLIB="-lsrv64"
			;;
	nthread_sun_svr464)	CTLIB="-lct_r64"; CSLIB="-lcs_r64";
	 		BLKLIB="-lblk_r64"; SRVLIB="-lsrv_r64"
			;;
	hpux64|rs600064) CTLIB="-lct64"; CSLIB="-lcs64";
	 		BLKLIB="-lblk64"; SRVLIB="-lsrv64"
			;;
	nthread_hpux64|nthread_rs600064) CTLIB="-lct_r64"; CSLIB="-lcs_r64";
	 		BLKLIB="-lblk_r64"; SRVLIB="-lsrv_r64"
			;;
	nthread_*) 	CTLIB="-lct_r"; CSLIB="-lcs_r";
	 		BLKLIB="-lblk_r"; SRVLIB="-lsrv_r";
			;;
	*)  		CTLIB="-lct"; CSLIB="-lcs";
	 		BLKLIB="-lblk"; SRVLIB="-lsrv";
			;;
esac ;

#
# A single argument of "verify" means that we should print
# the value of SYBPLATFORM, print the choices that will be made
# for comlibs, syslibs, etc., then exit with a status of 0. If
# SYBPLATFORM is incorrect, we will not get here.
#
if [ $1 = "verify" ]
  then
	echo "SYBPLATFORM is $SYBPLATFORM"
	echo "Compiling with $CC"
	echo "Sybase base libraries: $COMLIBS"
	echo "System libraries: $SYSLIBS"
	exit 0
fi

if [ $1 = verify_threaded ]
  then
	case $SYBPLATFORM in
		nthread_*)
			exit 0;;
		*)
			echo " $THREAD_SUPPORT_MSG";
			exit 1 ;;
	esac
	exit 0
fi


#
# Ensure that Kerberos is installed and running.  (Note that Kerberos is
# currently only supported on sun_svr4 and hpux)
#
if [ $1 = verify_krb ]
  then
	case $SYBPLATFORM in
		*sun_svr4|*hpux)
			exit 0;;
		*)
			echo " $KRB_SUPPORT_MSG";
			exit 1 ;;
	esac
	exit 0
fi

#
# Build a string to echo what was asked for:
#
ECHOSTRING=""
for a
do
	case "$a" in
		compile) 	ECHOSTRING="$ECHOSTRING $CC" ;;
		precomp)	ECHOSTRING="$ECHOSTRING $PRECOMP" ;;
		comlibs) 	ECHOSTRING="$ECHOSTRING $COMLIBS" ;;
		syslibs) 	ECHOSTRING="$ECHOSTRING $SYSLIBS " ;;
		ct) 		ECHOSTRING="$ECHOSTRING $CTLIB" ;;
		cs) 		ECHOSTRING="$ECHOSTRING $CSLIB" ;;
		srv) 		ECHOSTRING="$ECHOSTRING $SRVLIB" ;;
		blk) 		ECHOSTRING="$ECHOSTRING $BLKLIB" ;;
		ocsbase)	ECHOSTRING="$ECHOSTRING $OCSBASE" ;;
		*) 		echo "$0: $a: $BAD_ARGUMENT_MSG "; exit 1;;
	esac
done

echo "$ECHOSTRING"
exit 0
