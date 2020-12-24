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

	void push_front(int data); //���������� �������� � ������ ������
	void push_back(int data); //���������� �������� � ����� ������
	void pop_front(); //�������� ������� �������� � ������
	void pop_back(); //�������� ���������� �������� � ������
	void insert(int data, int index); //���������� �������� � ������ �� ���������� �������
	void removeAt(int index); //�������� �������� � ������ �� ���������� �������
	int  getsize() { return size; } // �������� ���������� ��������� � ������
	void clear(); // �������� ������
	void show();

	int& operator[](const int index); // ������������� �������� [] 
	friend ostream& operator<<(ostream&, List&);
};