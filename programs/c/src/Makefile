#Make file for JZJCoreLib, JZJCore C lib, crt0, and a program in the programs folder
#MIT Licensed
#Usefull sources:
#https://stackoverflow.com/questions/31421616/c-creating-static-library-and-linking-using-a-makefile
#https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html#creating
#https://riptutorial.com/makefile/example/21376/building-from-different-source-folders-to-different-target-folders
#https://stackoverflow.com/questions/9178285/how-can-makefile-use-separate-directories-for-source-code-and-binaries

CC = riscv64-unknown-elf-gcc
CFLAGS = -std=c18 $(ARCHSETTINGS) -fdata-sections -ffunction-sections -ffreestanding -fbuiltin -nostdlib -nostartfiles -nodefaultlibs -mstrict-align -Os
ARCHSETTINGS = -march=rv32i -mabi=ilp32 

INC = -I ../include/

BUILDDIR = ../build/
SRCDIR = ./

#Environment for c programs on JZJCore
.PHONY: env
env: $(BUILDDIR)/crt0.o $(BUILDDIR)/libjzjcore.a $(BUILDDIR)/libjzjcorec.a

##JZJCore custom library

#TODO more will need to be added here as the library expands
$(BUILDDIR)/libjzjcore.a: $(SRCDIR)/libjzjcore/JZJCoreLib.S | $(BUILDDIR)/libjzjcore
	$(CC) $(CFLAGS) $(INC) -c $(SRCDIR)/libjzjcore/JZJCoreLib.S -o $(BUILDDIR)/libjzjcore/JZJCoreLib.o
	ar rcs $(BUILDDIR)/libjzjcore.a $(BUILDDIR)/libjzjcore/JZJCoreLib.o

##C library

#TODO more will need to be added here as the library expands
$(BUILDDIR)/libjzjcorec.a: $(BUILDDIR)/libjzjcorec/stdlib.o $(BUILDDIR)/libjzjcorec/random.o $(BUILDDIR)/libjzjcorec/ctype.o
	ar rcs $(BUILDDIR)/libjzjcorec.a $(BUILDDIR)/libjzjcorec/stdlib.o $(BUILDDIR)/libjzjcorec/random.o $(BUILDDIR)/libjzjcorec/ctype.o

$(BUILDDIR)/libjzjcorec/stdlib.o: $(SRCDIR)/libjzjcorec/stdlib.S | $(BUILDDIR)/libjzjcorec
	$(CC) $(CFLAGS) $(INC) -c $(SRCDIR)/libjzjcorec/stdlib.S -o $(BUILDDIR)/libjzjcorec/stdlib.o
	
$(BUILDDIR)/libjzjcorec/random.o: $(SRCDIR)/libjzjcorec/random.S | $(BUILDDIR)/libjzjcorec
	$(CC) $(CFLAGS) $(INC) -c $(SRCDIR)/libjzjcorec/random.S -o $(BUILDDIR)/libjzjcorec/random.o

$(BUILDDIR)/libjzjcorec/ctype.o: $(SRCDIR)/libjzjcorec/ctype.S | $(BUILDDIR)/libjzjcorec
	$(CC) $(CFLAGS) $(INC) -c $(SRCDIR)/libjzjcorec/ctype.S -o $(BUILDDIR)/libjzjcorec/ctype.o

##C runtime
$(BUILDDIR)/crt0.o: $(SRCDIR)/crt0.s | $(BUILDDIR)
	$(CC) $(CFLAGS) $(INC) -c $(SRCDIR)/crt0.s -o $(BUILDDIR)/crt0.o

##Build Directory Creation
$(BUILDDIR)/libjzjcore:
	mkdir -p $(BUILDDIR)/libjzjcore
	
$(BUILDDIR)/libjzjcorec:
	mkdir -p $(BUILDDIR)/libjzjcorec

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)/libjzjcore
	rm -rf $(BUILDDIR)/libjzjcorec
	rm -rf $(BUILDDIR)/libjzjcore.a
	rm -rf $(BUILDDIR)/libjzjcorec.a
	rm -rf $(BUILDDIR)/crt0.o
