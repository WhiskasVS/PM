#include "BoolMatrix.h"
#include <windows.h>

int main() {
	setlocale(LC_CTYPE, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try {
		cout << "����� ����������!\n";
		BoolMatrix A;
		cout << A;
		BoolMatrix B;
		cout << B;
		BoolMatrix C1 = A;
		BoolMatrix C2 = B;
		while (true) {
			cout << "\n�������� ��, ��� �� ������ �������:\n";
			cout << "1. ������� �������.\n";
			cout << "2. ���������� ���������� ������ � �������.\n";
			cout << "3. ������� ������������ ����� �������.\n";
			cout << "4. ������� ����� (����������) ������ � � �.\n";
			cout << "5. ������� ������������ (����������) ������ � � �.\n";
			cout << "6. ������� ��������� �������� \"����������� ���\" ��� ������ � � �.\n";
			cout << "7. ��������� ����� ������� � �������� ������� � ��� �.\n";
			cout << "0. ����� �� ���������.\n";
			cout << "����� ��������: ";
			int choice;
			char m, m1, m2, m3;
			cin >> choice;
			switch (choice) {
			case 0: return 0;
			case 1:
				cout << "\n�������� �������: ";
				cin >> m;
				switch (m) {
				case 'A':
				case 'a':
					cout << "\n������� A:\n" << A;
					break;
				case 'B':
				case 'b':
					cout << "\n������� B:\n" << B;
					break;
				default:
					cout << "\n��� ����� �������.\n";
					break;
				}
				break;
			case 2:
				cout << "\n�������� �������: ";
				cin >> m1;
				switch (m1) {
				case 'A':
				case 'a':
					cout << "\n���������� ������ � ������� �: " << A.NumberOfUnity() << "\n";
					break;
				case 'B':
				case 'b':
					cout << "\n���������� ������ � ������� B: " << B.NumberOfUnity() << "\n";
					break;
				default:
					cout << "\n��� ����� �������.\n";
					break;
				}
				break;
			case 3:
				cout << "\n�������� �������: ";
				cin >> m2;
				switch (m2) {
				case 'A':
				case 'a':
					cout << "\n������������ ����� ������� �:\n" << A.Canon();
					break;
				case 'B':
				case 'b':
					cout << "\n������������ ����� ������� B:\n" << B.Canon();
					break;
				default:
					cout << "\n��� ����� �������.\n";
					break;
				}
				break;
			case 4:
				cout << "\n����� (����������) ������ � � �:\n" << A + B;
				break;
			case 5:
				cout << "\n������������ (����������) ������ � � �:\n" << A * B;
				break;
			case 6:
				cout << "\nP�������� �������� \"����������� ���\" ��� ������ � � �:\n" << (A ^ B);
				break;
			case 7:
				cout << "\n�������� �������: ";
				cin >> m3;
				switch (m3) {
				case 'A':
				case 'a':
					cout << "\n������� �:\n" << C1;
					break;
				case 'B':
				case 'b':
					cout << "\n������� �:\n" << C2;
					break;
				default:
					cout << "\n��� ����� �������.\n";
					break;
				}
				break;
			default:
				cout << "������������ ��������.\n";
				break;
			}
		}
	}
	catch (const char* ex) {
		cout << ex;
	}
}