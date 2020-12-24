#include "BoolMatrix.h"
#include <windows.h>

int main() {
	setlocale(LC_CTYPE, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try {
		cout << "Добро пожаловать!\n";
		BoolMatrix A;
		cout << A;
		BoolMatrix B;
		cout << B;
		BoolMatrix C1 = A;
		BoolMatrix C2 = B;
		while (true) {
			cout << "\nВыберите то, что вы хотите сделать:\n";
			cout << "1. Вывести матрицу.\n";
			cout << "2. Определить количество единиц в матрице.\n";
			cout << "3. Вывести каноническую форму матрицы.\n";
			cout << "4. Вывести сумму (дизъюнкцию) матриц А и В.\n";
			cout << "5. Вывести произведение (конъюнкцию) матриц А и В.\n";
			cout << "6. Вывести результат операции \"исключающее или\" для матриц А и В.\n";
			cout << "7. Присвоить новой матрице С элементы матрицы А или В.\n";
			cout << "0. Выход из программы.\n";
			cout << "Номер операции: ";
			int choice;
			char m, m1, m2, m3;
			cin >> choice;
			switch (choice) {
			case 0: return 0;
			case 1:
				cout << "\nВыберете матрицу: ";
				cin >> m;
				switch (m) {
				case 'A':
				case 'a':
					cout << "\nМатрица A:\n" << A;
					break;
				case 'B':
				case 'b':
					cout << "\nМатрица B:\n" << B;
					break;
				default:
					cout << "\nНет такой матрицы.\n";
					break;
				}
				break;
			case 2:
				cout << "\nВыберете матрицу: ";
				cin >> m1;
				switch (m1) {
				case 'A':
				case 'a':
					cout << "\nКоличество единиц в матрице А: " << A.NumberOfUnity() << "\n";
					break;
				case 'B':
				case 'b':
					cout << "\nКоличество единиц в матрице B: " << B.NumberOfUnity() << "\n";
					break;
				default:
					cout << "\nНет такой матрицы.\n";
					break;
				}
				break;
			case 3:
				cout << "\nВыберете матрицу: ";
				cin >> m2;
				switch (m2) {
				case 'A':
				case 'a':
					cout << "\nКаноническая форма матрицы А:\n" << A.Canon();
					break;
				case 'B':
				case 'b':
					cout << "\nКаноническая форма матрицы B:\n" << B.Canon();
					break;
				default:
					cout << "\nНет такой матрицы.\n";
					break;
				}
				break;
			case 4:
				cout << "\nСумма (дизъюнкция) матриц А и В:\n" << A + B;
				break;
			case 5:
				cout << "\nПроизведение (конъюнкция) матриц А и В:\n" << A * B;
				break;
			case 6:
				cout << "\nPезультат операции \"исключающее или\" для матриц А и В:\n" << (A ^ B);
				break;
			case 7:
				cout << "\nВыберете матрицу: ";
				cin >> m3;
				switch (m3) {
				case 'A':
				case 'a':
					cout << "\nМатрица С:\n" << C1;
					break;
				case 'B':
				case 'b':
					cout << "\nМатрица С:\n" << C2;
					break;
				default:
					cout << "\nНет такой матрицы.\n";
					break;
				}
				break;
			default:
				cout << "Неправильная операция.\n";
				break;
			}
		}
	}
	catch (const char* ex) {
		cout << ex;
	}
}