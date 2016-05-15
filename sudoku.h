#ifndef SUDOKU_H
#define SUDOKU_H
#include<vector>
#include<fstream>

class Sudoku {
	int n = 9;
	std::vector<std::vector<int>> grid;
	bool validNum(int nx, int ny, int i);

  public:
	Sudoku(std::istream &);
	bool solve();
	void print(std::ostream &);

};

Sudoku::Sudoku(std::istream &is)
{
	for (int i = 0; i < n; i++) {
		grid.push_back(std::vector<int>());

		for (int j = 0; j < n; j++) {
			int n;
			is >> n;
			grid[i].push_back(n);
		}
	}
}

void Sudoku::print(std::ostream &os)
{
	for (auto i : grid) {
		for (auto j : i) {
			os << j << ' ';
		}

		os << std::endl;
	}

	os << std::endl;
}

bool Sudoku::validNum(int nx, int ny, int i)
{
	for (int x = 0; x < 9; x++) {
		if (grid[ny][x] == i) {
			return false;
		}
	}

	for (int y = 0; y < 9; y++) {
		if (grid[y][nx] == i) {
			return false;
		}
	}

	for (int y = (ny / 3) * 3; y < (ny / 3) * 3 + 3; y++) {
		for (int x = (nx / 3) * 3; x < (nx / 3) * 3 + 3; x++) {
			if (grid[y][x] == i) {
				return false;
			}
		}
	}

	return true;
}

bool Sudoku::solve()
{
	int emptyX, emptyY;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(grid[i][j] == 0){
				emptyX = j;
				emptyY = i;
				goto fill;
			}
		}
	}
	return true;

fill:
	for(int i = 1; i <= 9; i++){
		if(validNum(emptyX, emptyY, i)){
			grid[emptyY][emptyX] = i;

			if(solve())
				return true;
			grid[emptyY][emptyX] = 0;
		}
	}
	return false;
}
#endif
