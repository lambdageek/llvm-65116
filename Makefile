
.PHONY: all clean

all: exampleWorks exampleNoDtor

SOURCES=runMe.cpp countCalls.cpp throwingFunc.cpp outlinedIndirectCaller.cpp main.cpp

CXXFLAGS=-g -O2 -Wall -fexceptions

exampleWorks: $(SOURCES)
	clang++ -o $@ $(CXXFLAGS) $^

exampleNoDtor: $(SOURCES)
	clang++ -o $@ $(CXXFLAGS) -DINLINE_CALLER=1 $^

clean:
	-rm -f exampleWorks exampleCrashes
