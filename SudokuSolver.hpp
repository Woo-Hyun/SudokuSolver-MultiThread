#pragma once
#include "BoardMaker.hpp"
#include <iostream>
using namespace std;

class SudokuSolver {
private:
	BoardMaker* board_ptr;
public:
	const bool check_square(const int& rows, const int& cols) const;
	const bool run_cols() const;
	const bool run_rows() const;
	SudokuSolver(BoardMaker* boardmaker) : board_ptr(boardmaker) {};
	~SudokuSolver() {};
};
