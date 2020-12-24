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
		cout << "����� ����������!\n";
		while (true) {
			cout << "\n�������� ��, ��� �� ������ �������:\n";
			cout << "1. ������� ������ ��������� �� �����.\n";
			cout << "2. �������� ������ ��������� � ����.\n";
			cout << "3. �������� ��� ���� ������� � ������.\n";
			cout << "4. ������� ������� �� ������.\n";
			cout << "5. �������� ������� �� ������.\n";
			cout << "6. ������� ������ ���������, ������ ������� ����� 10000 ��.\n";
			cout << "7. ������� ������ ���������, ������� ��������������� ������ 10 ���.\n";
			cout << "8. ������� ������ ���������, ������ �� ��������� ��������.\n";
			cout << "0. ����� �� ���������.\n";
			cout << "����� ��������: ";
			int choice;
			cin >> choice;
			cout << "\n";
			switch (choice) {
			case 0: return 0;
			case 1:
				readFromFile(buses, "Buses.txt");
				cout << setw(18) << "��������: |" << setw(7) << "  �A: |"
					<< setw(7) << "  ��: |" << setw(9) << " �����: |"
					<< setw(7) << "���: |" << setw(11) << " ������ � ��:\n";
				printBuses(buses);
				break;
			case 2:
				writeToFile(buses, "Buses.txt");
				break;
			case 3:
				buses = addBus(buses);
				break;
			case 4:
				cout << "������� ���������� ����� ��������, ������� ������ �������: ";
				int num; 
				cin >> num;
				buses = deleteCar(buses, num - 1);
				break;
			case 5:
				cout << "������� ����� ��������, ������� �� ������ ��������: ";
				int n;
				cin >> n;
				cout << "\n";
				if (buses.size() < n || n < 0) { cout << "� ������ ��� ������ ������.\n"; break; }
				buses[n - 1].show();
				break;
			case 6:
				cout << setw(18) << "��������: |" << setw(7) << "  �A: |"
					<< setw(7) << "  ��: |" << setw(9) << " �����: |"
					<< setw(7) << "���: |" << setw(11) << " ������ � ��:\n";
				getBusesWithMilage(buses, 10000);
				break;
			case 7:
				cout << setw(18) << "��������: |" << setw(7) << "  �A: |"
					<< setw(7) << "  ��: |" << setw(9) << " �����: |"
					<< setw(7) << "���: |" << setw(11) << " ������ � ��:\n";
				getBusesOlderThen(buses, 10);
				break;
			case 8:
				cout << "������� �������, �� �������� ������ �������� ��������: ";
				string r;
				cin >> r;
				cout << "\n";
				int j = 0;
				for (int i = 0; i < buses.size(); i++) {
					if (buses[i].getRoute() == r) j++;
				}
				if (j == 0) cout << "� ������ ��� ������ ��������.\n";
				else {
					cout << setw(18) << "��������: |" << setw(7) << "  �A: |"
						<< setw(7) << "  ��: |" << setw(9) << " �����: |"
						<< setw(7) << "���: |" << setw(11) << " ������ � ��:\n";
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