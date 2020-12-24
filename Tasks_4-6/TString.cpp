#include "TString.h"

TString::TString() {
	cout << "Введите строку: ";
	getline(cin, arr);
	if (arr.size() < 1 || arr.size() > maxSize) throw "\nДлина строки не может быть меньше 1 или больше 255.\n";
	transferToBinaryFromChar(int(arr.size()), 0);
	for (int i = myByte, j = 0; j < arr.size(); i += myByte, j++)
		transferToBinaryFromChar(int(arr[j]), i);
}
void TString::transferToBinaryFromChar(int value, int begin) {
	int size = 0, buffValue = value;
	while (buffValue) {
		buffValue /= 2;
		size++;
	}
	bool* buff = new bool[size];
	for (int i = size - 1; i >= 0; i--, value /= 2)
		buff[i] = value % 2;
	for (int i = begin, j = 0; i < begin + myByte; i++, j++) {
		while (i < begin + myByte - size) {
			array[i] = 0;
			i++;
		}
		array[i] = buff[j];
	}
	delete[] buff;
}
//void TString::transferToCharFromBinary(bool* array)
//{
//    int size = 0, number = 0;
//    for (int i = myByte - 1; i >= 0; i--)
//        size += pow(2, i);
//    string arr = "";
//    for (int i = myByte; i < myByte * size + myByte; i += myByte,number = 0)
//    {
//        for (int j = i + myByte - 1; j >= i; j--)
//            number += pow(2, j);
//        arr += number;
//    }
//}
bool TString::Search(string other) {
	if (int(arr.find(other)) != -1)
		return true;
	return false;
}
void TString::Remove(string other) {
	if (arr.find(other) == -1)
		throw "\nВ строке нет такой подстроки.\n";
	int entry = int(arr.find(other));
	string a = "", b = "";
	for (int i = 0; i < entry; i++) a += arr[i];
	for (int i = entry + int(other.size()); i < int(arr.size()); i++) b += arr[i];
	arr.clear();
	arr = a + b;
	transferToBinaryFromChar(int(arr.size()), 0);
	for (int i = myByte, j = 0; j < arr.size(); i += myByte, j++)
		transferToBinaryFromChar(int(arr[j]), i);
}
void TString::Insert(string other, int index) {
	if (index > arr.size() + 1)
		throw "\nНеверные данные. Индекс превышает максимальный.\n";
	if ((arr.size() + other.size()) > maxSize) {
		cout << "\nНевозможно вставить подстроку: размер новой строки будет превышать максимальный.\n";
		return;
	}
	if (index == arr.size() + 1) {
		arr += other;
		transferToBinaryFromChar(int(arr.size()), 0);
		for (int i = myByte, j = 0; j < arr.size(); i += myByte, j++)
			transferToBinaryFromChar(int(arr[j]), i);
	}
	else {
		string buffer1 = "", buffer2 = "";
		for (int i = 0; i < index - 1; i++) buffer1 += arr[i];
		for (int i = index - 1; i < arr.size(); i++) buffer2 += arr[i];
		arr.clear();
		arr = buffer1 + other + buffer2;
		transferToBinaryFromChar(int(arr.size()), 0);
		for (int i = myByte, j = 0; j < arr.size(); i += myByte, j++)
			transferToBinaryFromChar(int(arr[j]), i);
	}
}

TString& TString::operator + (const TString& other) {
	if (int(arr.size() + other.arr.size()) > maxSize)
		throw "\nНевозможно сложить строки. Размер новой строки будет превышать максимальный (255).\n";
	arr += other.arr;
	transferToBinaryFromChar(int(arr.size()), 0);
	for (int i = myByte, j = 0; j < arr.size(); i += myByte, j++)
		transferToBinaryFromChar(int(arr[j]), i);
	return *this;
}
ostream& operator << (ostream& os, const TString& string) {
	os << "\n" << string.arr << "\n\n";
	for (int i = 0; i < myByte; i++)
		os << string.array[i] << " ";
	os << " -- " << string.arr.size() << "\n";
	for (int i = myByte, k = 0; k < string.arr.size(); i += myByte, k++) {
		for (int j = i; j < i + myByte; j++)
			os << string.array[j] << " ";
		os << " -- " << string.arr[k] << endl;
	}
	return os;
}