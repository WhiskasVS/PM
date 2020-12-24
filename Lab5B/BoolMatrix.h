#pragma once
#include <iostream>
#include <math.h> 
using namespace std;

class Matrix {
public:
	Matrix();
	Matrix(int**, int, int);
	Matrix(const Matrix&);
	~Matrix();

	int GetRows() { return this->rows; }
	int GetColumns() { return this->columns; }
	int** GetMatrix() { return this->matrix; }

	Matrix operator + (const Matrix&);
	Matrix operator * (const Matrix&);
	Matrix& operator = (const Matrix&);
	friend ostream& operator << (ostream&, const Matrix&);
protected:
	int& GetIJ(int, int);
	int** matrix;
	int rows;
	int columns;
};

class BoolMatrix : public Matrix {
public:
	BoolMatrix();
	BoolMatrix(int**, int, int);
	BoolMatrix(const BoolMatrix&);
	~BoolMatrix();

	int NumberOfUnity();
	BoolMatrix Canon();

	BoolMatrix operator & (const BoolMatrix&);
	BoolMatrix operator | (const BoolMatrix&);
	BoolMatrix operator ^ (const BoolMatrix&);
	BoolMatrix operator + (const BoolMatrix&);
	BoolMatrix operator * (const BoolMatrix&);
	BoolMatrix& operator = (const BoolMatrix&);
private:
	void Convert(int**, int, int);
	void Swap(int&, int&);
	void Swap(int*&, int*&);
	void RemoveRow(int, int);
	void BuffCanon();
};
