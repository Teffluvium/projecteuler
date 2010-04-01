TGT     = problem_001
SRCS    = ${TGT}.cpp
OBJS    = $(SRCS:.cpp=.o)
LDFLAGS = # Set load library flags here, if any

INCLUDES = -I.                # Set include paths here, if any
CXXFLAGS = -o3 -g -ggdb -Wall # Compiler Flags
CPPFLAGS = $(INCLUDES)        # List of include paths

#--------------------------
# Include automatically generated dependencies
-include $(SRCS:.cpp=.d)

#--------------------------
.PHONY: all
all: ${TGT}

$(TGT): $(OBJS)
	@# CXX command is g++, @ is TGT, ^ loops on each OBJ
	$(CXX) -o $@ $(LDFLAGS) $^

.PHONY: clean
clean:
	@/bin/rm -fv $(OBJS) *.d

.PHONY: fresh
fresh: clean all

# Automate Generation of Dependencies
%.d: %.cpp
	$(CXX) $(INCLUDES) -MM $< > $@
	@# where $< is all my.cpp files
	@# and > redirects output to $@ file called my.d
	@# and $(CXX) is g++ with -MM option to build dependencies
