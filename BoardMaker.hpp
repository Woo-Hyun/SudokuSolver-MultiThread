#pragma once
#include <iostream>
#include <string>
using namespace std;

class BoardMaker{
private:
	int** sudoku_board;
public:
	BoardMaker() noexcept;
	~BoardMaker() noexcept;
	void FileToBoard(const string& path) const;
	friend class SudokuSolver;
};
