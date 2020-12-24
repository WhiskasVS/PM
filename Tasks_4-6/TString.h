#pragma once
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int maxSize = 255;
const int myByte = 8;

class TString {
private:
	string arr;
	bool* array = new bool[maxSize + 1]{};
	void transferToBinaryFromChar(int, int);
	//void transferToCharFromBinary(bool*);
public:
	TString();
	~TString() {}

	bool Search(string);
	void Remove(string);
	void Insert(string, int);
	int  GetSize() { return int(this->arr.size()); }

	TString& operator + (const TString&);
	friend ostream& operator << (ostream&, const TString&);
};