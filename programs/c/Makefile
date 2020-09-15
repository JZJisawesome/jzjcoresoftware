#Make file for JZJCoreLib, JZJCore C lib, crt0, and a program in the programs folder
#MIT Licensed
#Usefull sources:
#https://stackoverflow.com/questions/31421616/c-creating-static-library-and-linking-using-a-makefile
#https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html#creating
#https://riptutorial.com/makefile/example/21376/building-from-different-source-folders-to-different-target-folders
#https://stackoverflow.com/questions/9178285/how-can-makefile-use-separate-directories-for-source-code-and-binaries

CC = riscv64-unknown-elf-gcc
CFLAGS = -std=c18 -static-libgcc -lgcc -fdata-sections -ffunction-sections -Wl,--gc-sections -ffreestanding -fbuiltin -nostdlib -march=rv32i -mabi=ilp32 -nostartfiles -nodefaultlibs -mstrict-align -Os

INC = -I ./include/

BUILDDIR = ./build/
SRCDIR = ./src/
PROGRAMSDIR = ./programs/
LINKERSCRIPT = ./jzjcorea.ld
HEXSCRIPT = ../convertelf.sh

#Environment for c programs on JZJCore
env: crt0 libjzjcore libjzjcorec
crt0: $(BUILDDIR)/crt0.o
libjzjcore: $(BUILDDIR)/libjzjcore.a
libjzjcorec: $(BUILDDIR)/libjzjcorec.a

#A program (depends on definition of the PROGRAM variable which contains the name of a c file in PROGRAMSDIR without the .c)
#Eg. "make program PROGRAM=clibtest" will output ./build/programs/clibtest and ./build/programs/clibtest.hex
program: $(LINKERSCRIPT) $(BUILDDIR)/programs env
	$(CC) $(CFLAGS) $(INC) -c $(PROGRAMSDIR)/$(PROGRAM).c -o $(BUILDDIR)/programs/$(PROGRAM).o
	$(CC) $(CFLAGS) -T $(LINKERSCRIPT) -o $(BUILDDIR)/programs/$(PROGRAM) $(BUILDDIR)/crt0.o $(BUILDDIR)/libjzjcore.a $(BUILDDIR)/libjzjcorec.a $(BUILDDIR)/programs/$(PROGRAM).o
	$(HEXSCRIPT) $(BUILDDIR)/programs/$(PROGRAM)

#JZJCore custom library
#TODO more will need to be added here as the library expands
$(BUILDDIR)/libjzjcore.a: $(BUILDDIR)/libjzjcore $(SRCDIR)/libjzjcore/JZJCoreLib.S
	$(CC) $(CFLAGS) $(INC) -c $(SRCDIR)/libjzjcore/JZJCoreLib.S -o $(BUILDDIR)/libjzjcore/JZJCoreLib.o
	ar rcs $(BUILDDIR)/libjzjcore.a $(BUILDDIR)/libjzjcore/JZJCoreLib.o

#C library
#TODO more will need to be added here as the library expands
$(BUILDDIR)/libjzjcorec.a: $(BUILDDIR)/libjzjcorec
	$(CC) $(CFLAGS) $(INC) -c $(SRCDIR)/libjzjcorec/stdlib.S -o $(BUILDDIR)/libjzjcorec/stdlib.o
	ar rcs $(BUILDDIR)/libjzjcorec.a $(BUILDDIR)/libjzjcorec/stdlib.o

#C runtime
$(BUILDDIR)/crt0.o: $(BUILDDIR) $(SRCDIR)/crt0.s
	$(CC) $(CFLAGS) $(INC) -c $(SRCDIR)/crt0.s -o $(BUILDDIR)/crt0.o

#Build Directory Creation
$(BUILDDIR)/programs: $(BUILDDIR)
	mkdir -p $(BUILDDIR)/programs

$(BUILDDIR)/libjzjcore: $(BUILDDIR)
	mkdir -p $(BUILDDIR)/libjzjcore
	
$(BUILDDIR)/libjzjcorec: $(BUILDDIR)
	mkdir -p $(BUILDDIR)/libjzjcorec

$(BUILDDIR):
	mkdir -p $(BUILDDIR)
