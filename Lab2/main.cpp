#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>
#include "Set.h"

using namespace std;
void myFunction(Set&, Set&);
Set myFunction1(Set&, Set&);
void WorkWithConsole();
void WorkWithFile();

int main() {
	setlocale(LC_CTYPE, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try {
		cout << "����� ����������!\n";
		cout << "\n�������� ������ ������:\n";
		cout << "1. ������ � ��������.\n";
		cout << "2. ������ � ������.\n";
		int choise;
		while (true) {
			cout << "��� �����: ";
			cin >> choise;
			switch (choise) {
			case 1:
				WorkWithConsole();
				return 0;
			case 2:
				WorkWithFile();
				return 0;
			default:
				cout << "�� ������ ������ ������ 1 ��� 2.\n\n";
				break;
			}
		}
	}
	catch (const char* ex) {
		cout << ex;
	}
}

void myFunction(Set& lhs, Set& rhs) {
	Set bufer1 = lhs + rhs;
	Set bufer2 = lhs * rhs;
	Set bufer = bufer1 - bufer2;
	cout << "����� ���������: ";
	bufer.show();
}

Set myFunction1(Set& lhs, Set& rhs) {
	Set bufer1 = lhs + rhs;
	Set bufer2 = lhs * rhs;
	Set bufer = bufer1 - bufer2;
	return bufer;
}

void WorkWithConsole() {
	Set A;
	cout << "M�������� �: ";
	A.show();
	Set B;
	cout << "M�������� B: ";
	B.show();
	while (true) {
		cout << "\n�������� ��, ��� �� ������ �������:\n";
		cout << "1. ������� ����������� ��������.\n";
		cout << "2. ������� ����������� ��������.\n";
		cout << "3. ������� �������� ��������.\n";
		cout << "4. ����������, ����������� �� �������� ������� ����������.\n";
		cout << "5. �������� ������� �� ���������.\n";
		cout << "6. ������� ����� ���������, ������� ������������� ������� (A+B)\\(A*B).\n";
		cout << "0. ����� �� ���������.\n";
		cout << "����� ��������: ";
		int choise;
		cin >> choise;
		cout << "\n";
		Set Union = A + B;
		Set Intersect = A * B;
		Set Difference = A - B;
		switch (choise) {
		case 0: return;
		case 1:
			cout << "����������� �������� � � �: ";
			Union.show();
			break;
		case 2:
			cout << "����������� �������� � � �: ";
			if (Intersect.getPower() == 0) cout << "������ ���������.\n";
			else Intersect.show();
			break;
		case 3:
			cout << "�������� �������� � � �: ";
			if (Difference.getPower() == 0) cout << "������ ���������.\n";
			else Difference.show();
			break;
		case 4:
			int n;
			cout << "������� �������: ";
			cin >> n;
			if (A.belong(n)) cout << "\n������� " << n << " ����������� ��������� �.\n";
			else cout << "\n������� " << n << " �� ����������� ��������� �.\n";
			if (B.belong(n)) cout << "������� " << n << " ����������� ��������� B.\n";
			else cout << "������� " << n << " �� ����������� ��������� B.\n";
			break;
		case 5:
			int m;
			char set;
			cout << "�������� ���������: ";
			cin >> set;
			switch (set) {
			case 'A':
				cout << "������� ����� ��������: ";
				cin >> m;
				if (m > A.getPower() || m <= 0) throw "�� ��������� ��� �������� � ����� �������.\n";
				else cout << A[m] << "\n";
				break;
			case 'B':
				cout << "������� ����� ��������: ";
				cin >> m;
				if (m > B.getPower() || m <= 0) throw "�� ��������� ��� �������� � ����� �������.\n";
				else cout << B[m] << "\n";
				break;
			default:
				throw "������ �������� �� ����������.\n";
				break;
			}
			break;
		case 6:
			Set *setarray;
			int l;
			cout << "������� ���������� ��������: ";
			cin >> l;
			setarray = new Set[l];
			cout << "\n";
			for (int i = 0; i < l; i++) {
				cout << "��������� " << i + 1 << ": ";
				setarray[i].show();
			}
			for (int i = 0; i < l - 1; i++) {
				myFunction(setarray[i], setarray[i + 1]);
			}
			break;
		default:
			throw "�������� ��������\n";
			break;
		}
	}
}

void WorkWithFile() {
	vector<Set> sets;
	string tmp;
	fstream file;
	while (true) {
		cout << "\n�������� ��, ��� �� ������ �������:\n";
		cout << "1. ������� ��������� �� �����.\n";
		cout << "2. ������� ����� ���������, ������� ������������� ������� (A+B)\\(A*B).\n";
		cout << "3. �������� ����� ��������� � ����.\n";
		cout << "0. ����� �� ���������.\n";
		cout << "����� ��������: ";
		int choise;
		cin >> choise;
		char ch = 'A';
		switch (choise) {
		case 0:
			return;
		case 1:
			sets.clear();
			file.open("Sets.txt", fstream::in | fstream::out | fstream::app);
			if (file.peek() == EOF) throw "\n���� ����!";
			while (!file.eof()) {
				tmp = "";
				getline(file, tmp);
				Set set(tmp);
				sets.push_back(set);
			}
			for (int i = 0; i < (int)sets.size(); i++, ch++)
				cout << "\n��������� " << ch << ": " << sets[i];
			cout << "\n";
			break;
		case 2:
			ch += (int)sets.size();
			for (int i = 0; i < (int)(sets.size()) - 1; i++, ch++)
				cout << "\n��������� " << ch << ": " << myFunction1(sets[i], sets[i + 1]);
			cout << "\n";
			break;
		case 3:
			file.seekg(ios::end);
			for (int i = 0; i < (int)(sets.size()) - 1; i++)
				file << "\n" << myFunction1(sets[i], sets[i + 1]);
			cout << "\n��������� ������� ���������!\n";
			file.close();
			break;
		default:
			throw "�������� ��������\n";
			break;
		}
	}
}