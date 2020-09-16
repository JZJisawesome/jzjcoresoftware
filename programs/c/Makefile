#Uses makefiles in other directories
#I know this is a bad way of doing things but it works for now
WRAPPER_LIBSDIR = ./src
WRAPPER_PROGRAMSDIR = ./programs
WRAPPER_BUILDDIR = ./build

.PHONY: env program
env:
	$(MAKE) --directory=$(WRAPPER_LIBSDIR)

#Program to compile must be specified with PROGRAM
program: env
	$(MAKE) --directory=$(WRAPPER_PROGRAMSDIR) PROGRAM=$(PROGRAM)
	
.PHONY: clean
clean:
	rm -rf $(WRAPPER_BUILDDIR)
