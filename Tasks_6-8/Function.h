#pragma once
#include <iostream>
//#include <cmath>
#include <Windows.h>
#include <vector>
#include <string>
using namespace std;

class Function {
protected:
	double x;
	double y;
public:
	Function() { this->x = 0; this->y = 0; }
	~Function() {}

	virtual void Value(double) = 0;
	virtual void Result() = 0;
	virtual void Input() = 0;
	virtual void Output() = 0;
};

class Ellips : public Function {
private:
	double a;
	double b;
public:
	Ellips();
	Ellips(double, double);
	~Ellips() {}

	void Value(double) override;
	void Result() override;
	void Input() override;
	void Output() override;
};

class Hyperbola : public Function {
private:
	double a;
	double b;
public:
	Hyperbola();
	Hyperbola(double, double);
	~Hyperbola() {}

	void Value(double) override;
	void Result() override;
	void Input() override;
	void Output() override;
};