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
	cout << "����� ����������!\n";
	try {
		//Cat* cats;
		//Dog* dogs;
		//Parrot* parrots;
		//Turtle* turtles;
		//int number1 = 0, number2 = 0, number3 = 0, number4 = 0;
		while (true) {
			cout << "\n����� � ��� �������� ��������?\n";
			cout << "1. ��� (�����)\n";
			cout << "2. ϸ� (������)\n";
			cout << "3. �������\n";
			cout << "4. ��������\n";
			//cout << "5. ����� ����� ��������\n";
			cout << "��� �����: ";
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
				cout << "��� ������ �������� ������.";
			}
			cout << "\n\n������ ����������?\n";
			cout << "1. ��.\n";
			cout << "2. ���.\n";
			int choise;
			while (true) {
				cout << "��� �����: ";
				cin >> choise;
				if (choise == 1 || choise == 2) break;
				else cout << "\n�� ������ ������ ������ 1 ��� 2.\n\n";
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
	cout << "��� �������, ���������� ��� ������������? ";
	string species;
	cin.ignore(3267,'\n');
	getline(cin, species);
	if (species != "�������" && species != "�������" && species != "����������" 
		&& species != "����������" && species != "������������" && species != "������������")
		throw "\n�������� ������.\n";
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
//	cout << "������� ���������� : ";
//	cin >> number;
//}