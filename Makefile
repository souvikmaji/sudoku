all: sudoku.h main.cpp
	g++ -std=c++11 main.cpp -o sudoku
clean:
	rm sudoku
