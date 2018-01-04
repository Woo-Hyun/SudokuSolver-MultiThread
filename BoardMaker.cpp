#include "BoardMaker.hpp"
#include <fstream>
#include <string>
using namespace std;

BoardMaker::BoardMaker() noexcept{
	sudoku_board = new int*[9];
	for(auto i = 0; i < 9; ++i)
		sudoku_board[i] = new int[9];
}

BoardMaker::~BoardMaker() noexcept{
	for(auto i = 0; i < 9; ++i)
		delete[] sudoku_board[i];
	delete[] sudoku_board;
}

void BoardMaker::FileToBoard(const string& path) const {
	ifstream read;

	char templine[100];

	read.open(path);

	if (read.is_open()) {
		auto i = 0;
		while (read.getline(templine, sizeof(templine))) {
			for (auto j = 0; j < 9; ++j) {
				sudoku_board[i][j] = static_cast<int>(templine[j]) - 48;
			}
			++i;
		}
	}

	read.close();

	cout << "This file is..." << endl;
	for (auto i = 0; i < 9; ++i) {
		for (auto j = 0; j < 9; ++j) {
			cout << sudoku_board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
