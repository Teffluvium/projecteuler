SRCS    = problem_102.cpp
OBJS    = $(SRCS:.cpp=.o)
TGT     = problem_102
LDFLAGS = # Set load library flags here, if any

.PHONY: $(TGT) # Default target has TGT prerequisite
.PHONY: clean

# Target has OBJS prerequisite
# CXX command is g++, @ is TGT, ^ loops on each OBJ
$(TGT): $(OBJS)
	$(CXX) -o $@ $(LDFLAGS) $^

# Target does not have prerequisite
clean:
	/bin/rm -f $(OBJS) $(SRCS:.cpp=.d)

# Include automatically generated dependencies
-include $(SRCS:.cpp=.d) 

# Set include paths here, if any
INCLUDES = -I.

# Compiler Flags
CXXFLAGS = -o3 -g -ggdb -Wall

# List of include paths
CPPFLAGS = $(INCLUDES)

# Automate Generation of Dependencies
#	where $< is all my.cpp files and > redirects output to $@ file called my.d
#	and $(CXX) is g++ with -MM option to build dependencies
%.d: %.cpp
	$(CXX) $(INCLUDES) -MM $< > $@
