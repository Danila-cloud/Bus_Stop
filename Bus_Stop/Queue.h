#pragma once
#include"MyData.h"

#include<iostream>
using namespace std;

//QueueRing кольцевая очередь по принципу "элемент, который выходит из начала очереди, будет перемещён в её конец."

template<class T>
class QueueRing
{
	MyData<T>* first = nullptr;
	MyData<T>* last = nullptr;
	int size = 0;

public:
	~QueueRing();
	void push(T val);
	T pop();
	T pop_front();//извлечение первого элемента
	T peek();
	int getSize();
	void clear();
	void print() const;
};

template<class T>
inline QueueRing<T>::~QueueRing()
{
	clear();
}

template<class T>
inline void QueueRing<T>::push(T val)
{
	if (size == 0)
	{
		first = new MyData<T>;
		first->value = val;
		last = first;
	}

	else
	{
		MyData<T>* temp = new MyData<T>;
		temp->value = val;
		last->next = temp;
		last = temp;
	}

	size++;
}

template<class T>
inline void QueueRing<T>::push(T val)
{
	if (size == 0)
	{
		first = new MyData<T>;
		first->value = val;
		last = first;
	}

	else
	{
		MyData<T>* temp = new MyData<T>;
		temp->value = val;
		last->next = temp;
		last = temp;
	}

	size++;
}

template<class T>
inline T QueueRing<T>::pop()
{
	if (size == 0)
	{
		cout << "Очередь пустая!";
		system("pause");
		exit(1);
	}

	T val = first->value;

	if (size == 1)
	{
		return val;
	}

	else
	{
		MyData<T>* temp = first;
		first = first->next;
		last->next = temp;
		last = temp;
		temp->next = nullptr;
	}

	return val;
}

template<class T>
inline T QueueRing<T>::pop_front()
{
	if (size == 0)
	{
		cout << "Очередь пустая!";
		system("pause");
		exit(1);
	}

	T val = first->value;

	if (size == 1)
	{
		delete first;
		first = last = nullptr;
	}

	else
	{

		MyData<T>* temp = first;
		first = first->next;
		delete temp;
	}

	size--;

	return val;
}

template<class T>
inline T QueueRing<T>::peek()
{
	if (size > 0)
	{
		return last->value;
	}

	else
	{
		cout << "Очередь пустая!";
		system("pause");
		exit(1);
	}
}

template<class T>
inline int QueueRing<T>::getSize()
{
	return size;
}

template<class T>
inline void QueueRing<T>::clear()
{
	while (size)
		pop_front();
	first = last = nullptr;
}

template<class T>
inline void QueueRing<T>::print() const
{
	MyData<T>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}