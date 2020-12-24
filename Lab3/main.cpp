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
		cout << "Добро пожаловать!\n";
		cout << "\nВыберите способ работы:\n";
		cout << "1. Работа с консолью.\n";
		cout << "2. Работа с файлом.\n";
		int choise;
		while (true) {
			cout << "Ваш выбор: ";
			cin >> choise;
			switch (choise) {
			case 1:
				WorkWithConsole();
				return 0;
			case 2:
				WorkWithFile();
				return 0;
			default:
				cout << "Вы можете ввести только 1 или 2.";
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
		cout << "\nКоличество элементов первого списка превышает количество элементов второго списка.";
	else if (lhs.getsize() == rhs.getsize()) {
		for (int i = 0; i < lhs.getsize(); i++) {
			if (rhs[i] != lhs[i]) {
				cout << "\nЭлементы первого списка не содержатся во втором списке.";
				break;
			}
			if (rhs[i] == lhs[i] && i == rhs.getsize() - 1)
				cout << "\nЭлементы первого списка содержатся во втором списке.";
		}
	}
	else {
		for (int i = 0; i < rhs.getsize(); i++) {
			if (rhs[i] == lhs[0]) {
				for (int j = 0, k = i; j < lhs.getsize(); j++, k++) {
					//if (rhs[k] != lhs[j]) break;
					if (rhs[k] == lhs[j] && j == lhs.getsize() - 1) {
						cout << "\nЭлементы первого списка содержатся во втором списке.";
						return;
					}
				}
			}
		}
		cout << "\nЭлементы первого списка не содержатся во втором списке.";
	}
}

void WorkWithConsole() {
	int n, m;
	cout << "\nВведите количество элементов: ";
	cin >> n;
	List list1(n);
	cout << "Первый список:";
	list1.show();
	cout << "\n";
	cout << "\nВведите количество элементов: ";
	cin >> m;
	List list2(m);
	cout << "Второй список:";
	list2.show();
	while (true) {
		cout << "\n\nВыберите то, что вы хотите сделать:\n";
		cout << "1. Добавить элемент в список на указанный номер.\n";
		cout << "2. Удалить элемент из списка по указанному номеру.\n";
		cout << "3. Проверить, содержатся ли элементы первого списка во втором.\n";
		cout << "0. Выход из программы.\n";
		cout << "Номер операции: ";
		int choice, num1, num2, ind1, ind2, element;
		cin >> choice;
		switch (choice) {
		case 0: return;
		case 1:
			cout << "\nВыберите список: ";
			cin >> num1;
			if (num1 > 2 || num1 <= 0) throw "Нет списка с таким номером.";
			else {
				cout << "Элемент: ";
				cin >> element;
				cout << "Номер элемента: ";
				cin >> ind1;
				switch (num1) {
				case 1:
					list1.insert(element, ind1 - 1);
					cout << "Первый список:";
					list1.show();
					break;
				case 2:
					list2.insert(element, ind1 - 1);
					cout << "Второй список:";
					list2.show();
					break;
				default:
					break;
				}
			}
			break;
		case 2:
			cout << "\nВыберите список: ";
			cin >> num2;
			if (num2 > 2 || num2 <= 0) throw "Нет списка с таким номером.";
			else {
				cout << "Номер элемента: ";
				cin >> ind2;
				switch (num2) {
				case 1:
					list1.removeAt(ind2 - 1);
					cout << "Первый список:";
					list1.show();
					break;
				case 2:
					list2.removeAt(ind2 - 1);
					cout << "Второй список:";
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
			cout << "Неправильная операция.\n";
			break;
		}
	}
}

void WorkWithFile() {
	ifstream filein("Lists.txt");
	if (filein.peek() == EOF) throw "\nФайл пуст.\n";
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
	cout << "\nПервый список:";
	list1.show();
	cout << "\nВторой список:";
	list2.show();
	filein.close();
	ofstream fileout("Lists.txt");
	while (true) {
		cout << "\n\nВыберите то, что вы хотите сделать:\n";
		cout << "1. Добавить элемент в список на указанный номер.\n";
		cout << "2. Удалить элемент из списка по указанному номеру.\n";
		cout << "3. Проверить, содержатся ли элементы первого списка во втором.\n";
		cout << "4. Записать новые списки в файл и выйти из программы.\n";
		cout << "Номер операции: ";
		int choice, num1, num2, ind1, ind2, element;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "\nВыберите список: ";
			cin >> num1;
			if (num1 > 2 || num1 <= 0) throw "Нет списка с таким номером.";
			else {
				cout << "Элемент: ";
				cin >> element;
				cout << "Номер элемента: ";
				cin >> ind1;
				switch (num1) {
				case 1:
					list1.insert(element, ind1 - 1);
					cout << "Первый список:";
					list1.show();
					break;
				case 2:
					list2.insert(element, ind1 - 1);
					cout << "Второй список:";
					list2.show();
					break;
				default:
					break;
				}
			}
			break;
		case 2:
			cout << "\nВыберите список: ";
			cin >> num2;
			if (num2 > 2 || num2 <= 0) throw "Нет списка с таким номером.";
			else {
				cout << "Номер элемента: ";
				cin >> ind2;
				switch (num2) {
				case 1:
					list1.removeAt(ind2 - 1);
					cout << "Первый список:";
					list1.show();
					break;
				case 2:
					list2.removeAt(ind2 - 1);
					cout << "Второй список:";
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
			cout << "\nСписки успешно записаны!\n";
			return;
		default:
			cout << "Неправильная операция.\n";
			break;
		}
	}
}