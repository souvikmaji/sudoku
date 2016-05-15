#include<iostream>
#include"sudoku.h"

using namespace std;

int main(int argc, char **argv)
{
	if(argc < 2){
		cerr << "Input fille missing.\n";
		cerr << "Usage: ./sudoku input\n";
		exit(1);
	}
	ifstream in(argv[1]);

	Sudoku s(in);
	s.solve();

	s.print(cout);
	return 0;
}
