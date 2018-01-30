#include "BoardMaker.hpp"
#include "SudokuSolver.hpp"
#include <iostream>
#include <string>
#include <thread>
using namespace std;

int main() {
	cout << "Hello!! This is Sudoku-Solver with c++." << endl;
	cout << "This program services \"Solved\" or \"NOT Solved\" value about your 9X9 Sudoku board." << endl;
	cout << "If you understood, please press ENTER." << endl;
	getchar();

	string path;

	cout << "Enter your path of your text file." << endl;
	cin >> path;
	BoardMaker* board;
	board = new BoardMaker();
	board->FileToBoard(path);

	SudokuSolver* solver;
	solver = new SudokuSolver(board);

	bool result0, result1, result2, result3, result4, result5, result6, result7, result8, result9, result10;


	thread thr0([&]() {result0 = solver->run_rows(); });
	thread thr1([&]() {result1 = solver->run_cols(); });
	thread thr2([&]() {result2 = solver->check_square(0, 0); });
	thread thr3([&]() {result3 = solver->check_square(0, 3); });
	thread thr4([&]() {result4 = solver->check_square(0, 6); });
	thread thr5([&]() {result5 = solver->check_square(3, 0); });
	thread thr6([&]() {result6 = solver->check_square(3, 3); });
	thread thr7([&]() {result7 = solver->check_square(3, 6); });
	thread thr8([&]() {result8 = solver->check_square(6, 0); });
	thread thr9([&]() {result9 = solver->check_square(6, 3); });
	thread thr10([&]() {result10 = solver->check_square(6, 6); });

	thr0.join();
	thr1.join();
	thr2.join();
	thr3.join();
	thr4.join();
	thr5.join();
	thr6.join();
	thr7.join();
	thr8.join();
	thr9.join();
	thr10.join();

	if (result0 == true
		&& result1 == true
		&& result2 == true
		&& result3 == true
		&& result4 == true
		&& result5 == true
		&& result6 == true
		&& result7 == true
		&& result8 == true
		&& result9 == true
		&& result10 == true)
		cout << "Sudoku is Solved!!" << endl;
	else
		cout << "Sudoku is NOT Solved!!" << endl;

	delete solver;
	delete board;
}
