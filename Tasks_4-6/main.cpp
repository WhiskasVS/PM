#include <windows.h>
#include "Matrix.h"
#include "TString.h"

void Task1();
void Task2();
void Swap(Matrix*, const int);
void AddStrings();

int main() {
	setlocale(LC_CTYPE, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try {
		cout << "����� ����������!\n";
		int choise;
		while (true) {
			cout << "\n�������� ������:\n";
			cout << "1. ������ 1\n";
			cout << "2. ������ 2\n";
			cout << "��� �����: ";
			cin >> choise;
			switch (choise) {
			case 1:
				Task1();
				break;
			case 2:
				Task2();
				break;
			default:
				cout << "�� ������ ������ ������ 1 ��� 2.\n\n";
				break;
			}
			cout << "\n������� ����������?\n";
			cout << "1. ��\n";
			cout << "2. ���\n";
			cout << "��� �����: ";
			cin >> choise;
			switch (choise) {
			case 1:
				break;
			case 2:
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

void Task1() {
	int number = 0, size = 0;
	char ch = 'A';
	cout << "\n������� ���������� ������: ";
	cin >> number;
	if (number < 1) throw "\n�������� ������.\n";
	Matrix* matrices = new Matrix[number];
	for (int i = 0; i < number; i++) {
		cout << "������� ������ ������� " << char(ch + i) << ": ";
		cin >> size;
		matrices[i] = Matrix(size);
	}
	for (int i = 0; i < number; i++, ch++)
		cout << "\n������� " << ch << ":\n" << matrices[i];
	Swap(matrices, number);
}

void Task2() {
	cin.ignore(3247, '\n');
	cout << "\n";
	TString ourString;
	cout << ourString;
	string strSearch;
	string strRemove;
	string strInsert;
	int index;
	while (true) {
		cout << "\n�������� ��, ��� �� ������ �������:\n";
		cout << "1. ���������� ����� ������.\n";
		cout << "2. ����������, ���������� �� �������� ��������� � ������.\n";
		cout << "3. ������� ��������� �� ������.\n";
		cout << "4. �������� ��������� � ������.\n";
		cout << "5. ������� ��� ������.\n";
		cout << "0. ����� �� ���������.\n";
		cout << "��� �����: ";
		int choise; cin >> choise;
		switch (choise) {
		case 0: return;
		case 1:
			cout << "\n����� ������: ";
			cout << ourString.GetSize() << "\n";
			break;
		case 2:
			cout << "\n������� ���������: ";
			cin.ignore(3247, '\n');
			getline(cin, strSearch);
			if (ourString.Search(strSearch))
				cout << "\n������ ��������� ���������� � ������.\n";
			else cout << "\n������ ��������� �� ���������� � ������.\n";
			break;
		case 3:
			cout << "\n������� ���������, ������� ������ �������: ";
			cin.ignore(3247, '\n');
			getline(cin, strRemove);
			ourString.Remove(strRemove);
			cout << ourString;
			break;
		case 4:
			cout << "\n������� ���������: ";
			cin.ignore(3247, '\n');
			getline(cin, strInsert);
			cout << "������� ������: ";
			cin >> index;
			ourString.Insert(strInsert, index);
			cout << ourString;
			break;
		case 5:
			AddStrings();
			break;
		default:
			cout << "\n�������� ��������.\n";
			break;
		}
	}
}

void Swap(Matrix* matrices, const int number) {
	int column = 0;
	char ch = 'A';
	for (int i = 0, j = 0, minRow = 0, maxRow = 0; i < number; i++, ch++, j = 0, minRow = 0, maxRow = 0) {
		cout << "\n������� ����� ������� ������� " << ch << ": ";
		cin >> column;
		if (column < 1 || column > matrices[i].GetSize()) throw "\n�������� ������.\n";
		for (int min = matrices[i][j][column - 1], max = matrices[i][j][column - 1]; j < matrices[i].GetSize(); j++) {
			if (matrices[i][j][column - 1] < min) {
				minRow = j;
				min = matrices[i][j][column - 1];
			}
			else if (matrices[i][j][column - 1] > max) {
				maxRow = j;
				max = matrices[i][j][column - 1];
			}
		}
		matrices[i].SwapRow(minRow, maxRow);
		cout << "����� ������ ������������ ��������: " << minRow + 1;
		cout << "\n����� ������ ������������� ��������: " << maxRow + 1;
		cout << "\n\n��������� ������������:\n";
		cout << matrices[i];
	}
}

void AddStrings() {
	cin.ignore(3247, '\n');
	cout << "\n";
	TString strFirst;
	TString strSecond;
	cout << strFirst + strSecond;
}