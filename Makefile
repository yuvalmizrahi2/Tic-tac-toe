CXX=g++
CXXFLAGS=-Wall -Werror -Wvla

all: Board.o IllegalCharException.o IllegalCoordinateException.o Pair.o Cell.o
	$(CXX) $(CXXFLAGS) Board.o IllegalCharException.o IllegalCoordinateException.o Pair.o Cell.o

Board.o: Board.cpp Board.hpp
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o

IllegalCharException.o: IllegalCharException.cpp IllegalCharException.hpp
	$(CXX) $(CXXFLAGS) -c IllegalCharException.cpp -o IllegalCharException.o

IllegalCoordinateException.o: IllegalCoordinateException.cpp IllegalCoordinateException.hpp
	$(CXX) $(CXXFLAGS) -c IllegalCoordinateException.cpp -o IllegalCoordinateException.o

Pair.o: Pair.cpp Pair.hpp
	$(CXX) $(CXXFLAGS) -c Pair.cpp -o Pair.o

GameBoard.o: Cell.cpp Cell.hpp
	$(CXX) $(CXXFLAGS) -c Cell.cpp -o Cell.o
clean:
	rm *.o 
	