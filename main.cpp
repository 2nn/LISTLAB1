#include <stdio.h>
#include <iostream>
#include <locale.h>
#include "SLList.h"
#include "types1.h"
#include <string>

void testint();

int main()
{
	setlocale(0, "Russian");
	testint();
	system("pause");
	return 0;
}

void testint()
{
	SLList<int> a, b;
	a.add(1);
	a.add(3);
	a.add(43);
	a.add(5);
	a.add(123);
	a.add(4);
	b.add(123);
	b.add(3);
	b.add(4);
	b.add(5);
	b.add(65);
	cout << "содержимое a" << endl;
	a.print();
	cout << endl;
	cout << endl;
	cout << "содержимое списка b" << endl;
	b.print();
	cout << endl;
	cout << endl;
	cout << "a.add(3)" << endl << "a: ";
	a.add(3);
	a.print();
	cout << endl;
	cout << endl;
	cout << "a.bubblesort()" << endl << "a: ";
	a.bubblesort();
	a.print();
	cout << endl;
	cout << endl;
	cout << "a.concatenation(b)" << endl << "a: ";
	a.concatenation(b);
	a.print();
	cout << endl;
	cout << endl;
	cout << "a.pop(123)" << endl << "a: ";
	a.pop(123);
	a.print();
	cout << endl << endl << "создадим список c" << endl << "c: ";
	SLList<int> c;
	c.add(7);
	c.print();
	cout << endl;
	cout << endl << "a+=c" << endl << "a: " ;
	a += c;
	a.print();
}