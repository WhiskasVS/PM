#include "Matrix.h"
#include <ctime>

Matrix::Matrix() {
	this->size = 1;
	matrix = new int*[size];
	for (int i = 0; i < size; i++)
		matrix[i] = new int[size] {};
}
Matrix::Matrix(int size) {
	if (size < 1) throw "\nНеверные данные.\n";
	this->size = size;
	matrix = new int*[size];
	for (int i = 0; i < size; i++) matrix[i] = new int[size];
	srand(time(0));
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix[i][j] = rand() % 19 - 9;
}
Matrix::~Matrix() {
	for (int i = 0; i < size; i++)
		delete[] matrix[i];
	delete[] matrix;
}

void Matrix::SwapRow(int row1, int row2) {
	int* buffer = this->matrix[row1];
	this->matrix[row1] = this->matrix[row2];
	this->matrix[row2] = buffer;
}
int* Matrix::operator[](int index) {
	return this->matrix[index];
}
Matrix& Matrix::operator=(const Matrix& other) {
	for (int i = 0; i < this->size; i++) delete[] matrix[i];
	delete[] matrix;
	matrix = nullptr;
	this->size = other.size;
	this->matrix = new int*[size];
	for (int i = 0; i < size; i++) matrix[i] = new int[size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix[i][j] = other.matrix[i][j];
	return *this;
}
ostream& operator << (ostream& out, const Matrix& matrix) {
	for (int i = 0; i < matrix.size; i++) {
		for (int j = 0; j < matrix.size; j++)
			out << setw(2) << matrix.matrix[i][j] << " ";
		out << endl;
	}
	return out;
}