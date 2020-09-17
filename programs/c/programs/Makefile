#Make file for individual c programs
#Assumes the env target has been made (STATICLIBSDIR contains crt0.o, libjzjcore.a, and libjzjcorec.a)

#Compiler settings
CC = riscv64-unknown-elf-gcc
CFLAGS = -std=c18 $(ARCHSETTINGS) -fdata-sections -ffunction-sections -ffreestanding -fbuiltin -nostdlib -nostartfiles -nodefaultlibs -mstrict-align -Os
ARCHSETTINGS = -march=rv32i -mabi=ilp32 

#Linker settings
LDFLAGS = $(CFLAGS) -T $(LINKERSCRIPT) -Wl,--gc-sections
LDLIBS = -L $(STATICLIBSDIR) -static-libgcc -Wl,--start-group -lgcc -ljzjcore -ljzjcorec -Wl,--end-group

#Directory Locations
INC = -I ../include/
BUILDDIR = ../build
PROGRAMSDIR = ./
LINKERSCRIPT = ../jzjcorea.ld
HEXSCRIPT = ../../convertelf.sh
STATICLIBSDIR = $(BUILDDIR)

#A program (depends on definition of the PROGRAM variable which contains the name of a c file in PROGRAMSDIR without the .c)
#Eg. "make program PROGRAM=clibtest" will output $(BUILDDIR)/programs/clibtest and $(BUILDDIR)/programs/clibtest.hex
.PHONY: program
program: $(BUILDDIR)/programs/$(PROGRAM).hex

$(BUILDDIR)/programs/$(PROGRAM).hex: $(PROGRAMSDIR)/$(PROGRAM).c $(LINKERSCRIPT) $(BUILDDIR)/crt0.o $(BUILDDIR)/libjzjcore.a $(BUILDDIR)/libjzjcorec.a | $(BUILDDIR)/programs
	$(CC) $(CFLAGS) $(INC) -c $(PROGRAMSDIR)/$(PROGRAM).c -o $(BUILDDIR)/programs/$(PROGRAM).o
	$(CC) $(LDFLAGS) -o $(BUILDDIR)/programs/$(PROGRAM) $(BUILDDIR)/crt0.o $(BUILDDIR)/programs/$(PROGRAM).o $(LDLIBS)
	$(HEXSCRIPT) $(BUILDDIR)/programs/$(PROGRAM)

#Build Directory Creation
$(BUILDDIR)/programs:
	mkdir -p $(BUILDDIR)/programs

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)/programs
