
#!/bin/make
# GNU MAKEFILE

#   All The Strings
#  _____ _ _    _____ _          _____ _       _             
# |  _  | | |  |_   _| |_ ___   |   __| |_ ___|_|___ ___ ___ 
# |     | | |    | | |   | -_|  |__   |  _|  _| |   | . |_ -|
# |__|__|_|_|    |_| |_|_|___|  |_____|_| |_| |_|_|_|_  |___|
#                                                   |___|    
# AUTHOR:  Chris Reid <spikeysnack@gmail.com>                #
# LICENSE: Free for all purposes                             #
# COPYRIGHT: 2018- Chris Reid                                #



DEBUG=1
EXCEPTIONS=1
COLORS=1


CC= gcc
CXX= g++
#STD = c++14
STD = gnu++23

CXXFLAGS= -std=$(STD) -Wall  -Wextra  -Wformat -pedantic -Werror -fpic 
#CC= clang
#CXX= clang++
#CXXFLAGS= -std=c++11 -Wall  -Wextra  -Wformat -pedantic -Werror -fpic 

#BASE_CFLAGS= -m32 -fstrict-aliasing -fpic  -Wno-unused-function $(DEFINES) 
BASE_CFLAGS=  -fstrict-aliasing -fpic  -Wno-unused-function $(DEFINES) 
DEBUG_CFLAGS= -ggdb3  -Wall -Werror  -fno-omit-frame-pointer
INCLUDES= $(PWD)
LIBINCLUDES= $(PWD)
# rpath tells the linker where to find the library
LIBPATH= -Wl,-rpath=$(LIBINCLUDES)/

INSTALLPATH= /usr/local
DEFINES += -DUSE_SMALL_WORDS -DUSE_COLOR

ifeq ($(EXCEPTIONS),1)
	DEFINES+= -DUSE_EXCEPTIONS
	CXXFLAGS += -fexceptions
else
	CXXFLAGS += -fnoexceptions
endif



ifdef DEBUG
DEFINES += -DDEBUG
CFLAGS= $(BASE_CFLAGS)  $(DEBUG_CFLAGS)
else
CFLAGS= $(BASE_CFLAGS)
DEFINES += -D NDEBUG  #turns off assert
endif

ifdef C_SRC
OBJS += ${C_SRC:.c=.o}
endif


LIBRARIES   = libAllTheStrings.so.1
STATIC_LIBS = libAllTheStrings.a
BINARIES    =  libAllTheStrings.o libAllTheStrings.a
TEST_BINARIES  =  strtest
ARCHIVE =   AllTheStrings.tgz

LLIB=$(HOME)/lib/
LINC=$(HOME)/include/



options:
	@echo  "Make Options:"
	@echo  "all             (default) makes library and all test binaries"
	@echo  "test            makes and run tests in tests directory"
	@echo  "lib             makes shared library (default)"
	@echo  "static          makes static version of AllTheStrings library  (libdAlltheStrings.a)"
	@echo  "install         installs library and headers (super user)"
	@echo  "uninstall       removes library and headers"
	@echo  "localinstall    installs in user's dirs"
	@echo  "dist            makes a tarball (AllTheStrings.tgz)of all files in current dir"

help:	options



all: clean AllTheStrings.o shared test


AllTheStrings.o:	AllTheStrings.cpp

	$(CXX) $(CXXFLAGS) $(DEFINES) -c AllTheStrings.cpp


shared:	AllTheStrings.o
	$(CXX) -shared -o libAllTheStrings.so.1  AllTheStrings.o



.PHONY:	all clean test install uninstall localinstall static dist


lib:    libAllTheStrings.so
	@echo  "libAllTheStrings.so created (link with -L .  -lAllTheStrings )"

# this is the shared lib
libAllTheStrings.so:	AllTheStrings.o
	$(CXX) $(CXXFLAGS)  $(DEFINES)  -shared    -o libAllTheStrings.so.1  AllTheStrings.o
	ln -sf libAllTheStrings.so.1  libAllTheStrings.so


static: libAllTheStrings.a

#if you need a static version of the library
libAllTheStrings.a:	AllTheStrings.o
	ar -cvq libAllTheStrings.a AllTheStrings.o
	@echo  "libAllTheStrings.a created ( add explicit path  (eg "/usr/local/lib/libAlTheStrings.a" to compile string )"


dist:   clean
	if [ -f $(ARCHIVE) ] ; then      \
		gunzip $(ARCHIVE) ;      \
		tar -uvf AllTheStrings.tar ;   \
		gzip  AllTheStrings.tar ;      \
		mv AllTheStrings.tar.gz AllTheStrings.tgz ; \
	else\
		tar -cvzf AllTheStrings.tgz ../AllTheStrings/* ; \
	fi;



install:	lib
	sudo  cp libAllTheStrings.so.1 $(INSTALLPATH)/lib
	sudo  ln -sf $(INSTALLPATH)/lib/libAllTheStrings.so.1 $(INSTALLPATH)/lib/libAllTheStrings.so   
	sudo  cp AllTheStrings.h $(INSTALLPATH)/include/
	@echo  ""
	@echo  "libAllTheStrings.so  installed to /usr/local/lib. headers to /usr/local/include."
	@echo  "to use:  include AllTheStrings.h and -l AllTheStrings in your compilation string"


localinstall:	lib
	install -d $(LLIB) $(LINC)
	cp libAllTheStrings.so.1 $(LLIB)
	ln -sf $(LLIB)/libAllTheStrings.so.1 $(LLIB)/libAllTheStrings.so   
	cp AllTheStrings.h $(LINC)
	@echo
	@echo  "libAllTheStrings.so  installed to $(LLIB) . headers to $(LINC) ."
	@echo  "to use:  "
	@echo  " -I$(LLINC) include \"AllTheStrings.h\","
	@echo  "and -L$(LLIB),  -lAllTheStrings in your compilation string"


uninstall:
	sudo  unlink $(INSTALLPATH)/lib/libAllTheStrings.so
	@echo "link to lib removed"
	sudo  rm  -f $(INSTALLPATH)/lib/libAllTheStrings.so.* 
	@echo  "libAllTheStrings.so removed"
	sudo  rm  -f $(INSTALLPATH)/include/AllTheStrings.h 
	@echo  "AllTheStrings  headers removed"



 test:	AllTheStrings.o
	(cd tests; make all)


clean:
	rm -f  *.o   *~ \#* core *.so $(BINARIES) $(LIBRARIES)  $(STATIC_LIBS) $(TEST_BINARIES)
	(cd tests;  make clean)

