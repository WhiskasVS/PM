#include "Pets.h"

Pet::Pet() {
	cout << "Это мальчик или девочка (М/м - мальчик, Д/д - девочка)? ";
	cin >> male;
	cin.ignore(3267, '\n');
	switch (male) {
	case 'М':
	case 'м':
		cout << "Как его зовут? ";
		getline(cin, name);
		cout << "Каков его возраст? ";
		getline(cin, age);
		cout << "Какой он породы? ";
		getline(cin, breed);
		cout << "Какой у него окрас? ";
		getline(cin, color);
		break;
	case 'Д':
	case 'д':
		cout << "Как её зовут? ";
		getline(cin, name);
		cout << "Каков её возраст? ";
		getline(cin, age);
		cout << "Какой она породы? ";
		getline(cin, breed);
		cout << "Какой у неё окрас? ";
		getline(cin, color);
		break;
	default:
		throw "\nНеверные данные.\n";
		break;
	}
}

Cat::Cat() : Pet() {
	switch (GetMale()) {
	case 'М':
	case 'м':
		cout << "Каков цвет его глаз? ";
		getline(cin, eyes);
		cout << "Какой у него характер? ";
		getline(cin, character);
		break;
	case 'Д':
	case 'д':
		cout << "Каков цвет её глаз? ";
		getline(cin, eyes);
		cout << "Какой у неё характер? ";
		getline(cin, character);
		break;
	default:
		break;
	}
}

void Cat::Show() {
	switch (GetMale()) {
	case 'М':
	case 'м':
		cout << "\nКот";
		break;
	case 'Д':
	case 'д':
		cout << "\nКошка";
		break;
	default:
		break;
	}
	cout << "\nИмя: " << GetName();
	cout << "\nВозраст: " << GetAge();
	cout << "\nПорода: " << GetBreed();
	cout << "\nОкрас: " << GetColor();
	cout << "\nЦвет глаз: " << GetEyes();
	cout << "\nХарактер: " << GetCharacter();
}

Dog::Dog() : Pet() {
	switch (GetMale()) {
	case 'М':
	case 'м':
		cout << "Каков цвет его глаз? ";
		getline(cin, eyes);
		cout << "Он дрессированный? ";
		getline(cin, training);
		if (training != "Да" && training != "да" && training != "Нет" && training != "нет")
			throw "\nНеверные данные.\n";
		cout << "Какой у него характер? ";
		getline(cin, character);
		break;
	case 'Д':
	case 'д':
		cout << "Каков цвет её глаз? ";
		getline(cin, eyes);
		cout << "Она дрессированная? ";
		getline(cin, training);
		if (training != "Да" && training != "да" && training != "Нет" && training != "нет")
			throw "\nНеверные данные.\n";
		cout << "Какой у неё характер? ";
		getline(cin, character);
		break;
	default:
		break;
	}
}

void Dog::Show() {
	switch (GetMale()) {
	case 'М':
	case 'м':
		cout << "\nПёс";
		break;
	case 'Д':
	case 'д':
		cout << "\nСобака";
		break;
	default:
		break;
	}
	cout << "\nИмя: " << GetName();
	cout << "\nВозраст: " << GetAge();
	cout << "\nПорода: " << GetBreed();
	cout << "\nОкрас: " << GetColor();
	cout << "\nЦвет глаз: " << GetEyes();
	cout << "\nХарактер: " << GetCharacter();
	if (training == "Да" || training == "да") cout << "\nДрессированная";
	else cout << "\nНедрессированная";
}

Parrot::Parrot() : Pet() {
	switch (GetMale()) {
	case 'М':
	case 'м':
		cout << "Он хорошо летает? ";
		getline(cin, fly);
		if (fly != "Да" && fly != "да" && fly != "Нет" && fly != "нет")
			throw "\nНеверные данные.\n";
		cout << "Он умеет разговаривать? ";
		getline(cin, speak);
		if (speak != "Да" && speak != "да" && speak != "Нет" && speak != "нет")
			throw "\nНеверные данные.\n";
		cout << "Какой у него характер? ";
		getline(cin, character);
		break;
	case 'Д':
	case 'д':
		cout << "Она хорошо летает? ";
		getline(cin, fly);
		if (fly != "Да" && fly != "да" && fly != "Нет" && fly != "нет")
			throw "\nНеверные данные.\n";
		cout << "Она умеет разговаривать? ";
		getline(cin, speak);
		if (speak != "Да" && speak != "да" && speak != "Нет" && speak != "нет")
			throw "\nНеверные данные.\n";
		cout << "Какой у неё характер? ";
		getline(cin, character);
		break;
	default:
		break;
	}
}

void Parrot::Show() {
	cout << "\nПопугай\n";
	cout << "Пол: ";
	switch (GetMale()) {
	case 'М':
	case 'м':
		cout << "мужской";
		break;
	case 'Д':
	case 'д':
		cout << "женский";
		break;
	default:
		break;
	}
	cout << "\nИмя: " << GetName();
	cout << "\nВозраст: " << GetAge();
	cout << "\nПорода: " << GetBreed();
	cout << "\nОкрас: " << GetColor();
	cout << "\nХарактер: " << GetCharacter();
	if (fly == "Да" || fly == "да") cout << "\nХорошо летает";
	else cout << "\nПлохо летает";
	if (speak == "Да" || speak == "да") cout << "\nУмеет разговаривать";
	else cout << "\nНе умеет разговаривать";
}

Turtle::Turtle(string species) : Pet() {
	this->species = species;
	switch (GetMale()) {
	case 'М':
	case 'м':
		cout << "Какой у него характер? ";
		getline(cin, character);
		break;
	case 'Д':
	case 'д':
		cout << "Какой у неё характер? ";
		getline(cin, character);
		break;
	default:
		break;
	}
}

void Turtle::Show() {
	if (species == "Морская" || species == "морская") cout << "\nМорская";
	if (species == "Сухопутная" || species == "сухопутная") cout << "\nСухопутная";
	else cout << "\nПресноводная";
	cout << " черепаха";
	cout << "\nПол: ";
	switch (GetMale()) {
	case 'М':
	case 'м':
		cout << "мужской";
		break;
	case 'Д':
	case 'д':
		cout << "женский";
		break;
	default:
		break;
	}
	cout << "\nИмя: " << GetName();
	cout << "\nВозраст: " << GetAge();
	cout << "\nПорода: " << GetBreed();
	cout << "\nОкрас: " << GetColor();
	cout << "\nХарактер: " << GetCharacter();
}