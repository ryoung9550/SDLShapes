# Creation rules for SDLShapes
#

CXX=clang
CXXFLAGS=-Wall -W -std=c++14
CXXFLAGS += $(sdl2-config --cflags --libs)

default: libSDLShapes.a libSDLShapes.dylib

libSDLShapes.a: SDLShapes.o
	ar -rcv $@ $^

libSDLShapes.dylib: SDLShapes.o
	$(CXX) -dynamiclib -undefined suppress -flat_namespace -o $@ $^

SDLShapes.o: SDLShapes.cpp SDLShapes.hpp
	$(CXX) -c -fPIC SDLShapes.cpp -o $@ $(CXXFLAGS)

clean:
	rm *.o *.dylib *.a
