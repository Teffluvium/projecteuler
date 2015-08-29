TGT          = problem_template
SRCS         = ${TGT}.cpp
OBJS         = ${SRCS:.cpp=.o}

#--------------------------
-include ../makefile.common

#--------------------------
INCLUDES     = -I. # Set include paths here, if any
LDFLAGS      =     # Set load library flags here, if any
INSTALLLIST += 


#--------------------------
.PHONY: all
all: ${TGT} install

#--------------------------
-include ../makefile.targets.common
