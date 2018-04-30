CXX=clang++-5.0
CXXFLAGS=-std=c++17

all: main.o Board.o IllegalCharException.o IllegalCoordinateException.o Pair.o GameBoard.o
	$(CXX) $(CXXFLAGS) main.o Board.o IllegalCharException.o IllegalCoordinateException.o Pair.o GameBoard.o
	./a.out
Board.o: Board.cpp Board.hpp
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o

main.o: main.cpp Board.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

IllegalCharException.o: IllegalCharException.cpp IllegalCharException.hpp
	$(CXX) $(CXXFLAGS) -c IllegalCharException.cpp -o IllegalCharException.o

IllegalCoordinateException.o: IllegalCoordinateException.cpp IllegalCoordinateException.hpp
	$(CXX) $(CXXFLAGS) -c IllegalCoordinateException.cpp -o IllegalCoordinateException.o

Pair.o: Pair.cpp Pair.hpp
	$(CXX) $(CXXFLAGS) -c Pair.cpp -o Pair.o

GameBoard.o: GameBoard.cpp GameBoard.hpp
	$(CXX) $(CXXFLAGS) -c GameBoard.cpp -o GameBoard.o
clean:
	rm *.o a.out
	