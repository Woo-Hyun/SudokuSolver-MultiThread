#include "SudokuSolver.hpp"
#include "BoardMaker.hpp"
#include <iostream>
using namespace std;

const bool SudokuSolver::check_square(const int& rows, const int& cols) const {
	int** check = board_ptr->sudoku_board;
	int saved[10] = { 0 };
	for (auto i = rows; i < rows + 3; ++i) {
		for (auto j = cols; j < cols + 3; ++j) {
			auto val = check[i][j];
			if (saved[val] != 0) {
				return false;
			}
			else {
				saved[val] = 1;
			}
		}
	}
	return true;
}

const bool SudokuSolver::run_cols() const {
	int** check = board_ptr->sudoku_board;
	for (auto i = 0; i < 9; ++i) {
		int col[10] = { 0 };
		for (auto j = 0; j < 9; ++j) {
			auto val = check[j][i];
			if (col[val] != 0) {
				return false;
			}
			else {
				col[val] = 1;
			}
		}
	}
	return true;
}

const bool SudokuSolver::run_rows() const {
	int** check = board_ptr->sudoku_board;
	for (auto i = 0; i < 9; ++i) {
		int row[10] = { 0 };
		for (auto j = 0; j < 9; ++j) {
			auto val = check[i][j];
			if (row[val] != 0) {
				return false;
			}
			else {
				row[val] = 1;
			}
		}
	}
	return true;
}
