#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>
#include "Set.h"
#include "Array.h"
#include "Function.h"
using namespace std;

void Task1();
void myFunction(Set&, Set&);
Set  myFunction1(Set&, Set&);
void WorkWithConsole();
void WorkWithFile();

void Task3();
void ArrIndex();
void ArrSum();
void BitSum();
void HexSum();

void Task4();
void Ellip();
void Hyperbol();

int main() {
	setlocale(LC_CTYPE, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try {
		cout << "Добро пожаловать!\n";
		int choise;
		while (true) {
			choise = 0;
			while (choise != 1 && choise != 2 && choise != 3) {
				cout << "\nВыберите задачу:\n";
				cout << "1. Задача 1\n";
				cout << "2. Задача 3\n";
				cout << "3. Задача 4\n";
				cout << "Ваш выбор: ";
				cin >> choise;
				switch (choise) {
				case 1:
					Task1();
					break;
				case 2:
					Task3();
					break;
				case 3:
					Task4();
					break;
				default:
					cout << "\nВы можете ввести только числа от 1 до 3.\n";
					break;
				}
			}
			choise = 0;
			while (choise != 1 && choise != 2) {
				cout << "Выйти из программы?\n";
				cout << "1. Да\n";
				cout << "2. Нет\n";
				cout << "Ваш выбор: ";
				cin >> choise;
				switch (choise) {
				case 1:
					return 0;
				case 2:
					break;
				default:
					cout << "\nВы можете ввести только 1 или 2.\n\n";
					break;
				}
			}
		}
	}
	catch (const char* ex) {
		cout << ex;
	}
}

void Task1() {
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
			return;
		case 2:
			WorkWithFile();
			return;
		default:
			cout << "Вы можете ввести только 1 или 2.\n\n";
			break;
		}
	}
}
void myFunction(Set& lhs, Set& rhs) {
	Set bufer1 = lhs + rhs;
	Set bufer2 = lhs * rhs;
	Set bufer = bufer1 - bufer2;
	cout << "Новое множество: ";
	bufer.show();
}
Set  myFunction1(Set& lhs, Set& rhs) {
	Set bufer1 = lhs + rhs;
	Set bufer2 = lhs * rhs;
	Set bufer = bufer1 - bufer2;
	return bufer;
}
void WorkWithConsole() {
	Set A;
	cout << "Mножество А: ";
	A.show();
	Set B;
	cout << "Mножество B: ";
	B.show();
	while (true) {
		cout << "\nВыберите то, что вы хотите сделать:\n";
		cout << "1. Вывести объединение множеств.\n";
		cout << "2. Вывести пересечение множеств.\n";
		cout << "3. Вывести разность множеств.\n";
		cout << "4. Определить, принадлежит ли заданный элемент множествам.\n";
		cout << "5. Показать элемент из множества.\n";
		cout << "6. Вывести новое множество, которое удовлетворяет условию (A+B)\\(A*B).\n";
		cout << "0. Завершить работу.\n";
		cout << "Номер операции: ";
		int choise;
		cin >> choise;
		cout << "\n";
		Set Union = A + B;
		Set Intersect = A * B;
		Set Difference = A - B;
		switch (choise) {
		case 0: return;
		case 1:
			cout << "Объединение множеств А и В: ";
			Union.show();
			break;
		case 2:
			cout << "Пересечение множеств А и В: ";
			if (Intersect.getPower() == 0) cout << "пустое множество.\n";
			else Intersect.show();
			break;
		case 3:
			cout << "Разность множеств А и В: ";
			if (Difference.getPower() == 0) cout << "пустое множество.\n";
			else Difference.show();
			break;
		case 4:
			int n;
			cout << "Введите элемент: ";
			cin >> n;
			if (A.belong(n)) cout << "\nЭлемент " << n << " принадлежит множеству А.\n";
			else cout << "\nЭлемент " << n << " не принадлежит множеству А.\n";
			if (B.belong(n)) cout << "Элемент " << n << " принадлежит множеству B.\n";
			else cout << "Элемент " << n << " не принадлежит множеству B.\n";
			break;
		case 5:
			int m;
			char set;
			cout << "Выберите множество: ";
			cin >> set;
			switch (set) {
			case 'A':
				cout << "Введите номер элемента: ";
				cin >> m;
				if (m > A.getPower() || m <= 0) throw "Во множестве нет элемента с таким номером.\n";
				else cout << A[m] << "\n";
				break;
			case 'B':
				cout << "Введите номер элемента: ";
				cin >> m;
				if (m > B.getPower() || m <= 0) throw "Во множестве нет элемента с таким номером.\n";
				else cout << B[m] << "\n";
				break;
			default:
				throw "Такого множеста не существует.\n";
				break;
			}
			break;
		case 6:
			Set *setarray;
			int l;
			cout << "Введите количество множеств: ";
			cin >> l;
			setarray = new Set[l];
			cout << "\n";
			for (int i = 0; i < l; i++) {
				cout << "Множество " << i + 1 << ": ";
				setarray[i].show();
			}
			for (int i = 0; i < l - 1; i++) {
				myFunction(setarray[i], setarray[i + 1]);
			}
			break;
		default:
			throw "Неверная операция\n";
			break;
		}
	}
}
void WorkWithFile() {
	vector<Set> sets;
	string tmp;
	fstream file;
	while (true) {
		cout << "\nВыберите то, что вы хотите сделать:\n";
		cout << "1. Вывести множества из файла.\n";
		cout << "2. Вывести новые множества, которые удовлетворяют условию (A+B)\\(A*B).\n";
		cout << "3. Добавить новые множества в файл.\n";
		cout << "0. Завершить работу.\n";
		cout << "Номер операции: ";
		int choise;
		cin >> choise;
		char ch = 'A';
		switch (choise) {
		case 0:
			return;
		case 1:
			sets.clear();
			file.open("Sets.txt", fstream::in | fstream::out | fstream::app);
			if (file.peek() == EOF) throw "\nФайл пуст!";
			while (!file.eof()) {
				tmp = "";
				getline(file, tmp);
				Set set(tmp);
				sets.push_back(set);
			}
			for (int i = 0; i < (int)sets.size(); i++, ch++)
				cout << "\nМножество " << ch << ": " << sets[i];
			cout << "\n";
			break;
		case 2:
			ch += (int)sets.size();
			for (int i = 0; i < (int)(sets.size()) - 1; i++, ch++)
				cout << "\nМножество " << ch << ": " << myFunction1(sets[i], sets[i + 1]);
			cout << "\n";
			break;
		case 3:
			file.seekg(ios::end);
			for (int i = 0; i < (int)(sets.size()) - 1; i++)
				file << "\n" << myFunction1(sets[i], sets[i + 1]);
			cout << "\nМножества успешно добавлены!\n";
			file.close();
			break;
		default:
			throw "Неверная операция\n";
			break;
		}
	}
}

