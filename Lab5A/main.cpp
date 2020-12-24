#include <iostream>
#include <string>
#include <windows.h>
#include "Pets.h"
using namespace std;

void MyCat();
void MyDog();
void MyParrot();
void MyTurtle();

//void MyCats(Cat*&,int);
//void MyDogs(Dog*&,int);
//void MyParrots(Parrot*&,int);
//void MyTurtles(Turtle*&,int);
//void EnterNumber(int&);

int main() {
	setlocale(LC_CTYPE, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Добро пожаловать!\n";
	try {
		//Cat* cats;
		//Dog* dogs;
		//Parrot* parrots;
		//Turtle* turtles;
		//int number1 = 0, number2 = 0, number3 = 0, number4 = 0;
		while (true) {
			cout << "\nКакое у вас домашнее животное?\n";
			cout << "1. Кот (кошка)\n";
			cout << "2. Пёс (собака)\n";
			cout << "3. Попугай\n";
			cout << "4. Черепаха\n";
			//cout << "5. Вывод Ваших животных\n";
			cout << "Ваш ответ: ";
			int animal;
			cin >> animal;
			cout << "\n";
			switch (animal) {
			case 1:
				//EnterNumber(number1);
				MyCat();
				break;
			case 2:
				//EnterNumber(number2);
				MyDog();
				break;
			case 3:
				//EnterNumber(number3);
				MyParrot();
				break;
			case 4:
				//EnterNumber(number4);
				MyTurtle();
				break;
			default:
				cout << "Нет такого варианта ответа.";
			}
			cout << "\n\nХотите продолжить?\n";
			cout << "1. Да.\n";
			cout << "2. Нет.\n";
			int choise;
			while (true) {
				cout << "Ваш выбор: ";
				cin >> choise;
				if (choise == 1 || choise == 2) break;
				else cout << "\nВы можете ввести только 1 или 2.\n\n";
			}
			if (choise == 2) return 0;
		}
	}
	catch (string ex) {
		cout << ex;
	}
}

void MyCat() {
	Cat cat;
	cat.Show();
}

void MyDog() {
	Dog dog;
	dog.Show();
}

void MyParrot() {
	Parrot parrot;
	parrot.Show();
}

void MyTurtle() {
	cout << "Она морская, сухопутная или пресноводная? ";
	string species;
	cin.ignore(3267,'\n');
	getline(cin, species);
	if (species != "Морская" && species != "морская" && species != "Сухопутная" 
		&& species != "сухопутная" && species != "Пресноводная" && species != "пресноводная")
		throw "\nНеверные данные.\n";
	Turtle turtle(species);
	turtle.Show();
}

//void MyCats(Cat*& cats,int number)
//{
//	cats = new Cat[number];
//}
//
//void MyDogs(Dog*& dogs,int number)
//{
//	dogs = new Dog[number];
//}
//
//void MyParrots(Parrot*& parrots,int number)
//{
//	parrots = new Parrot[number];
//}
//void MyTurtles(Turtle*& turtles,int number)
//{
//	turtles = new Turtle[number];
//}
//
//void EnterNumber(int& number)
//{
//	cout << "Введите количество : ";
//	cin >> number;
//}