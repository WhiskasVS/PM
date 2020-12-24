#pragma once
#include <vector>
#include "Driver.h"

class Bus {
private:
	Driver driver;
	string busNum;
	string route;
	string mark;
	int year;
	double milage;
public:
	Bus();
	Bus(Driver, string, string, string, int, double);
	Bus(const Bus&);
	~Bus() {}

	Driver getDriver() const { return driver; }
	string getBusNum() const { return busNum; }
	string getRoute() const { return route; }
	string getMark() const { return mark; }
	int getYear() const { return year; }
	double getMilage() const { return milage; }

	void setDriver(Driver newDriver);
	void setBusNum(const string newBusNum);
	void setRoute(const string newRoute);
	void setMark(const string newMark);
	void setYear(int newYear);
	void setMilage(double newMilage);
	void show();

	Bus& operator=(const Bus&);
	friend istream& operator>>(istream&, Bus&);
	friend ostream& operator<<(ostream&, const Bus&);

	friend void my_swap(Bus&, Bus&);
	friend void printBuses(vector<Bus>);
	friend void getBusesWithMilage(vector<Bus>, double);
	friend void getBusesOlderThen(vector<Bus>, int);
	friend void getBusesInRoute(vector<Bus>, string);
};

void readFromFile(vector<Bus>&, string);
void writeToFile(vector<Bus>, string);

vector<Bus> addBus(vector<Bus>);
vector<Bus> deleteCar(vector<Bus>, int);
Bus registerBus();