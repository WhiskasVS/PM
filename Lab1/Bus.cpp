#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <fstream>
#include "Bus.h"
#include "Driver.h"

Bus::Bus() :
	driver(),
	busNum(),
	route(),
	mark(),
	year(2000),
	milage(0)
{}
Bus::Bus(Driver driver, string busNum, string route, 
	string mark, int year, double milage) :
	driver(driver),
	busNum(busNum),
	route(route),
	mark(mark),
	year(year),
	milage(milage)
{
	setYear(year);
	setBusNum(busNum);
	setRoute(route);
	setMark(mark);
	setMilage(milage);
}
Bus::Bus(const Bus& bus) :
	driver(bus.driver),
	busNum(bus.busNum),
	route(bus.route),
	mark(bus.mark),
	year(bus.year),
	milage(bus.milage)
{
	this->driver = driver;
	this->busNum = busNum;
	this->route = route;
	this->mark = mark;
	this->year = year;
	this->milage = milage;
}

void Bus::setDriver(Driver driver) {
	this->driver = driver;
}
void Bus::setBusNum(const string busNum) {
	if (busNum.length() != 4) 
		throw "������������ ���� ������. ����� �������� ������ �������� �� ������ ����.\n";
	for (int i = 0; i < busNum.length(); ++i)
		if (busNum[i] < '0' || busNum[i] > '9')
			throw "�������� ������. ����� �������� ����� �������� ������ �� ����.\n";
	this->busNum = busNum;
}
void Bus::setRoute(const string route) {
	if (route.length() > 3) 
		throw "�������� ������. ����� ������� �� ����� �������� �����, ��� �� ��� ����.\n";
	for (int i = 0; i < route.length(); ++i)
		if (route[i] < '0' || route[i] > '9')
			throw "�������� ������. ����� ������� ����� �������� ������ �� ����.\n";
	this->route = route;
}
void Bus::setMark(const string mark) {
	for (int i = 0; i < mark.length(); ++i) {
		if ((mark[i] >= 'A' && mark[i] <= 'Z') 
			|| (mark[i] >= '�' && mark[i] <= '�' || mark[i] == '�')) {}
		else throw "�������� ������. ����� �������� ����� ��������� ������ ��������� �����.\n";
 	}
	this->mark = mark;
}
void Bus::setYear(int year) {
	if (year < 0 || year > 2020) 
		throw "�������� ������. ��� ������ ������������ �� ����� ���� ������ 0 ��� ������ 2020.\n";
	this->year = year;
}
void Bus::setMilage(double milage) {
	if (milage < 0) throw "�������� ������. ������ �� ����� ���� ������ 0.\n";
	this->milage = milage;
}

void Bus::show() {
	cout << "��������: " << driver << "\n";
	cout << "����� ��������: " << busNum << "\n";
	cout << "�������: " << route << "\n";
	cout << "����� ��������: " << mark << "\n";
	cout << "��� ������ ������������: " << year << "\n";
	cout << "������: " << milage << "\n";
}

Bus& Bus::operator=(const Bus& rhs) {
	driver = rhs.driver;
	busNum = rhs.busNum;
	route = rhs.route;
	mark = rhs.mark;
	year = rhs.year;
	milage = rhs.milage;
	return *this;
}
istream& operator>>(istream& in, Bus& bus) {
	string tmp;
	int y;
	double mil;
	in >> tmp;
	bus.driver.setSureName(tmp);
	in >> tmp;
	bus.driver.setInitials(tmp);
	in >> tmp;
	bus.setBusNum(tmp);
	in >> tmp;
	bus.setRoute(tmp);
	in >> tmp;
	bus.setMark(tmp);
	in >> y;
	bus.setYear(y);
	in >> mil;
	bus.setMilage(mil);
	return in;
}
ostream& operator<<(ostream& out, const Bus& bus) {
	if (bus.busNum[0] == '\0') return out;
	out << bus.driver << bus.busNum << " "
		<< bus.route << " " << bus.mark << " "
		<< bus.year << " " << bus.milage << "\n";
	return out;
}

