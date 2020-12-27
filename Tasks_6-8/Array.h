#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Array {
public:
	Array();
	Array(const Array&);
	~Array() { delete[] this->array; this->array = nullptr; }

	int GetLength() { return this->length; }
	char* GetArray() { return this->array; }

	char operator [] (int);
	Array& operator = (const Array&);
	friend ostream& operator << (ostream&, const Array&);

	virtual void Sum(Array*);
protected:
	char* array;
	int length;
};

class BitString : public Array {
private:
	void Convert();
public:
	BitString();
	~BitString() {}

	void Sum(Array*) override;
	friend ostream& operator << (ostream&, const BitString&);
};

class Hex : public Array {
private:
	void TransferToDecimal(const char*, const int, int&);
	void TransferToHex(const int);
	char Transfer(int);
public:
	Hex();
	~Hex() {}

	void Sum(Array*) override;
	friend ostream& operator << (ostream&, const Hex&);
};