void Task3() {
	while (true) {
		cout << "\nВыберите то, что вы хотите сделать:\n";
		cout << "1. Вывести элемент массива по указанному индексу.\n";
		cout << "2. Найти результат сложения двух символьных массивов.\n";
		cout << "3. Найти результат сложения двух битовых строк.\n";
		cout << "4. Найти сумму двух шестнадцатеричных чисел.\n";
		cout << "0. Завершить работу.\n";
		cout << "Номер операции: ";
		int choise;
		cin >> choise;
		cout << "\n";
		switch (choise) {
		case 0: return;
		case 1:
			ArrIndex();
			break;
		case 2:
			ArrSum();
			break;
		case 3:
			BitSum();
			break;
		case 4:
			HexSum();
			break;
		default:
			cout << "\nНеверная операция.\n";
			break;
		}
	}
}
void ArrIndex() {
	cin.ignore(3267, '\n');
	Array arr;
	cout << "Введите индекс: ";
	int index; cin >> index;
	cout << "Элемент с индексом " << index << ": " << arr[index] << "\n";
}
void ArrSum() {
	cin.ignore(3267, '\n');
	Array arr1;
	Array arr2;
	arr1.Sum(&arr2);
	cout << "Результат сложения: " << arr1;
}
void BitSum() {
	cin.ignore(3267, '\n');
	BitString arr1;
	BitString arr2;
	arr1.Sum(&arr2);
	cout << "Результат сложения: " << arr1;
}
void HexSum() {
	cin.ignore(3267, '\n');
	Hex arr1;
	Hex arr2;
	arr1.Sum(&arr2);
	cout << "Результат сложения: " << arr1;
}

void Task4() {
	int choise;
	while (true) {
		choise = 0;
		while (choise != 1 && choise != 2) {
			cout << "\nВыберите фигуру:\n";
			cout << "1. Эллипс\n";
			cout << "2. Гипербола\n";
			cout << "Ваш выбор: ";
			cin >> choise;
			cout << "\n";
			switch (choise) {
			case 1:
				Ellip();
				break;
			case 2:
				Hyperbol();
				break;
			default:
				cout << "Вы можете ввести только 1 или 2.\n";
				break;
			}
		}
		choise = 0;
		while (choise != 1 && choise != 2) {
			cout << "Желаете продолжить?\n";
			cout << "1. Да\n";
			cout << "2. Нет\n";
			cout << "Ваш выбор: ";
			cin >> choise;
			cout << "\n";
			switch (choise) {
			case 1:
				break;
			case 2:
				return;
			default:
				cout << "Вы можете ввести только 1 или 2.\n\n";
				break;
			}
		}
	}
}
void Ellip() {
	Function* ellipse = new Ellips;
	int choise;
	double x = 0.0;
	while (true) {
		cout << "\nВыберите то, что вы хотите сделать:\n";
		cout << "1. Вывести уравнение фигуры.\n";
		cout << "2. Найти значение у в точке х.\n";
		cout << "0. Завершить работу.\n";
		cout << "Ваш выбор: ";
		cin >> choise;
		cout << "\n";
		switch (choise) {
		case 0: return;
		case 1:
			ellipse->Output();
			break;
		case 2:
			cout << "Введите х: ";
			cin >> x;
			ellipse->Value(x);
			ellipse->Result();
			break;
		default:
			cout << "Неверная операция.\n";
			break;
		}
	}
}
void Hyperbol() {
	Function* hyperbola = new Hyperbola;
	int choise;
	double x = 0.0;
	while (true) {
		cout << "\nВыберите то, что вы хотите сделать:\n";
		cout << "1. Вывести уравнение фигуры.\n";
		cout << "2. Найти значение у в точке х.\n";
		cout << "0. Завершить работу.\n";
		cout << "Ваш выбор: ";
		cin >> choise;
		cout << "\n";
		switch (choise) {
		case 0: return;
		case 1:
			hyperbola->Output();
			break;
		case 2:
			cout << "Введите х: ";
			cin >> x;
			hyperbola->Value(x);
			hyperbola->Result();
			break;
		default:
			cout << "Неверная операция.\n";
			break;
		}
	}
}