#define _CRT_SECURE_NO_WARNINGS
#include "Array.h"

Array::Array() {
	string str;
	cout << "Введите строку: ";
	getline(cin, str);
	this->length = int(str.size());
	this->array = new char[this->length];
	for (int i = 0; i < this->length; i++)
		this->array[i] = str[i];
}
Array::Array(const Array& other) {
	*this = other;
}

char Array::operator [] (int index) {
	if (index < 1 || index > this->length)
		throw "\nНеверные данные. Индекс не может быть меньше еденицы или превышать длину строки.\n";
	return this->array[index - 1];
}
Array& Array::operator = (const Array& other) {
	this->length = other.length;
	delete[] this->array;
	this->array = nullptr;
	this->array = new char[this->length];
	for (int i = 0; i < this->length; i++)
		this->array[i] = other.array[i];
	return *this;
}
ostream& operator << (ostream& os, const Array& array) {
	for (int i = 0; i < array.length; i++)
		os << array.array[i];
	os << endl;
	return os;
}

void Array::Sum(Array* other) {
	int newSize = this->length > other->length ? this->length : other->length;
	char* buffer = new char[newSize];
	for (int i = 0; i < (this->length > other->length ? other->length : this->length); i++)
		buffer[i] = this->array[i] + other->array[i];
	for (int i = this->length > other->length ? other->length : this->length; i < newSize; i++)
		buffer[i] = this->length > other->length ? this->array[i] : other->array[i];
	delete[] this->array;
	array = nullptr;
	array = new char[newSize];
	strcpy(this->array, buffer);
	this->length = newSize;
	delete[] buffer;
}

BitString::BitString() : Array() {
	Convert();
}
void BitString::Convert() {
	for (int i = 0; i < this->length; i++)
		if (this->array[i] != '0')
			this->array[i] = '1';
}
void BitString::Sum(Array* other) {
	int newSize = this->length > other->GetLength() ? this->length : other->GetLength();
	char* buffer = new char[newSize];
	for (int i = 0; i < newSize; i++)
		buffer[i] = '0';
	for (int i = 0; i < (this->length > other->GetLength() ? other->GetLength() : this->length); i++)
		if (this->array[i] == '1' || other->GetArray()[i] == '1')
			buffer[i] = '1';
	for (int i = this->length > other->GetLength() ? other->GetLength() : this->length; i < newSize; i++)
		buffer[i] = this->length > other->GetLength() ? this->array[i] : other->GetArray()[i];
	delete[] this->array;
	array = nullptr;
	array = new char[newSize];
	strcpy(this->array, buffer);
	this->length = newSize;
	delete[] buffer;
}
Hex::Hex() : Array() {
	for (int i = 0; i < this->length; i++)
		if ((array[i] < '0' || array[i] > '9') && (array[i] < 'A' || array[i] > 'F'))
			throw "\nНеверные данные. Данное число не является шестнадцатеричным.\n";
}
void Hex::Sum(Array* other) {
	int number1 = 0, number2 = 0, result = 0;
	TransferToDecimal(array, length, number1);
	TransferToDecimal(other->GetArray(), other->GetLength(), number2);
	result = number1 + number2;
	TransferToHex(result);
}
void Hex::TransferToDecimal(const char* array, const int length, int& number) {
	for (int i = length - 1, j = 0; i >= 0; i--, j++) {
		if (array[i] == 'A') {
			number += 10 * pow(16, j);
			continue;
		}
		else if (array[i] == 'B') {
			number += 11 * pow(16, j);
			continue;
		}
		else if (array[i] == 'C') {
			number += 12 * pow(16, j);
			continue;
		}
		else if (array[i] == 'D') {
			number += 13 * pow(16, j);
			continue;
		}
		else if (array[i] == 'E') {
			number += 14 * pow(16, j);
			continue;
		}
		else if (array[i] == 'F') {
			number += 15 * pow(16, j);
			continue;
		}
		number += int(array[i] - '0') * pow(16, j);
	}
}
void Hex::TransferToHex(const int number) {
	int size = 0;
	for (int i = number; i > 0; i /= 16)
		size++;
	char* buffer = new char[size];
	for (int i = size - 1, j = number; i >= 0; i--, j /= 16)
		buffer[i] = Transfer(j % 16);
	delete[] array;
	array = nullptr;
	array = new char[size];
	this->length = size;
	strcpy(array, buffer);
	delete[] buffer;
}
char Hex::Transfer(int number) {
	if (number > 9)
		return ('7' + number);
	return (number + '0');
}
ostream& operator << (ostream& os, const BitString& other) {
	for (int i = 0; i < other.length; i++)
		os << other.array[i];
	os << endl;
	return os;
}
ostream& operator << (ostream& os, const Hex& other) {
	for (int i = 0; i < other.length; i++)
		os << other.array[i];
	os << endl;
	return os;
}