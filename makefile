appname := rpgengine

SRC_DIR := src
INC_DIR := include

CXX := g++
CXXFLAGS := -I$(INC_DIR) -std=c++17

srcfiles 	:= $(shell find . -name "*.cpp")
objects := $(patsubst %.cpp, %.o, $(srcfiles))

all: $(appname)

$(appname): $(objects)
	$(CXX) $(CXXFLAGS) -shared $(objects) -o lib$(appname).so 
	ar r lib$(appname).a $(objects)

depend: .depend

.depend: $(srcfiles)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -c -fPIC -MM $^>>./.depend;

clean:
	rm -f $(objects)

dist-clean: clean
	rm -f *~ .depend

veryclean: clean dist-clean
	rm -f lib/*

include .depend