void my_swap(Bus& a, Bus& b) {
	using std::swap;
	my_swap(a.driver, b.driver);
	std::swap(a.busNum, b.busNum);
	std::swap(a.route, b.route);
	std::swap(a.mark, b.mark);
	std::swap(a.year, b.year);
	std::swap(a.milage, b.milage);
}
void printBuses(vector<Bus> arr) {
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i].busNum[0] == '\0') break;
		cout << setw(13) << arr[i].driver << " "
			<< setw(5) << arr[i].busNum << " "
			<< setw(5) << arr[i].route << " "
			<< setw(8) << arr[i].mark << " "
			<< setw(7) << arr[i].year << " "
			<< setw(13) << arr[i].milage << " \n";
	}
}
void getBusesWithMilage(vector<Bus> arr, double milage) {
	ofstream fileout("Results.txt", fstream::app);
	if (!fileout.is_open())
		throw "������ �������� �����.\n";
	fileout << "������ ���������, ������ ������� ����� 10000 ��:\n";
	for (int i = 0; i < arr.size(); ++i)
		if (arr[i].milage >= milage) {
			fileout << arr[i];
			cout << setw(13) << arr[i].driver << " "
				<< setw(5) << arr[i].busNum << " "
				<< setw(5) << arr[i].route << " "
				<< setw(8) << arr[i].mark << " "
				<< setw(7) << arr[i].year << " "
				<< setw(13) << arr[i].milage << " \n";
		}
	fileout << "\n";
	fileout.close();
}
void getBusesOlderThen(vector<Bus> arr, int age) {
	ofstream fileout("Results.txt", fstream::app);
	if (!fileout.is_open())
		throw "������ �������� �����.\n";
	fileout << "������ ���������, ������� ��������������� ������ 10 ���:\n";
	for (int i = 0; i < arr.size(); ++i)
		if (2020 - arr[i].year >= age) {
			fileout << arr[i];
			cout << setw(13) << arr[i].driver << " "
				<< setw(5) << arr[i].busNum << " "
				<< setw(5) << arr[i].route << " "
				<< setw(8) << arr[i].mark << " "
				<< setw(7) << arr[i].year << " "
				<< setw(13) << arr[i].milage << " \n";
		}
	fileout << "\n";
	fileout.close();
}
void getBusesInRoute(vector<Bus> arr, string route) {
	ofstream fileout("Results.txt", fstream::app);
	if (!fileout.is_open())
		throw "������ �������� �����.\n";
	fileout << "������ ���������, ������ �� �������� �" << route << ":\n";
	for (int i = 0; i < arr.size(); ++i)
		if (arr[i].route == route) {
			fileout << arr[i];
			cout << setw(13) << arr[i].driver << " "
				<< setw(5) << arr[i].busNum << " "
				<< setw(5) << arr[i].route << " "
				<< setw(8) << arr[i].mark << " "
				<< setw(7) << arr[i].year << " "
				<< setw(13) << arr[i].milage << " \n";
		}
	fileout << "\n";
	fileout.close();
}

void readFromFile(vector<Bus>& arr, string way) {
	Bus tmpBus;
	ifstream filein(way);
	if (filein.peek() == EOF) throw "\n���� ����.\n";
	if (!filein.is_open())
		throw "������ �������� �����.\n";
	for (int i = 0; i < arr.size(); i++) {
		if (filein.eof()) break;
		filein >> tmpBus;
		arr[i] = tmpBus;
	}
	filein.close();
}
void writeToFile(vector<Bus> arr, string way) {
	ofstream fileout(way);
	if (!fileout.is_open())
		throw "������ �������� �����.\n";
	for (int i = 0; i < arr.size(); i++)
		fileout << arr[i];
	cout << "������ � ���� ������ �������.\n";
	fileout.close();
}
vector<Bus> addBus(vector<Bus> arr) {
	vector<Bus> tmp(arr.size() + 1);
	for (int i = 0; i < arr.size(); ++i) tmp[i] = arr[i];
	tmp[arr.size()] = registerBus();
	cout << "������� �������� �������.\n";
	return tmp;
}
vector<Bus> deleteCar(vector<Bus> arr, int num) {
	if (num >= arr.size() || num < 0) {
		cout << "��� �������� � ����� ���������� �������.\n";
		return arr;
	}
	my_swap(arr[num], arr[arr.size() - 1]);
	vector<Bus> tmp(arr.size() - 1);
	for (int i = 0; i < arr.size() - 1; ++i) tmp[i] = arr[i];
	cout << "\n������� �����.\n";
	return tmp;
}
Bus registerBus() {
	Bus bus;
	Driver driver;
	string s;
	int n;
	double d;
	cout << "�������:\n";
	cout << "������� ��������: ";
	cin >> s; driver.setSureName(s);
	cout << "�������� ��������: ";
	cin >> s; driver.setInitials(s);
	bus.setDriver(driver);
	cout << "����� ��������: ";
	cin >> s; bus.setBusNum(s);
	cout << "����� ��������: ";
	cin >> s; bus.setRoute(s);
	cout << "����� ��������: ";
	cin >> s; bus.setMark(s);
	cout << "��� ������ ������������: ";
	cin >> n; bus.setYear(n);
	cout << "������: ";
	cin >> d; bus.setMilage(d);
	/*cout << "������� � �������� ��������, ����� ��������, 
	����� ��������, ����� ��������, ��� ������ ������������ � ������.\n";
	cin >> bus;*/
	return bus;
}