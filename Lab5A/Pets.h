#pragma once
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class Pet {
protected:
	string age;
	string name;
	string breed;
	string color;
	string character;
	char male;
public:
	Pet();
	~Pet() {}

	string GetAge() { return this->age; }
	string GetName() { return this->name; }
	string GetBreed() { return this->breed; }
	string GetColor() { return this->color; }
	string GetCharacter() { return this->character; }
	char GetMale() { return this->male; }
	virtual void Show() = 0;
};

class Cat : public Pet {
private:
	string eyes;
public:
	Cat();
	~Cat() {}

	string GetEyes() { return this->eyes; }
	void Show() override;
};

class Dog : public Pet {
private:
	string eyes;
	string training;
public:
	Dog();
	~Dog() {}

	string GetEyes() { return this->eyes; }
	string GetTraining() { return this->training; }
	void Show() override;
};

class Parrot : public Pet {
private:
	string speak;
	string fly;
public:
	Parrot();
	~Parrot() {}

	string GetSpeak() { return this->speak; }
	string GetFly() { return this->fly; }
	void Show() override;
};

class Turtle : public Pet {
private:
	string species;
public:
	Turtle(string);
	~Turtle() {}

	string GetSpecies() { return this->species; }
	void Show() override;
};