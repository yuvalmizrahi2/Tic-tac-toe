CXX=g++
CXXFLAGS=-Wall -Werror -Wvla

all: Board.o IllegalCharException.o IllegalCoordinateException.o Coordinate.o Cell.o

Board.o: Board.cpp Board.h
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o

IllegalCharException.o: IllegalCharException.cpp IllegalCharException.hpp
	$(CXX) $(CXXFLAGS) -c IllegalCharException.cpp -o IllegalCharException.o

IllegalCoordinateException.o: IllegalCoordinateException.cpp IllegalCoordinateException.hpp
	$(CXX) $(CXXFLAGS) -c IllegalCoordinateException.cpp -o IllegalCoordinateException.o

Coordinate.o: Coordinate.cpp Coordinate.hpp
	$(CXX) $(CXXFLAGS) -c Coordinate.cpp -o Coordinate.o

Cell.o: Cell.cpp Cell.hpp
	$(CXX) $(CXXFLAGS) -c Cell.cpp -o Cell.o
clean:
	rm *.o 
