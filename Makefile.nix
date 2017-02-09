# Creation rules for SDLShapes
#

CXX=clang
CXXFLAGS=-Wall -W -std=c++14
CXXFLAGS += $(sdl2-config --cflags --libs)
unamestr=$(uname)
mac=Darwin
linux=Linux

default: libSDLShapes.a libSDLShapes.so

libSDLShapes.a: SDLShapes.o
	ar -rcv $@ $^

libSDLShapes.so: SDLShapes.o
	$(CXX) -shared -o $@ $^

SDLShapes.o: SDLShapes.cpp SDLShapes.hpp
	$(CXX) -c -fPIC SDLShapes.cpp -o $@ $(CXXFLAGS)

clean:
	rm *.o *.so *.a
