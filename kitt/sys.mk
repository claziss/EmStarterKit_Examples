##################################################################################################
# define OS specific parameters 
#
#########################################
# Under Win9x, COMSPEC is defined, but ComSpec isn't,
# and under WinNT, ComSpec is defined, but COMSPEC isn't!
#
ifdef ComSpec
    DOS_CMD=$(ComSpec) /C
endif
ifdef COMSPEC
    DOS_CMD=$(COMSPEC) /C
endif
ifneq ($(DOS_CMD),)
    O_SYS = windows
else
    # We're running under Unix (or Linux)
    O_SYS = linux
endif
##########################################################################

ifeq "$(O_SYS)" "windows"
	PS= \$(nullstring)
	DOS_CMD=$(ComSpec) /C
	ASH_PATH=c:/AshlingOpellaXDforARC/opxdarc
	RM=$(DOS_CMD) del /Q /F
	RMD=$(DOS_CMD) rd /S /Q
	ECHO=$(DOS_CMD) echo
	CP=copy
	MKD = mkdir
	FixPath = $(subst /,\,$1)
else 
	PS=/$(nullstring)
	ASH_PATH=/opt/opellaxdforarc/opxdarc.so
	RM=rm -f
	RMD=rm -f
	ECHO=echo
	CP=cp
	MKD = mkdir
	FixPath = $1
endif













