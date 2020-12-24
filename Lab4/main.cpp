#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

template<typename T>
class List {
private:
	template<typename T>
	class Node {
	public:
		Node * pNext;
		T data;
		Node(T data = T(), Node *pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size;
	Node<T> *head;
public:
	List();
	List(int size);
	~List();

	void push_front(T data); //добавление элемента в начало списка
	void push_back(T data); //добавление элемента в конец списка
	void pop_front(); //удаление первого элемента в списке
	void pop_back(); //удаление последнего элемента в списке
	void insert(T data, int index); //добавление элемента в список по указанному индексу
	void removeAt(int index); //удаление элемента в списке по указанному индексу
	int  getsize() { return size; } // получить количество елементов в списке
	void clear(); // очистить список
	void show();

	T& operator[](const int index); // перегруженный оператор [] 
};

template<typename T>
List<T>::List() {
	size = 0;
	head = nullptr;
}

template<typename T>
List<T>::List(int size) {
	this->head = nullptr;
	T n;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << " элемент: ";
		cin >> n;
		insert(n, i);
	}
}

template<typename T>
List<T>::~List() {
	clear();
}

template<typename T>
void List<T>::push_front(T data) {
	head = new Node<T>(data, head);
	size++;
}

template<typename T>
void List<T>::push_back(T data) {
	if (head == nullptr) head = new Node<T>(data);
	else {
		Node<T> *current = this->head;
		while (current->pNext != nullptr) current = current->pNext;
		current->pNext = new Node<T>(data);
	}
	size++;
}

template<typename T>
void List<T>::pop_front() {
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	size--;
}

template<typename T>
void List<T>::pop_back() {
	removeAt(size - 1);
}

template<typename T>
void List<T>::insert(T data, int index) {
	if (index == 0) push_front(data);
	else if (index > size) {
		cout << "Размер списка: " << size << ".\n";
		cout << "Номер элемента не может превышать " << size + 1 << ".\n";
	}
	else if (index < 0) cout << "В списке не может быть элемента с таким номером.\n";
	else {
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++) previous = previous->pNext;
		Node<T> *newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;
		size++;
	}
}

template<typename T>
void List<T>::removeAt(int index) {
	if (index == 0) pop_front();
	else if (index > size) {
		cout << "Размер списка: " << size << ".\n";
		cout << "Номер элемента не может превышать " << size + 1 << ".\n";
	}
	else if (index < 0) cout << "В списке не может быть элемента с таким номером.\n";
	else {
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++) previous = previous->pNext;
		Node<T> *toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		size--;
	}
}

template<typename T>
void List<T>::clear() {
	while (size) pop_front();
}

template<typename T>
void List<T>::show() {
	for (int i = 0; i < this->getsize(); i++) cout << " " << operator[](i);
}

