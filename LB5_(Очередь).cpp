
#include <iomanip>
#include <iostream>
#include<Windows.h>
#include <conio.h>
#include <string>
using namespace std;

template <class T>
struct QueueNode
{
	T value;
	QueueNode* next = nullptr;
};


template <class T>
class Queue
{
private:
	QueueNode<T>* head;
	int size;
public:
	Queue()
	{
		size = 0;
		head = nullptr;
	}

	~Queue()
	{
		deleteQueue();
	}

	void popFront();

	void pushFront(const T value);

	void deleteQueue();
	void showQueue();
	void findByValue(const T value);

	int getSize();

	bool operator == (const Queue& other);
	friend ostream& operator << (ostream&, Queue&);
};

template <class T>
class Interface
{
private:
	T obj;
public:
	void menu();
	void functions();
};
int main()
{
	setlocale(LC_ALL, "rus");
	Interface<int> interface;

	interface.menu();

	system("pause");
}
template <class T>
void Interface<T>::menu()
{
	int selection;

	do
	{
		system("cls");
		cout << "1. Работа с int односвязным списком" << endl;
		cout << "2. Работа с double односвязным списком" << endl;
		cout << "3. Работа с char односвязным списком" << endl;
		cout << "Другое - выход" << endl;

		cin >> selection;

		switch (selection)
		{
		case 1:
		{
			Interface<int> object;
			object.functions();
			break;
		}
		case 2:
		{
			Interface<double> object;
			object.functions();
			break;
		}
		case 3:
		{
			Interface<char> object;
			object.functions();
			break;
		}
		default:
			return;
		}

	} while (true);
}

template <class T>
void Interface<T>::functions()
{
	Queue<T> queue;
	int selection;

	do
	{
		system("cls");
		cout << "1. Добавить элемент" << endl;
		cout << "2. Удалить элемент" << endl;
		cout << "3. Удалить очередь" << endl;
		cout << "4. Вывести очередь на экран" << endl;
		cout << "5. Найти элемент очереди по значению" << endl;
		cout << "Другое - выход" << endl;

		selection = writeNumbers();
		system("cls");

		switch (selection)
		{
		case 1:
		{
			T value;
			cout << "Введите элемент: ";
			cin >> value;
			queue.pushFront(value);

			cout << "Элемент успешно добавлен!" << endl;
			system("pause");
			break;
		}
		case 2:
		{
			queue.popFront();
			cout << "Элемент успешно удалён!" << endl;

			system("pause");
			break;
		}
		case 3:
		{
			queue.deleteQueue();
			cout << "Односвязный список успешно удалена!" << endl;

			system("pause");
			break;
		}
		case 4:
		{
			cout << "Элементы односвязного списка: " << endl;
			queue.showQueue();

			system("pause");
			break;
		}
		case 5:
		{
			T value;

			cout << "Введите искомое значение: ";
			cin >> value;
			queue.findByValue(value);

			system("pause");
			break;
		}
		default:
			return;
		}

	} while (true);
}
template <class T>
void Queue<T>::pushFront(const T value)
{
	if (this->head == nullptr)
	{
		this->head = new QueueNode<T>;
		this->head->value = value;
	}
	else
	{
		QueueNode<T>* temp = new QueueNode<T>;
		temp->value = value;

		temp->next = this->head;
		this->head = temp;
	}

	size++;
}

template <class T>
void Queue<T>::popFront()
{
	if (this->head == nullptr)
	{
		return;
	}
	else if (this->head->next == nullptr)
	{
		delete this->head;
		this->head = nullptr;
	}
	else
	{
		QueueNode<T>* temp = this->head;
		this->head = this->head->next;
		delete temp;
	}

	size--;
}

template <class T>
void Queue<T>::showQueue()
{
	if (this->head == nullptr)
	{
		cout << "Односвязный список пуст!" << endl;
		return;
	}

	QueueNode<T>* current = this->head;

	while (current != nullptr)
	{
		cout << current->value << setw(3);
		current = current->next;
	}
	cout << endl;
}

template <class T>
void Queue<T>::deleteQueue()
{
	if (this->head == nullptr)
	{
		return;
	}

	QueueNode<T>* current = this->head;

	while (this->head != nullptr)
	{
		popFront();
	}

	this->head = nullptr;
}

template <class T>
void Queue<T>::findByValue(const T value)
{
	if (this->head == nullptr)
	{
		cout << "Односвязный список пуст!" << endl;
		return;
	}
	else
	{
		QueueNode<T>* current = this->head;
		int counter = 0;

		while (current != nullptr)
		{
			if (current->value == value)
			{
				cout << "Элемент " << value << " содержится в односвязном списке на " << counter + 1 << " месте" << endl;
				return;
			}

			current = current->next;
			counter++;
		}

		cout << "Данного элемента в односвязном списке нет!" << endl;
	}
}

template <class T>
bool Queue<T>::operator == (const Queue<T>& other)
{
	if (this->getSize() == other.getSize())
		return true;
	else
		return false;
}

template <class T>
ostream& operator << (ostream& out, Queue<T>& obj)
{
	out << obj.showQueue();
	return out;
}

template <class T>
int Queue<T>::getSize()
{
	return this->size;
}
string writeWord()
{
	string slovo;
	while (true) {
		int Knopka;
		char sumbol;
		Knopka = _getch();
		if (Knopka == 224) {
			Knopka = _getch();
		}
		else
			if (Knopka == 8) {
				if (slovo.length() != 0) {
					cout << '\b' << " " << '\b';
					slovo.erase(slovo.length() - 1);
				}
			}
			else
				if (Knopka == 13) {
					break;
				}
				else {
					sumbol = (char)Knopka;
					if ((sumbol >= 'a' && sumbol <= 'z') || (sumbol >= 'A' && sumbol <= 'Z')) {
						slovo = slovo + sumbol;
						cout << sumbol;
					}
				}
	}
	return slovo;
}
int writeNumbers()
{
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224)
		{
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	return stoi(numbers);
}