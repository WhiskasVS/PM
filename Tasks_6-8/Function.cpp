#include "Function.h"

Ellips::Ellips() {
	cout << "������� ����������� �: ";
	cin >> this->a;
	if (this->a <= 0)
		throw "�������� ������. ����������� � ������ ���� ������ 0.\n";
	cout << "������� ����������� b: ";
	cin >> this->b;
	if (this->b <= 0)
		throw "�������� ������. ����������� b ������ ���� ������ 0.\n";
}

Ellips::Ellips(double a, double b) {
	if (a <= 0)
		throw "�������� ������. ����������� � ������ ���� ������ 0.\n";
	if (b <= 0)
		throw "�������� ������. ����������� b ������ ���� ������ 0.\n";
	this->a = a;
	this->b = b;
}

void Ellips::Value(double x) {
	this->x = x;
	this->y = (this->b / this->a) * sqrt(pow(this->a, 2) - pow(this->x, 2));
}

void Ellips::Result() {
	if (this->x > a)
		cout << "��� ����� �� ����������� �������.\n";
	else if (this->y == 0)
		cout << "�������� � � ����� " << this->x << " ����� " << this->y << ".\n";
	else
		cout << "�������� � � ����� " << this->x << " ����� " << this->y << " � -" << this->y << ".\n";
}

void Ellips::Input() {
	double buffer = 0.0;
	cout << "������� ����������� �: ";
	cin >> buffer;
	if (buffer <= 0)
		throw "�������� ������. ����������� � ������ ���� ������ 0.\n";
	this->a = buffer;
	cout << "������� ����������� b: ";
	cin >> buffer;
	if (buffer <= 0)
		throw "�������� ������. ����������� b ������ ���� ������ 0.\n";
	this->b = buffer;
}

void Ellips::Output() {
	cout << "��������� ������� ����� ���:\n";
	cout << "x^2/" << this->a << "^2 + y^2/" << b << "^2 = 1\n";
}

Hyperbola::Hyperbola() {
	cout << "������� ����������� �: ";
	cin >> this->a;
	if (this->a <= 0)
		throw "�������� ������. ����������� � ������ ���� ������ 0.\n";
	cout << "������� ����������� b: ";
	cin >> this->b;
	if (this->b <= 0)
		throw "�������� ������. ����������� b ������ ���� ������ 0.\n";
}

Hyperbola::Hyperbola(double a, double b) {
	if (a <= 0)
		throw "�������� ������. ����������� � ������ ���� ������ 0.\n";
	if (b <= 0)
		throw "�������� ������. ����������� b ������ ���� ������ 0.\n";
	this->a = a;
	this->b = b;
}

void Hyperbola::Value(double x) {
	this->x = x;
	this->y = (this->b / this->a) * sqrt(pow(this->x, 2) - pow(this->a, 2));
}

void Hyperbola::Result() {
	if (x < a)
		cout << "��� ����� �� ����������� ���������.\n";
	else if (this->y == 0)
		cout << "�������� � � ����� " << this->x << " ����� " << this->y << ".\n";
	else
		cout << "�������� � � ����� " << this->x << " ����� " << this->y << " � -" << this->y << ".\n";
}

void Hyperbola::Input() {
	double buffer = 0.0;
	cout << "������� ����������� �: ";
	cin >> buffer;
	if (buffer <= 0)
		throw "�������� ������. ����������� � ������ ���� ������ 0.\n";
	this->a = buffer;
	cout << "������� ����������� b: ";
	cin >> buffer;
	if (buffer <= 0)
		throw "�������� ������. ����������� b ������ ���� ������ 0.\n";
	this->b = buffer;
}

void Hyperbola::Output() {
	cout << "��������� ��������� ����� ���: \n";
	cout << "x^2/" << this->a << "^2 - y^2/" << b << "^2 = 1\n";
}