template<typename T>
T& List<T>::operator[](const int index) {
	int counter = 0;
	Node<T> *current = this->head;
	while (current != nullptr) {
		if (counter == index) return current->data;
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void belong(List<T>& lhs, List<T>& rhs);
void ListForInt();
void ListForFloat();
void ListForDouble();
void ListForChar();

int main() {
	setlocale(LC_CTYPE, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Добро пожаловать!\n";
	while (true) {
		cout << "\nВыберите тип данных:\n";
		cout << "1. Integer\n";
		cout << "2. Float\n";
		cout << "3. Double\n";
		cout << "4. Char\n";
		cout << "Тип под номером ";
		int type;
		cin >> type;
		switch (type) {
		case 1:
			ListForInt();
			break;
		case 2:
			ListForFloat();
			break;
		case 3:
			ListForDouble();
			break;
		case 4:
			ListForChar();
			break;
		default:
			cout << "\nНеверный тип данных.\n";
		}
		cout << "\nХотите продолжить?\n";
		cout << "1. Да.\n";
		cout << "2. Нет.\n";
		int choise;
		while (true) {
			cout << "Ваш выбор: ";
			cin >> choise;
			if (choise == 1 || choise == 2) break;
			else cout << "\nВы можете ввести только 1 или 2.\n\n";
		}
		if (choise == 2) return 0;
	}
}

template<typename T>
void belong(List<T>& lhs, List<T>& rhs) {
	if (lhs.getsize() > rhs.getsize())
		cout << "\nКоличество элементов первого списка превышает количество элементов второго списка.";
	else if (lhs.getsize() == rhs.getsize()) {
		for (int i = 0; i < lhs.getsize(); i++) {
			if (rhs[i] != lhs[i]) {
				cout << "\nЭлементы первого списка не содержатся во втором списке.";
				break;
			}
			if (rhs[i] == lhs[i] && i == rhs.getsize() - 1)
				cout << "\nЭлементы первого списка содержатся во втором списке.";
		}
	}
	else {
		for (int i = 0; i < rhs.getsize(); i++) {
			if (rhs[i] == lhs[0]) {
				for (int j = 0, k = i; j < lhs.getsize(); j++, k++) {
					//if (rhs[k] != lhs[j]) break;
					if (rhs[k] == lhs[j] && j == lhs.getsize() - 1) {
						cout << "\nЭлементы первого списка содержатся во втором списке.";
						return;
					}
				}
			}
		}
		cout << "\nЭлементы первого списка не содержатся во втором списке.";
	}
}

void ListForInt() {
	int n, m;
	cout << "\nВведите количество элементов: ";
	cin >> n;
	List<int> list1(n);
	cout << "Первый список:";
	list1.show();
	cout << "\n";
	cout << "\nВведите количество элементов: ";
	cin >> m;
	List<int> list2(m);
	cout << "Второй список:";
	list2.show();
	while (true) {
		cout << "\n\nВыберите то, что вы хотите сделать:\n";
		cout << "1. Добавить элемент в список на указанный номер.\n";
		cout << "2. Удалить элемент из списка по указанному номеру.\n";
		cout << "3. Проверить, содержатся ли элементы первого списка во втором.\n";
		cout << "0. Выход из программы.\n";
		cout << "Номер операции: ";
		int choice, num1, num2, ind1, ind2, element;
		cin >> choice;
		switch (choice) {
		case 0: return;
		case 1:
			cout << "\nВыберите список: ";
			cin >> num1;
			if (num1 > 2 || num1 <= 0) cout << "Нет списка с таким номером.";
			else {
				cout << "Элемент: ";
				cin >> element;
				cout << "Номер элемента: ";
				cin >> ind1;
				switch (num1) {
				case 1:
					list1.insert(element, ind1 - 1);
					cout << "Первый список:";
					list1.show();
					break;
				case 2:
					list2.insert(element, ind1 - 1);
					cout << "Второй список:";
					list2.show();
					break;
				}
			}
			break;
		case 2:
			cout << "\nВыберите список: ";
			cin >> num2;
			if (num2 > 2 || num2 <= 0) cout << "Нет списка с таким номером.";
			else {
				cout << "Номер элемента: ";
				cin >> ind2;
				switch (num2) {
				case 1:
					list1.removeAt(ind2 - 1);
					cout << "Первый список:";
					list1.show();
					break;
				case 2:
					list2.removeAt(ind2 - 1);
					cout << "Второй список:";
					list2.show();
					break;
				default:
					cout << "Нет списка с таким номером.";
					break;
				}
			}
			break;
		case 3:
			belong(list1, list2);
			break;
		default:
			cout << "Неправильная операция.\n";
			break;
		}
	}
}

void ListForFloat() {
	int n, m;
	cout << "\nВведите количество элементов: ";
	cin >> n;
	List<float> list1(n);
	cout << "Первый список:";
	list1.show();
	cout << "\n";
	cout << "\nВведите количество элементов: ";
	cin >> m;
	List<float> list2(m);
	cout << "Второй список:";
	list2.show();
	while (true) {
		cout << "\n\nВыберите то, что вы хотите сделать:\n";
		cout << "1. Добавить элемент в список на указанный номер.\n";
		cout << "2. Удалить элемент из списка по указанному номеру.\n";
		cout << "3. Проверить, содержатся ли элементы первого списка во втором.\n";
		cout << "0. Выход из программы.\n";
		cout << "Номер операции: ";
		int choice, num1, num2, ind1, ind2;
		float element;
		cin >> choice;
		switch (choice) {
		case 0: return;
		case 1:
			cout << "\nВыберите список: ";
			cin >> num1;
			if (num1 > 2 || num1 <= 0) cout << "Нет списка с таким номером.";
			else {
				cout << "Элемент: ";
				cin >> element;
				cout << "Номер элемента: ";
				cin >> ind1;
				switch (num1) {
				case 1:
					list1.insert(element, ind1 - 1);
					cout << "Первый список:";
					list1.show();
					break;
				case 2:
					list2.insert(element, ind1 - 1);
					cout << "Второй список:";
					list2.show();
					break;
				}
			}
			break;
		case 2:
			cout << "\nВыберите список: ";
			cin >> num2;
			if (num2 > 2 || num2 <= 0) cout << "Нет списка с таким номером.";
			else {
				cout << "Номер элемента: ";
				cin >> ind2;
				switch (num2) {
				case 1:
					list1.removeAt(ind2 - 1);
					cout << "Первый список:";
					list1.show();
					break;
				case 2:
					list2.removeAt(ind2 - 1);
					cout << "Второй список:";
					list2.show();
					break;
				default:
					cout << "Нет списка с таким номером.";
					break;
				}
			}
			break;
		case 3:
			belong(list1, list2);
			break;
		default:
			cout << "Неправильная операция.\n";
			break;
		}
	}
}

void ListForDouble() {
	int n, m;
	cout << "\nВведите количество элементов: ";
	cin >> n;
	List<double> list1(n);
	cout << "Первый список:";
	list1.show();
	cout << "\n";
	cout << "\nВведите количество элементов: ";
	cin >> m;
	List<double> list2(m);
	cout << "Второй список:";
	list2.show();
	while (true) {
		cout << "\n\nВыберите то, что вы хотите сделать:\n";
		cout << "1. Добавить элемент в список на указанный номер.\n";
		cout << "2. Удалить элемент из списка по указанному номеру.\n";
		cout << "3. Проверить, содержатся ли элементы первого списка во втором.\n";
		cout << "0. Выход из программы.\n";
		cout << "Номер операции: ";
		int choice, num1, num2, ind1, ind2;
		double element;
		cin >> choice;
		switch (choice) {
		case 0: return;
		case 1:
			cout << "\nВыберите список: ";
			cin >> num1;
			if (num1 > 2 || num1 <= 0) cout << "Нет списка с таким номером.";
			else {
				cout << "Элемент: ";
				cin >> element;
				cout << "Номер элемента: ";
				cin >> ind1;
				switch (num1) {
				case 1:
					list1.insert(element, ind1 - 1);
					cout << "Первый список:";
					list1.show();
					break;
				case 2:
					list2.insert(element, ind1 - 1);
					cout << "Второй список:";
					list2.show();
					break;
				}
			}
			break;
		case 2:
			cout << "\nВыберите список: ";
			cin >> num2;
			if (num2 > 2 || num2 <= 0) cout << "Нет списка с таким номером.";
			else {
				cout << "Номер элемента: ";
				cin >> ind2;
				switch (num2) {
				case 1:
					list1.removeAt(ind2 - 1);
					cout << "Первый список:";
					list1.show();
					break;
				case 2:
					list2.removeAt(ind2 - 1);
					cout << "Второй список:";
					list2.show();
					break;
				default:
					cout << "Нет списка с таким номером.";
					break;
				}
			}
			break;
		case 3:
			belong(list1, list2);
			break;
		default:
			cout << "Неправильная операция.\n";
			break;
		}
	}
}

void ListForChar() {
	int n, m;
	cout << "\nВведите количество элементов: ";
	cin >> n;
	List<char> list1(n);
	cout << "Первый список:";
	list1.show();
	cout << "\n";
	cout << "\nВведите количество элементов: ";
	cin >> m;
	List<char> list2(m);
	cout << "Второй список:";
	list2.show();
	while (true) {
		cout << "\n\nВыберите то, что вы хотите сделать:\n";
		cout << "1. Добавить элемент в список на указанный номер.\n";
		cout << "2. Удалить элемент из списка по указанному номеру.\n";
		cout << "3. Проверить, содержатся ли элементы первого списка во втором.\n";
		cout << "0. Выход из программы.\n";
		cout << "Номер операции: ";
		int choice, num1, num2, ind1, ind2;
		char element;
		cin >> choice;
		switch (choice) {
		case 0: return;
		case 1:
			cout << "\nВыберите список: ";
			cin >> num1;
			if (num1 > 2 || num1 <= 0) cout << "Нет списка с таким номером.";
			else {
				cout << "Элемент: ";
				cin >> element;
				cout << "Номер элемента: ";
				cin >> ind1;
				switch (num1) {
				case 1:
					list1.insert(element, ind1 - 1);
					cout << "Первый список:";
					list1.show();
					break;
				case 2:
					list2.insert(element, ind1 - 1);
					cout << "Второй список:";
					list2.show();
					break;
				}
			}
			break;
		case 2:
			cout << "\nВыберите список: ";
			cin >> num2;
			if (num2 > 2 || num2 <= 0) cout << "Нет списка с таким номером.";
			else {
				cout << "Номер элемента: ";
				cin >> ind2;
				switch (num2) {
				case 1:
					list1.removeAt(ind2 - 1);
					cout << "Первый список:";
					list1.show();
					break;
				case 2:
					list2.removeAt(ind2 - 1);
					cout << "Второй список:";
					list2.show();
					break;
				default:
					cout << "Нет списка с таким номером.";
					break;
				}
			}
			break;
		case 3:
			belong(list1, list2);
			break;
		default:
			cout << "Неправильная операция.\n";
			break;
		}
	}
}