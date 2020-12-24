#include <windows.h>
#include <fstream>
#include <string>
#include "List.h"

void belong(List& lhs, List& rhs);
void WorkWithConsole();
void WorkWithFile();

int main() {
	setlocale(LC_CTYPE, "Rus");
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
				cout << "�� ������ ������ ������ 1 ��� 2.";
				break;
			}
		}
	}
	catch (const char* ex) {
		cout << ex;
	}
}

void belong(List& lhs, List& rhs) {
	if (lhs.getsize() > rhs.getsize())
		cout << "\n���������� ��������� ������� ������ ��������� ���������� ��������� ������� ������.";
	else if (lhs.getsize() == rhs.getsize()) {
		for (int i = 0; i < lhs.getsize(); i++) {
			if (rhs[i] != lhs[i]) {
				cout << "\n�������� ������� ������ �� ���������� �� ������ ������.";
				break;
			}
			if (rhs[i] == lhs[i] && i == rhs.getsize() - 1)
				cout << "\n�������� ������� ������ ���������� �� ������ ������.";
		}
	}
	else {
		for (int i = 0; i < rhs.getsize(); i++) {
			if (rhs[i] == lhs[0]) {
				for (int j = 0, k = i; j < lhs.getsize(); j++, k++) {
					//if (rhs[k] != lhs[j]) break;
					if (rhs[k] == lhs[j] && j == lhs.getsize() - 1) {
						cout << "\n�������� ������� ������ ���������� �� ������ ������.";
						return;
					}
				}
			}
		}
		cout << "\n�������� ������� ������ �� ���������� �� ������ ������.";
	}
}

void WorkWithConsole() {
	int n, m;
	cout << "\n������� ���������� ���������: ";
	cin >> n;
	List list1(n);
	cout << "������ ������:";
	list1.show();
	cout << "\n";
	cout << "\n������� ���������� ���������: ";
	cin >> m;
	List list2(m);
	cout << "������ ������:";
	list2.show();
	while (true) {
		cout << "\n\n�������� ��, ��� �� ������ �������:\n";
		cout << "1. �������� ������� � ������ �� ��������� �����.\n";
		cout << "2. ������� ������� �� ������ �� ���������� ������.\n";
		cout << "3. ���������, ���������� �� �������� ������� ������ �� ������.\n";
		cout << "0. ����� �� ���������.\n";
		cout << "����� ��������: ";
		int choice, num1, num2, ind1, ind2, element;
		cin >> choice;
		switch (choice) {
		case 0: return;
		case 1:
			cout << "\n�������� ������: ";
			cin >> num1;
			if (num1 > 2 || num1 <= 0) throw "��� ������ � ����� �������.";
			else {
				cout << "�������: ";
				cin >> element;
				cout << "����� ��������: ";
				cin >> ind1;
				switch (num1) {
				case 1:
					list1.insert(element, ind1 - 1);
					cout << "������ ������:";
					list1.show();
					break;
				case 2:
					list2.insert(element, ind1 - 1);
					cout << "������ ������:";
					list2.show();
					break;
				default:
					break;
				}
			}
			break;
		case 2:
			cout << "\n�������� ������: ";
			cin >> num2;
			if (num2 > 2 || num2 <= 0) throw "��� ������ � ����� �������.";
			else {
				cout << "����� ��������: ";
				cin >> ind2;
				switch (num2) {
				case 1:
					list1.removeAt(ind2 - 1);
					cout << "������ ������:";
					list1.show();
					break;
				case 2:
					list2.removeAt(ind2 - 1);
					cout << "������ ������:";
					list2.show();
					break;
				default:
					break;
				}
			}
			break;
		case 3:
			belong(list1, list2);
			break;
		default:
			cout << "������������ ��������.\n";
			break;
		}
	}
}

void WorkWithFile() {
	ifstream filein("Lists.txt");
	if (filein.peek() == EOF) throw "\n���� ����.\n";
	int n;
	string str1, str2;
	List list1;
	List list2;
	getline(filein, str1);
	for (int i = 0; i < str1.length(); i += 2)
		list1.push_back(str1[i] - '0');
	str2 = str1;
	getline(filein, str2);
	for (int i = 0; i < str2.length(); i += 2)
		list2.push_back(str2[i] - '0');
	cout << "\n������ ������:";
	list1.show();
	cout << "\n������ ������:";
	list2.show();
	filein.close();
	ofstream fileout("Lists.txt");
	while (true) {
		cout << "\n\n�������� ��, ��� �� ������ �������:\n";
		cout << "1. �������� ������� � ������ �� ��������� �����.\n";
		cout << "2. ������� ������� �� ������ �� ���������� ������.\n";
		cout << "3. ���������, ���������� �� �������� ������� ������ �� ������.\n";
		cout << "4. �������� ����� ������ � ���� � ����� �� ���������.\n";
		cout << "����� ��������: ";
		int choice, num1, num2, ind1, ind2, element;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "\n�������� ������: ";
			cin >> num1;
			if (num1 > 2 || num1 <= 0) throw "��� ������ � ����� �������.";
			else {
				cout << "�������: ";
				cin >> element;
				cout << "����� ��������: ";
				cin >> ind1;
				switch (num1) {
				case 1:
					list1.insert(element, ind1 - 1);
					cout << "������ ������:";
					list1.show();
					break;
				case 2:
					list2.insert(element, ind1 - 1);
					cout << "������ ������:";
					list2.show();
					break;
				default:
					break;
				}
			}
			break;
		case 2:
			cout << "\n�������� ������: ";
			cin >> num2;
			if (num2 > 2 || num2 <= 0) throw "��� ������ � ����� �������.";
			else {
				cout << "����� ��������: ";
				cin >> ind2;
				switch (num2) {
				case 1:
					list1.removeAt(ind2 - 1);
					cout << "������ ������:";
					list1.show();
					break;
				case 2:
					list2.removeAt(ind2 - 1);
					cout << "������ ������:";
					list2.show();
					break;
				default:
					break;
				}
			}
			break;
		case 3:
			belong(list1, list2);
			break;
		case 4:
			//fileout.trunc;
			fileout << list1;
			fileout << list2;
			fileout.close();
			cout << "\n������ ������� ��������!\n";
			return;
		default:
			cout << "������������ ��������.\n";
			break;
		}
	}
}