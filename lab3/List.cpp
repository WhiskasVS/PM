#include "List.h"

List::List() {
	size = 0;
	head = nullptr;
}
List::List(int size) {
	this->head = nullptr;
	int n = 0;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << " элемент: ";
		cin >> n;
		insert(n, i);
	}
}
List::~List() {
	clear();
}

void List::push_front(int data) {
	head = new Node(data, head);
	size++;
}
void List::push_back(int data) {
	if (head == nullptr) {
		head = new Node(data);
	}
	else {
		Node *current = this->head;
		while (current->pNext != nullptr) current = current->pNext;
		current->pNext = new Node(data);
	}
	size++;
}
void List::pop_front() {
	Node *temp = head;
	head = head->pNext;
	delete temp;
	size--;
}
void List::pop_back() {
	removeAt(size - 1);
}
void List::insert(int data, int index) {
	if (index == 0) push_front(data);
	else if (index > size) {
		cout << "Размер списка: " << size << ".\n";
		cout << "Номер элемента не может превышать " << size + 1 << ".\n";
	}
	else if (index < 0) cout << "В списке не может быть элемента с таким номером.\n";
	else {
		Node *previous = this->head;
		for (int i = 0; i < index - 1; i++) previous = previous->pNext;
		previous->pNext = new Node(data, previous->pNext);
		size++;
	}
}
void List::removeAt(int index) {
	if (index == 0) pop_front();
	else if (index > size) {
		cout << "Размер списка: " << size << ".\n";
		cout << "Номер элемента не может превышать " << size + 1 << ".\n";
	}
	else if (index < 0) cout << "В списке не может быть элемента с таким номером.\n";
	else {
		Node *previous = this->head;
		for (int i = 0; i < index - 1; i++) previous = previous->pNext;
		Node *toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		size--;
	}
}
void List::clear() {
	while (size) pop_front();
}
void List::show() {
	for (int i = 0; i < this->getsize(); i++) cout << " " << operator[](i);
}

int& List::operator[](const int index) {
	int counter = 0;
	Node *current = this->head;
	while (current != nullptr) {
		if (counter == index) return current->data;
		current = current->pNext;
		counter++;
	}
}

ostream& operator<<(ostream& os, List& list) {
	for (int i = 0; i < list.size; i++) {
		os << list.operator[](i) << " ";
	}
	os << "\n";
	return os;
}