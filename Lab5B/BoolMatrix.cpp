#include "BoolMatrix.h"

Matrix::Matrix() {
	int n = 0, m = 0;
	cout << "\nВведите количество строк: ";
	cin >> n;
	if (n < 1) throw "\nНеверные данные! Число строк должно быть больше 0.\n";
	cout << "Введите количество столбцов: ";
	cin >> m;
	if (m < 1) throw "\nНеверные данные! Число столбцов должно быть больше 0.\n";
	this->rows = n;
	this->columns = m;
	matrix = new int*[rows];
	for (int i = 0; i < rows; i++) matrix[i] = new int[columns];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "Элемент [" << i + 1 << "][" << j + 1 << "]: ";
			cin >> this->matrix[i][j];
		}
	}
}

Matrix::Matrix(int** matrix, int rows, int columns) {
	if (rows < 1) throw "\nНеверные данные! Число строк должно быть больше 0.\n";
	if (columns < 1) throw "\nНеверные данные! Число столбцов должно быть больше 0.\n";
	if (!matrix) throw "\nМатрицa не существует.\n";
	this->rows = rows;
	this->columns = columns;
	this->matrix = new int*[this->rows];
	for (int i = 0; i < this->rows; i++)  this->matrix[i] = new int[this->columns];
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->columns; j++)
			this->matrix[i][j] = matrix[i][j];
}

Matrix::Matrix(const Matrix& matrix) : Matrix(matrix.matrix, matrix.rows, matrix.columns) {}

Matrix::~Matrix() {
	for (int i = 0; i < rows; i++)
		delete matrix[i];
	delete[] matrix;
}

int& Matrix::GetIJ(int i, int j) {
	return matrix[i][j];
}

Matrix Matrix::operator + (const Matrix& other) {
	if (rows != other.rows || columns != other.columns)
		throw "\nНевозможно выполнить операцию сложения. Размеры матриц не совпадают.\n";
	int** buff = new int*[rows];
	for (int i = 0; i < rows; i++)
		buff[i] = new int[columns];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			buff[i][j] = matrix[i][j] + other.matrix[i][j];
	Matrix buffer(buff, rows, columns);
	for (int i = 0; i < rows; i++)
		delete buff[i];
	delete[] buff;
	return buffer;
}

Matrix Matrix::operator * (const Matrix& other) {
	if (columns != other.rows) throw "\nНевозможно выполнить операцию умножения.\n";
	int** buff = new int*[rows];
	for (int i = 0; i < rows; i++)
		buff[i] = new int[other.columns];
	for (int i = 0, number = 0; i < rows; i++)
		for (int k = 0; k < other.columns; k++, number = 0) {
			for (int j = 0; j < columns; j++)
				number += matrix[i][j] * other.matrix[j][k];
			buff[i][k] = number;
		}
	Matrix matrix(buff, rows, other.columns);
	for (int i = 0; i < rows; i++)
		delete buff[i];
	delete[] buff;
	return matrix;
}

Matrix& Matrix::operator = (const Matrix& other) {
	this->rows = other.rows;
	this->columns = other.columns;
	for (int i = 0; i < rows; i++)
		delete matrix[i];
	delete[] matrix;
	this->matrix = new int*[rows];
	for (int i = 0; i < rows; i++)
		matrix[i] = new int[columns];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] = other.matrix[i][j];
	return *this;
}

ostream& operator << (ostream& out, const Matrix& matrix) {
	for (int i = 0; i < matrix.rows; i++) {
		for (int j = 0; j < matrix.columns; j++)
			out << " " << matrix.matrix[i][j];
		out << endl;
	}
	return out;
}

void BoolMatrix::Convert(int** matrix, int rows, int columns) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (matrix[i][j]) GetIJ(i, j) = 1;
}

void BoolMatrix::Swap(int& a, int& b) {
	int buffer = a;
	a = b;
	b = buffer;
}

void BoolMatrix::Swap(int*& lhs, int*& rhs) {
	int* buff = lhs;
	lhs = rhs;
	rhs = buff;
}

void BoolMatrix::RemoveRow(int row, int number) {
	int** buffer = new int*[rows - number];
	for (int i = 0; i < rows - number; i++)
		buffer[i] = new int[columns];
	for (int i = 0, k = 0; i < rows - number + 1; i++) {
		if (i == row) continue;
		for (int j = 0; j < columns; j++)
			buffer[k][j] = matrix[i][j];
		k++;
	}
	for (int i = 0; i < rows - number + 1; i++) delete matrix[i];
	delete[] matrix;
	matrix = new int*[rows - number];
	for (int i = 0; i < rows - number; i++)
		matrix[i] = new int[columns];
	for (int i = 0; i < rows - number; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] = buffer[i][j];
	for (int i = 0; i < rows - number; i++) delete buffer[i];
	delete[] buffer;
}

