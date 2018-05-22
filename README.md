Board Game  
===  

Assignment 6 in a C++ course  

Authors:
--
Yuval Mizrahi

**Introduction**
==

About the assignment:
-- 
Create a class called Board that represent the game tic-tac-toe.  
The class is built by inputing it the board's size N * N.  
Every square has to have only: '.' \ 'X' \ 'O' - the dot char represents an empty square.  
The class has to support the operators: output, =, [].  
The class has to deal with exceptions: 
inputing an illegal char or trying to exceed the board's limits throws an exception according to the case.  
    
**File list:**  
--  

```  
.: 
Board.cpp  
Board.h
Cell.cpp  
Cell.h    
Coordinate.hpp 
README.md  
IllegalCoordinateException.hpp 
IllegalCoordinateException.cpp  
IllegalCharException.cpp 
IllegalCharException.hpp
Makefile  
```  
Further look into the classes:     
--  
1. **Board.h** - This class represents a board game of tic-tac-toe. Its fields are :   
*rowcolumn* - The board's size N * N.   
*board* - The board game itself, build by a matrix of DerivedChar size N * N.         
2. **Coordinate.hpp** - This class represent a specific place in the matrix - board. Its fields are : X,Y.  
3. **Cell.hpp** - This class represent a square in the matrix - board. Its field is a char c.   
4. **IllegalCoordinateException.hpp** - This class represents an exception thrown when illegal coordinate values are given.  
5. **IllegalCharException.hpp** - This class represents an exception thrown when an illegal char is given as an input.  
The llegal chars in the game: '.', 'X', 'O' .  

Compile Command:  
--  
To compile all the files we have the file "Makefile" - converts all to binary type "file.o" files.  
In order to compile by using the Makefile file - we run the command "make".  
Need to add a main to the completion level.   
After this just need to run g++ -g *.o *.cpp.  
To clean all the binary files need to run "clean".
