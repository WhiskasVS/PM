#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Matrix {
private:
	int size;
	int** matrix;
public:
	Matrix();
	Matrix(int);
	~Matrix();

	void SwapRow(int, int);
	int* operator [](int);
	Matrix& operator = (const Matrix&);
	friend ostream& operator << (ostream&, const Matrix&);

	int GetSize() { return this->size; }
};