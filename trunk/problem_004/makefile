TGT          = problem_004
SRCS         = ${TGT}.cpp
OBJS         = $(SRCS:.cpp=.o)

#--------------------------
-include ../makefile.common

#--------------------------
INCLUDES     = -I. # Set include paths here, if any
LDFLAGS      =     # Set load library flags here, if any
INSTALLLIST +=     # Add files needed for the install here

#--------------------------
.PHONY: all
all: ${TGT} install

#--------------------------
-include ../makefile.targets.common
