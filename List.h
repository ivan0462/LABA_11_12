#pragma once
#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

template <class T>
class List
{
	friend class ListIterator;
public:
	List();
	List(const List<T> &cpy); // конструктор копирования
	~List();
	void push_back(T val); // добавить в конец списка
	void push_front(T val); // добавить в начало списка
	void pop_front();        // удалить элемент из начала списка
	void clear();            // очистить список
	void print();            // вывести содержимое списка
	T front();               // возвратить самый первый элемент
	T back();                // возратить самый последний элемент
	bool empty();            // проверка списка на пустоту
	List<T> & operator+(const T val);
	List<T> & operator=(const List<T> &cpy);
	bool operator==(const List<T> &rVal);
	List<T> & operator--();
private:
	struct Node
	{
		Node(T val)
		{
			data = val;
		}
		T data;
		Node *next;
	};

	Node *firstPtr;
	Node *lastPtr;
	unsigned long counts;
};

template <class T>
List<T>::List()
{
	firstPtr = 0;
	lastPtr = 0;
	counts = 0;
}
//------------------------------
template <class T>
List<T>::List(const List<T> &cpy)
{

	Node *curNode = cpy.firstPtr;
	while (curNode != 0)
	{
		this->push_back(curNode->data);
		curNode = curNode->next;
	}

	counts = cpy.counts;
}
//------------------------------
template <class T>
List<T>::~List()
{

	while (!this->empty())
		this->pop_front();
}
//------------------------------
template <class T>
void List<T>::push_back(T val)
{
	Node *v = new Node(val);
	if (this->empty())
	{
		firstPtr = v;
		lastPtr = v;
		firstPtr->next = 0; // равносильно v->next = 0 или lastPtr->next = 0
	}
	else
	{
		lastPtr->next = v;
		lastPtr = v;
		lastPtr->next = 0;
	}
	counts++;

}
//------------------------------
template <class T>
void List<T>::push_front(T val)
{
	Node *v = new Node(val);
	if (this->empty())
	{
		lastPtr = v;
		lastPtr->next = 0;
	}

	v->next = firstPtr;
	firstPtr = v;
	counts++;
}
//------------------------------
template <class T>
void List<T>::pop_front()
{
	if (this->empty()) // функция не определена для пустого списка
		throw (-1);

	Node *newFirst = firstPtr->next;
	delete firstPtr;
	firstPtr = newFirst;
	counts--;
}
//------------------------------
template <class T>
void List<T>::clear()
{
	while (!this->empty())
		pop_front();
}
//------------------------------
template <class T>
void List<T>::print()
{
	std::cout << "---------------------" << std::endl;
	for (Node *curNodePtr = firstPtr; curNodePtr != 0; curNodePtr = curNodePtr->next)
	{
		std::cout << curNodePtr->data << std::endl;
	}
	std::cout << "---------------------" << std::endl;
}
//------------------------------
template <class T>
T List<T>::front()
{
	if (this->empty()) // функция не определена для пустого списка
		throw (-1);

	return firstPtr->data;
}
//------------------------------
template <class T>
T List<T>::back()
{
	if (this->empty()) // функция не определена для пустого списка
		throw (-1);

	return lastPtr->data;
}
//------------------------------
template <class T>
bool List<T>::empty()
{
	if (counts != 0)
		return false;
	else
		return true;
}
//------------------------------
template <class T>
List<T> & List<T>::operator+(const T val)
{
	push_back(val);
	return *this;
}
//------------------------------
template <class T>
List<T> & List<T>::operator=(const List<T> &cpy)
{
	if (&cpy == this) // защита от самоприсваивания
		return *this;

	while (!this->empty()) // удаления старого списка
		this->pop_front();

	Node *curNode = cpy.firstPtr; // копирование списка
	while (curNode != 0)
	{
		this->push_back(curNode->data);
		curNode = curNode->next;
	}

	counts = cpy.counts;
	return *this;
}
//------------------------------
template <class T>
bool List<T>::operator==(const List<T> &rVal)
{
	if (this->counts != rVal.counts)
	{
		// списки содержат разное число элементов
		return false;
	}

	if (this->counts == 0)
		return true; // оба списка пусты

	Node *x1 = this->firstPtr; // поэлементное сравнение
	Node *x2 = rVal.firstPtr;
	while (x1 != 0)
	{
		if (x1->data != x2->data)
			return false;
		x1 = x1->next;
		x2 = x2->next;
	}

	// если мы тут, то несовпадения в списках не обнаружены
	return true;
}

template <class T>
List<T> & List<T>::operator--()
{
	pop_front();
	return *this;
}

#endif // LIST_HPP
