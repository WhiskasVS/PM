#pragma once
#include <iostream>
using namespace std;

class List {
private:
	class Node {
	public:
		Node *pNext;
		int data;
		Node(int data = 0, Node *pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size;
	Node *head;
public:
	List();
	List(int size);
	~List();

	void push_front(int data); //добавление элемента в начало списка
	void push_back(int data); //добавление элемента в конец списка
	void pop_front(); //удаление первого элемента в списке
	void pop_back(); //удаление последнего элемента в списке
	void insert(int data, int index); //добавление элемента в список по указанному индексу
	void removeAt(int index); //удаление элемента в списке по указанному индексу
	int  getsize() { return size; } // получить количество елементов в списке
	void clear(); // очистить список
	void show();

	int& operator[](const int index); // перегруженный оператор [] 
	friend ostream& operator<<(ostream&, List&);
};