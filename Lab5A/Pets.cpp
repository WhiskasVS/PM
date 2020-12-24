#include "Pets.h"

Pet::Pet() {
	cout << "��� ������� ��� ������� (�/� - �������, �/� - �������)? ";
	cin >> male;
	cin.ignore(3267, '\n');
	switch (male) {
	case '�':
	case '�':
		cout << "��� ��� �����? ";
		getline(cin, name);
		cout << "����� ��� �������? ";
		getline(cin, age);
		cout << "����� �� ������? ";
		getline(cin, breed);
		cout << "����� � ���� �����? ";
		getline(cin, color);
		break;
	case '�':
	case '�':
		cout << "��� � �����? ";
		getline(cin, name);
		cout << "����� � �������? ";
		getline(cin, age);
		cout << "����� ��� ������? ";
		getline(cin, breed);
		cout << "����� � �� �����? ";
		getline(cin, color);
		break;
	default:
		throw "\n�������� ������.\n";
		break;
	}
}

Cat::Cat() : Pet() {
	switch (GetMale()) {
	case '�':
	case '�':
		cout << "����� ���� ��� ����? ";
		getline(cin, eyes);
		cout << "����� � ���� ��������? ";
		getline(cin, character);
		break;
	case '�':
	case '�':
		cout << "����� ���� � ����? ";
		getline(cin, eyes);
		cout << "����� � �� ��������? ";
		getline(cin, character);
		break;
	default:
		break;
	}
}

void Cat::Show() {
	switch (GetMale()) {
	case '�':
	case '�':
		cout << "\n���";
		break;
	case '�':
	case '�':
		cout << "\n�����";
		break;
	default:
		break;
	}
	cout << "\n���: " << GetName();
	cout << "\n�������: " << GetAge();
	cout << "\n������: " << GetBreed();
	cout << "\n�����: " << GetColor();
	cout << "\n���� ����: " << GetEyes();
	cout << "\n��������: " << GetCharacter();
}

Dog::Dog() : Pet() {
	switch (GetMale()) {
	case '�':
	case '�':
		cout << "����� ���� ��� ����? ";
		getline(cin, eyes);
		cout << "�� ��������������? ";
		getline(cin, training);
		if (training != "��" && training != "��" && training != "���" && training != "���")
			throw "\n�������� ������.\n";
		cout << "����� � ���� ��������? ";
		getline(cin, character);
		break;
	case '�':
	case '�':
		cout << "����� ���� � ����? ";
		getline(cin, eyes);
		cout << "��� ��������������? ";
		getline(cin, training);
		if (training != "��" && training != "��" && training != "���" && training != "���")
			throw "\n�������� ������.\n";
		cout << "����� � �� ��������? ";
		getline(cin, character);
		break;
	default:
		break;
	}
}

void Dog::Show() {
	switch (GetMale()) {
	case '�':
	case '�':
		cout << "\nϸ�";
		break;
	case '�':
	case '�':
		cout << "\n������";
		break;
	default:
		break;
	}
	cout << "\n���: " << GetName();
	cout << "\n�������: " << GetAge();
	cout << "\n������: " << GetBreed();
	cout << "\n�����: " << GetColor();
	cout << "\n���� ����: " << GetEyes();
	cout << "\n��������: " << GetCharacter();
	if (training == "��" || training == "��") cout << "\n��������������";
	else cout << "\n����������������";
}

Parrot::Parrot() : Pet() {
	switch (GetMale()) {
	case '�':
	case '�':
		cout << "�� ������ ������? ";
		getline(cin, fly);
		if (fly != "��" && fly != "��" && fly != "���" && fly != "���")
			throw "\n�������� ������.\n";
		cout << "�� ����� �������������? ";
		getline(cin, speak);
		if (speak != "��" && speak != "��" && speak != "���" && speak != "���")
			throw "\n�������� ������.\n";
		cout << "����� � ���� ��������? ";
		getline(cin, character);
		break;
	case '�':
	case '�':
		cout << "��� ������ ������? ";
		getline(cin, fly);
		if (fly != "��" && fly != "��" && fly != "���" && fly != "���")
			throw "\n�������� ������.\n";
		cout << "��� ����� �������������? ";
		getline(cin, speak);
		if (speak != "��" && speak != "��" && speak != "���" && speak != "���")
			throw "\n�������� ������.\n";
		cout << "����� � �� ��������? ";
		getline(cin, character);
		break;
	default:
		break;
	}
}

void Parrot::Show() {
	cout << "\n�������\n";
	cout << "���: ";
	switch (GetMale()) {
	case '�':
	case '�':
		cout << "�������";
		break;
	case '�':
	case '�':
		cout << "�������";
		break;
	default:
		break;
	}
	cout << "\n���: " << GetName();
	cout << "\n�������: " << GetAge();
	cout << "\n������: " << GetBreed();
	cout << "\n�����: " << GetColor();
	cout << "\n��������: " << GetCharacter();
	if (fly == "��" || fly == "��") cout << "\n������ ������";
	else cout << "\n����� ������";
	if (speak == "��" || speak == "��") cout << "\n����� �������������";
	else cout << "\n�� ����� �������������";
}

Turtle::Turtle(string species) : Pet() {
	this->species = species;
	switch (GetMale()) {
	case '�':
	case '�':
		cout << "����� � ���� ��������? ";
		getline(cin, character);
		break;
	case '�':
	case '�':
		cout << "����� � �� ��������? ";
		getline(cin, character);
		break;
	default:
		break;
	}
}

void Turtle::Show() {
	if (species == "�������" || species == "�������") cout << "\n�������";
	if (species == "����������" || species == "����������") cout << "\n����������";
	else cout << "\n������������";
	cout << " ��������";
	cout << "\n���: ";
	switch (GetMale()) {
	case '�':
	case '�':
		cout << "�������";
		break;
	case '�':
	case '�':
		cout << "�������";
		break;
	default:
		break;
	}
	cout << "\n���: " << GetName();
	cout << "\n�������: " << GetAge();
	cout << "\n������: " << GetBreed();
	cout << "\n�����: " << GetColor();
	cout << "\n��������: " << GetCharacter();
}