void BoolMatrix::BuffCanon() {
	int numberOFRow = 0;
	for (int i = 0; i < rows; i++, numberOFRow = 0) {
		for (int j = i + 1; j < rows - numberOFRow; j++)
			if (matrix[i][0] == matrix[j][0])
				for (int k = 1; k < columns; k++) {
					if (matrix[i][k] != matrix[j][k]) break;
					if (matrix[i][k] == matrix[j][k] && k == columns - 1) {
						numberOFRow++;
						RemoveRow(j, numberOFRow);
						j--;
					}
				}
		if (numberOFRow) rows -= numberOFRow;
	}
	int *buffer = new int[rows];
	for (int i = 0, number = 0; i < rows; i++, number = 0) {
		for (int j = columns - 1, k = 0; j >= 0; j--, k++)
			number += pow(2, k) * matrix[i][j];
		buffer[i] = number;
	}
	for (int i = 0, min = i; i < rows - 1; i++, min = i) {
		for (int j = i + 1; j < rows; j++)
			if (buffer[j] < buffer[min]) min = j;
		if (i != min) {
			Swap(matrix[i], matrix[min]);
			Swap(buffer[i], buffer[min]);
		}
	}
	delete[] buffer;
}

BoolMatrix::BoolMatrix() : Matrix() {
	Convert(GetMatrix(), GetRows(), GetColumns());
}

BoolMatrix::BoolMatrix(int** matrix, int rows, int columns) : Matrix(matrix, rows, columns) {
	Convert(GetMatrix(), GetRows(), GetColumns());
}

BoolMatrix::BoolMatrix(const BoolMatrix& matrix) : Matrix(matrix) {}

BoolMatrix::~BoolMatrix() {}

int BoolMatrix::NumberOfUnity() {
	int number = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (matrix[i][j]) number++;
	return number;
}

BoolMatrix BoolMatrix::Canon() {
	BoolMatrix Buffer(*this);
	Buffer.BuffCanon();
	return Buffer;
}

BoolMatrix BoolMatrix::operator & (const BoolMatrix& other) {
	if (this->rows != other.rows || this->columns != other.columns)
		throw "\nНевозможно выполнить операцию конъюнкции. Размеры матриц не совпадают.\n";
	int** buffer = new int*[this->rows];
	for (int i = 0; i < this->rows; i++)
		buffer[i] = new int[columns];
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->columns; j++) {
			if (this->matrix[i][j] && other.matrix[i][j])
				buffer[i][j] = 1;
			else
				buffer[i][j] = 0;
		}
	BoolMatrix buff(buffer, this->rows, this->columns);
	for (int i = 0; i < this->rows; i++)
		delete buffer[i];
	delete[] buffer;
	return buff;
}

BoolMatrix BoolMatrix::operator | (const BoolMatrix& other) {
	if (this->rows != other.rows || this->columns != other.columns)
		throw "\nНевозможно выполнить операцию дизъюнкции. Размеры матриц не совпадают.\n";
	int** buffer = new int*[this->rows];
	for (int i = 0; i < this->rows; i++)
		buffer[i] = new int[columns];
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->columns; j++) {
			if (!this->matrix[i][j] && !other.matrix[i][j])
				buffer[i][j] = 0;
			else
				buffer[i][j] = 1;
		}
	BoolMatrix buff(buffer, this->rows, this->columns);
	for (int i = 0; i < this->rows; i++)
		delete buffer[i];
	delete[] buffer;
	return buff;
}

BoolMatrix BoolMatrix::operator ^ (const BoolMatrix& other) {
	if (this->rows != other.rows || this->columns != other.columns)
		throw "\nНевозможно выполнить операцию. Размеры матриц не совпадают.\n";
	int** buffer = new int*[this->rows];
	for (int i = 0; i < this->rows; i++)
		buffer[i] = new int[columns];
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->columns; j++) {
			if ((this->matrix[i][j] && !other.matrix[i][j]) || (!this->matrix[i][j] && other.matrix[i][j]))
				buffer[i][j] = 1;
			else
				buffer[i][j] = 0;
		}
	BoolMatrix buff(buffer, this->rows, this->columns);
	for (int i = 0; i < this->rows; i++)
		delete buffer[i];
	delete[] buffer;
	return buff;
}

BoolMatrix BoolMatrix::operator + (const BoolMatrix& other) {
	return *this | other;
}
BoolMatrix BoolMatrix::operator * (const BoolMatrix& other) {
	return *this & other;
}
BoolMatrix& BoolMatrix::operator = (const BoolMatrix& other) {
	Matrix:: operator = (other);
	return *this;
}