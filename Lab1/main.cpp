#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <windows.h>
#include "Driver.h"
#include "Bus.h"
using namespace std;

int main() {
	setlocale(LC_CTYPE, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try {
		vector<Bus> buses(10);
		cout << "Добро пожаловать!\n";
		while (true) {
			cout << "\nВыберите то, что вы хотите сделать:\n";
			cout << "1. Вывести список автобусов из файла.\n";
			cout << "2. Записать список автобусов в файл.\n";
			cout << "3. Добавить еще один автобус в список.\n";
			cout << "4. Удалить автобус из списка.\n";
			cout << "5. Показать элемент из списка.\n";
			cout << "6. Вывести список автобусов, пробег которых более 10000 км.\n";
			cout << "7. Вывести список автобусов, которые эксплуатируются больше 10 лет.\n";
			cout << "8. Вывести список автобусов, идущих по заданному маршруту.\n";
			cout << "0. Выход из программы.\n";
			cout << "Номер операции: ";
			int choice;
			cin >> choice;
			cout << "\n";
			switch (choice) {
			case 0: return 0;
			case 1:
				readFromFile(buses, "Buses.txt");
				cout << setw(18) << "Водитель: |" << setw(7) << "  №A: |"
					<< setw(7) << "  №М: |" << setw(9) << " Марка: |"
					<< setw(7) << "Год: |" << setw(11) << " Пробег в км:\n";
				printBuses(buses);
				break;
			case 2:
				writeToFile(buses, "Buses.txt");
				break;
			case 3:
				buses = addBus(buses);
				break;
			case 4:
				cout << "Введите порядковый номер автобуса, который хотите удалить: ";
				int num; 
				cin >> num;
				buses = deleteCar(buses, num - 1);
				break;
			case 5:
				cout << "Введите номер элемента, который вы хотите показать: ";
				int n;
				cin >> n;
				cout << "\n";
				if (buses.size() < n || n < 0) { cout << "В списке нет такого номера.\n"; break; }
				buses[n - 1].show();
				break;
			case 6:
				cout << setw(18) << "Водитель: |" << setw(7) << "  №A: |"
					<< setw(7) << "  №М: |" << setw(9) << " Марка: |"
					<< setw(7) << "Год: |" << setw(11) << " Пробег в км:\n";
				getBusesWithMilage(buses, 10000);
				break;
			case 7:
				cout << setw(18) << "Водитель: |" << setw(7) << "  №A: |"
					<< setw(7) << "  №М: |" << setw(9) << " Марка: |"
					<< setw(7) << "Год: |" << setw(11) << " Пробег в км:\n";
				getBusesOlderThen(buses, 10);
				break;
			case 8:
				cout << "Введите маршрут, по которому хотите отобрать автобусы: ";
				string r;
				cin >> r;
				cout << "\n";
				int j = 0;
				for (int i = 0; i < buses.size(); i++) {
					if (buses[i].getRoute() == r) j++;
				}
				if (j == 0) cout << "В списке нет такого маршрута.\n";
				else {
					cout << setw(18) << "Водитель: |" << setw(7) << "  №A: |"
						<< setw(7) << "  №М: |" << setw(9) << " Марка: |"
						<< setw(7) << "Год: |" << setw(11) << " Пробег в км:\n";
				}
				getBusesInRoute(buses, r);
				break;
			}
		}
	}
	catch (const char* exeption) {
		cout << exeption;
	}
}