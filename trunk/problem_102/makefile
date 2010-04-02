TGT          = problem_102
SRCS         = ${TGT}.cpp
OBJS         = ${SRCS:.cpp=.o}

#--------------------------
-include ../makefile.common

#--------------------------
INCLUDES     = -I. # Set include paths here, if any
LDFLAGS      =     # Set load library flags here, if any
INSTALLLIST += \
               problem_102.triangles.txt

#--------------------------
.PHONY: all
all: ${TGT} install

#--------------------------
-include ../makefile.targets.common
