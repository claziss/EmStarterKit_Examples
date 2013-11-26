INCLUDE linkcmds.memory

SECTIONS
{
    .ivt 0x00 :
    {
      KEEP (*(.ivt));
    } > REGION_IVT
    .init :
    {
	KEEP (*(.init));
    } > REGION_INIT
    .text 0x100 :
    {
	*(.text)
    } > REGION_TEXT
    .data :
    {
	*(.data)
    } > REGION_DATA
    .sdata :
    {
	__SDATA_BEGIN__ = .;
	*(.sdata .sdata.* .gnu.linkonce.s.*)
	_edata = .;
	PROVIDE (edata = .);
    } > REGION_SDATA
    .sbss :
    {
	__bss_start = .;
	PROVIDE (__sbss_start = .);
	PROVIDE (___sbss_start = .);
	*(.dynsbss)
	*(.sbss .sbss.* .gnu.linkonce.sb.*)
	*(.scommon)
	PROVIDE (__sbss_end = .);
	PROVIDE (___sbss_end = .);
    } > REGION_SBSS
    .bss :
    {
	*(.dynbss)
	*(.bss .bss.* .gnu.linkonce.b.*)
	*(COMMON)
	/* Align here to ensure that the .bss section occupies space up to
	_end.  Align after .bss to ensure correct alignment even if the
	.bss section disappears because there are no input sections.  */
	. = ALIGN(32 / 8);
	_end = .;
	PROVIDE (end = .);
    } > REGION_BSS
    .heap :
    {
	. = ALIGN(32 / 8);
	__start_heap = . ;
	. = . + (DEFINED(__HEAP_SIZE) ? __HEAP_SIZE : (DEFINED(__DEFAULT_HEAP_SIZE) ? __DEFAULT_HEAP_SIZE : 16k))  ;
	__end_heap = . ;
	. = ALIGN(0x8);
    } > REGION_HEAP
    .stack :
    {
	. = ALIGN(32 / 8);
	__stack = . ;
	. = . + (DEFINED(__STACK_SIZE) ? __STACK_SIZE : (DEFINED(__DEFAULT_STACK_SIZE) ? __DEFAULT_STACK_SIZE : 2k))  ;
	__stack_top = . ;
    } > REGION_STACK
}
