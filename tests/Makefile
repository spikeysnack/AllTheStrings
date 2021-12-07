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

CC= gcc
CXX= g++

CXXFLAGS= -std=gnu++2a -Wall  -Wextra  -Wformat -pedantic -Werror -fpic 
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

#
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

.PHONY:	all clean tests

all: clean tests

tests:	atstest begin_endtest applytest valuetest formattest inserttest colortest test 

atstest:	../AllTheStrings.o atstest.cpp
	$(CXX) $(CXXFLAGS) $(DEFINES)  -I.. -o atstest atstest.cpp  ../AllTheStrings.o

begin_endtest:	../AllTheStrings.o begin_endtest.cpp
	$(CXX) $(CXXFLAGS) $(DEFINES)  -I.. -o begin_endtest begin_endtest.cpp  ../AllTheStrings.o

valuetest:	../AllTheStrings.o valuetest.cpp
	$(CXX) $(CXXFLAGS) $(DEFINES)  -I.. -o valuetest valuetest.cpp  ../AllTheStrings.o

inserttest:	../AllTheStrings.o inserttest.cpp
	$(CXX) $(CXXFLAGS) $(DEFINES)  -I.. -o inserttest inserttest.cpp  ../AllTheStrings.o

strtest:	../AllTheStrings.o strtest.cpp
	$(CXX) $(CXXFLAGS) $(DEFINES)  -I.. -o strtest strtest.cpp  ../AllTheStrings.o

applytest:	../AllTheStrings.o applytest.cpp
	$(CXX) $(CXXFLAGS) $(DEFINES)  -I.. -o applytest applytest.cpp  ../AllTheStrings.o

formattest:	../AllTheStrings.o formattest.cpp
	$(CXX) $(CXXFLAGS) $(DEFINES)  -I.. -o formattest formattest.cpp  ../AllTheStrings.o

colortest:	../AllTheStrings.o colortest.cpp
	$(CXX) $(CXXFLAGS) $(DEFINES)  -I.. -o colortest colortest.cpp  ../AllTheStrings.o


table:	StringTable.h table.cpp
	$(CXX) $(CXXFLAGS) $(DEFINES)  -I.. -o table table.cpp 


test:	strtest
	@./atstest
	@read -p "Press enter to continue" dummy
	@./begin_endtest
	@read -p "Press enter to continue" dummy
	@./applytest
	@read -p "Press enter to continue" dummy
	@./valuetest
	@read -p "Press enter to continue" dummy
	@./formattest
	@read -p "Press enter to continue" dummy
	@./inserttest
	@read -p "Press enter to continue" dummy
	@./colortest


clean:	
	rm -f *test *.o *~ 


