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
		cout << "Добро пожаловать!\n";
		int choise;
		while (true) {
			cout << "\nВыберите задачу:\n";
			cout << "1. Задача 1\n";
			cout << "2. Задача 2\n";
			cout << "Ваш выбор: ";
			cin >> choise;
			switch (choise) {
			case 1:
				Task1();
				break;
			case 2:
				Task2();
				break;
			default:
				cout << "Вы можете ввести только 1 или 2.\n\n";
				break;
			}
			cout << "\nЖелаете продолжить?\n";
			cout << "1. Да\n";
			cout << "2. Нет\n";
			cout << "Ваш выбор: ";
			cin >> choise;
			switch (choise) {
			case 1:
				break;
			case 2:
				return 0;
			default:
				cout << "Вы можете ввести только 1 или 2.\n\n";
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
	cout << "\nВведите количество матриц: ";
	cin >> number;
	if (number < 1) throw "\nНеверные данные.\n";
	Matrix* matrices = new Matrix[number];
	for (int i = 0; i < number; i++) {
		cout << "Введите размер матрицы " << char(ch + i) << ": ";
		cin >> size;
		matrices[i] = Matrix(size);
	}
	for (int i = 0; i < number; i++, ch++)
		cout << "\nМатрица " << ch << ":\n" << matrices[i];
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
		cout << "\nВыберите то, что вы хотите сделать:\n";
		cout << "1. Определить длину строки.\n";
		cout << "2. Определить, содержится ли заданная подстрока в строке.\n";
		cout << "3. Удалить подстроку из строки.\n";
		cout << "4. Вставить подстроку в строку.\n";
		cout << "5. Сложить две строки.\n";
		cout << "0. Выйти из программы.\n";
		cout << "Ваш выбор: ";
		int choise; cin >> choise;
		switch (choise) {
		case 0: return;
		case 1:
			cout << "\nДлина строки: ";
			cout << ourString.GetSize() << "\n";
			break;
		case 2:
			cout << "\nВведите подстроку: ";
			cin.ignore(3247, '\n');
			getline(cin, strSearch);
			if (ourString.Search(strSearch))
				cout << "\nДанная подстрока содержится в строке.\n";
			else cout << "\nДанная подстрока не содержится в строке.\n";
			break;
		case 3:
			cout << "\nВведите подстроку, которую хотите удалить: ";
			cin.ignore(3247, '\n');
			getline(cin, strRemove);
			ourString.Remove(strRemove);
			cout << ourString;
			break;
		case 4:
			cout << "\nВведите подстроку: ";
			cin.ignore(3247, '\n');
			getline(cin, strInsert);
			cout << "Введите индекс: ";
			cin >> index;
			ourString.Insert(strInsert, index);
			cout << ourString;
			break;
		case 5:
			AddStrings();
			break;
		default:
			cout << "\nНеверная операция.\n";
			break;
		}
	}
}

void Swap(Matrix* matrices, const int number) {
	int column = 0;
	char ch = 'A';
	for (int i = 0, j = 0, minRow = 0, maxRow = 0; i < number; i++, ch++, j = 0, minRow = 0, maxRow = 0) {
		cout << "\nВведите номер столбца матрицы " << ch << ": ";
		cin >> column;
		if (column < 1 || column > matrices[i].GetSize()) throw "\nНеверные данные.\n";
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
		cout << "Номер строки минимального элемента: " << minRow + 1;
		cout << "\nНомер строки максимального элемента: " << maxRow + 1;
		cout << "\n\nРезультат перестановки:\n";
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