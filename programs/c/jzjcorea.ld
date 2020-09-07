/* This file is MIT licenced as well*/
/* Used lots of same resources as I used in crt0.s */
/* Also partly based on the default linker script for normal rv32 executables by the FSF under the following liscence*/
/* Default linker script, for normal executables */
/* Copyright (C) 2014-2020 Free Software Foundation, Inc.
   Copying and distribution of this script, with or without modification,
   are permitted in any medium without royalty provided the copyright
   notice and this notice are preserved.  */

/* My first, failed attempt*/
/* LENGTH can be determined with MEM_A_WIDTH. It is equal to (2 to the power of MEM_A_WIDTH) * 4 bytes */
MEMORY
{
    /* Default memory size is 16k and starts at 0x00000000 */
    ram : ORIGIN = 0x00000000, LENGTH = 16K
}

/* the arch is rv32 */
OUTPUT_ARCH("riscv")
OUTPUT_FORMAT("elf32-littleriscv", "elf32-littleriscv", "elf32-littleriscv")
/* After being output, objcopy can produce a verilog file to be formatted by formatverilog */

/* _start is defined in crt0.s */
ENTRY(_start)

SECTIONS
{
    PROVIDE (__executable_start = ORIGIN(ram));
    PROVIDE(__stack_top = ORIGIN(ram) + LENGTH(ram));

    .init : { *(.init*) } > ram
    .text : { *(.text*) } > ram
    .rodata : { *(.rodata*) } > ram
    .sdata :
    {
        __SDATA_BEGIN__ = .; 
        *(.sdata*)
    } > ram
    .data : { *(.data*) } > ram
    .bss : { *(.bss*) } > ram
    
    __global_pointer$ = __SDATA_BEGIN__;
}
