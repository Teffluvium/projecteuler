TGT          = problem_011
SRCS         = ${TGT}.cpp
OBJS         = ${SRCS:.cpp=.o}

#--------------------------
-include ../makefile.common

#--------------------------
INCLUDES     = -I. # Set include paths here, if any
LDFLAGS      =     # Set load library flags here, if any
INSTALLLIST += \
               problem_011.data.txt

#--------------------------
.PHONY: all
all: ${TGT} install

#--------------------------
-include ../makefile.targets.common
