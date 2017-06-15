#pragma once
#include "SLListNode.h"
#include <stdlib.h>
#include <iostream>
#include "types1.h"

using namespace std;

template <class T>
class SLList
{
	SLListNode<T> firstElm;
	SLListNode<T>* getLast(); //вернуть указатель последний элемент
	SLListNode<T>* findPrev(T key); //найти предыдущий элемент
	int size;
public:
	SLList();
	int getSize(); //вывести размер связного списка
	void add(T x); //добавить элемент
	void print(); //вывести содержимое
	void pop(T x); //удалить элемент
	void bubblesort(); // сотировка
	/*void findstr(T* str, int lgh, int output);*/
	void concatenation(SLList x);
	SLList<T>& operator+=(SLList<T> b);			//перегрузка +=
};



template <class T>
void SLList<T>::print()
{
	for (SLListNode<T> *temp = firstElm.next; temp != nullptr; temp = temp->next)
	{
		std::cout << temp->outputData() << " ";
	}
}


template <class T>
void SLList<T>::pop(T x)
{
	SLListNode<T> *prevElm = findPrev(x);
	if (prevElm)
	{
		SLListNode<T> *temp = prevElm->next;
		prevElm->next = prevElm->next->next;
		delete temp;
		--size;
	}
}

template <class T>
SLList<T>& SLList<T>::operator+=(SLList<T> b)
{
	getLast()->next = b.firstElm.next;
	size += b.getSize();
	return *this;
}

template <class T>
SLListNode<T>* SLList<T>::getLast()
{
	SLListNode<T> *i = &firstElm;
	while (i->next != nullptr)
	{
		i = i->next;
	}
	return i;
}

template <class T>
void SLList<T>::add(T x)
{
	SLListNode<T> *temp = new SLListNode<T>;
	temp->next = firstElm.next;
	firstElm.next = temp;
	temp->inputData(x);
	++size;
}

template <class T>
SLListNode<T>* SLList<T>::findPrev(T key)
{
	SLListNode<T> *i1, *i2;
	i1 = &firstElm;
	i2 = firstElm.next;
	for (; i2 != nullptr; i1 = i2, i2 = i2->next)
	{
		if (i2->outputData() == key)
		{
			return i1;
		}
	}
	return nullptr;
}

template <class T>
int SLList<T>::getSize()
{
	return size;
}


template <class T>
SLList<T>::SLList()
{
	firstElm.next = nullptr;
}


template <class T>
void SLList<T>::bubblesort()
{
	bool notsorted = false;
	if(getSize() > 1)
	{	
		do
		{
			notsorted = false;
			SLListNode<T> *t1 = &firstElm;
			SLListNode<T> *t2 = firstElm.next;
			SLListNode<T> *t3 = t2->next;
			do
			{
				if (t2->outputData() > t3->outputData())
				{
					notsorted = true;
					t1->next = t3;
					t2->next = t3->next;
					t3->next = t2;
					swap(t2, t3);
				}
				t1 = t1->next;
				t2 = t2->next;
				t3 = t3->next;
			} while (t3 != nullptr);

		} while (notsorted);		
	}
}

template <class T>
void SLList<T>::concatenation(SLList x)
{
	getLast()->next = x.firstElm.next;
	size += x.getSize();
	bubblesort();
}

template <class T>
//void SLList<T>::findstr(T* str, int lgh, int output)
//{
//	SLListNode<T> *i;
//	int outp = 0;
//	for (i = firstElm.next; i->next != nullptr; i = i->next, ++outp)
//	{
//		int j;
//		SLListNode<T> *i2;
//		for (j = 0, i2 = i; j < lgh && i2->next != nullptr; ++j, i2 = i2->next)
//		{
//			if (str[j] != i2->data)
//			{
//				break;
//			}
//		}
//		if (j == lgh)
//		{
//			output = outp;
//			return;
//		}
//	}
//}