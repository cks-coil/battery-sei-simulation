SUBDIRS = kmc/surface kmc/param kmc/transition kmc/core param

SRCS = $(shell find . $(SUBDIRS) -maxdepth 1 -name "*.cpp")
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
HEADS = $(shell find . $(SUBDIRS) -maxdepth 1 -name "*.hpp")

CXX = g++
RM = rm -f
PRODUCT = product

MYINCLUDE_OPTS =  -I. $(patsubst %,-I%,$(SUBDIRS))
CXXFLAGS += -Wall -O2 $(MYINCLUDE_OPTS)
LDFLAGS = -lm

.SUFFIXES: .cpp .o .d
.PHONY: all depend clean objectclean dependclean execute

all: depend $(PRODUCT)

depend: $(DEPS)

clean: objectclean dependclean
	$(RM) $(PRODUCT)

objectclean:
	$(RM) $(shell find . $(SUBDIRS) -maxdepth 1 -name "*.o")

dependclean:
	$(RM) $(shell find . $(SUBDIRS) -maxdepth 1 -name "*.d")

execute: all
	./$(PRODUCT)

$(PRODUCT): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(PRODUCT) $^ $(LDFLAGS) 

.cpp.o:
	$(CXX) -c $< -o $@ $(CXXFLAGS)

.cpp.d:
	$(CXX) -c -MM $(CXXFLAGS) $< > $@

-include $(DEPS)
