##
# Read options
#
include sys.mk

# Application name
APPL = fibonacci

# list of object files including in application
OBJS = fibonacci crt0

# include dirs
INC_DIRS =

# tools
MAKE = make
CC   = arc-elf32-gcc
AS   = arc-elf32-as
DMP  = arc-elf32-objdump
LD   = arc-elf32-ld

#options
ASM_OPT = -mav2em
COMPILE_OPT = -O2 -mcpu=ARCv2EM
LINK_OPT = crt0.o --script=linksections.cmd
OBJS_ALL = $(addsuffix .o, $(OBJS))


.PHONY: all $(APPL)


$(APPL) all: $(APPL).elf


%.elf:  $(OBJS_ALL)
	$(LD) $(LINK_OPT) $< -o $@

%o:%c
	$(ECHO) "Compiling $<"
	$(CC) -c $(COMPILE_OPT) $< -o $@

%o:%s
	$(ECHO) "Assembling $<"
	$(AS) $(ASM_OPT) $< -o $@

clean:
	$(RM) *.o *.out *.bin *.dis *.elf *.a* *.hex *.map *.bak *.dump *.d

%dump:%elf
	$(DM) $< -p > $@
	$(CP) $@ ..$(PS)$(CC)_$(CURRENT_CORE)__$@



