#include <iostream>
#include <string>
using namespace std;
#ifndef TYPES1
#define TYPES1
class student
{
public:
	string firstname, lastname, middlename;
	int id;
	bool operator==(student b); // перегрузка ==
	void operator=(student b);
	friend ostream& operator<<(ostream &os, student &x);
};

class teacher
{
public:
	std::string firstname, lastname, middlename;
	int id;
	bool operator==(teacher b);
	void operator=(teacher b);
	friend ostream& operator<<(std::ostream &os, teacher &x);
};


bool student::operator==(student b)
{
	return(this->firstname == b.firstname && this->lastname == b.lastname && this->middlename == b.middlename && this->id == b.id);
}

bool teacher::operator==(teacher b)
{
	return(this->firstname == b.firstname && this->lastname == b.lastname && this->middlename == b.middlename && this->id == b.id);
}

void student::operator=(student b)
{
	this->firstname = b.firstname;
	this->lastname = b.lastname;
	this->middlename = b.middlename;
	this->id = b.id;
}

void teacher::operator=(teacher b)
{
	this->firstname = b.firstname;
	this->lastname = b.lastname;
	this->middlename = b.middlename;
	this->id = b.id;
}


ostream& operator<<(ostream &os, student &x)
{	
	os << x.firstname << " " << x.lastname << " " << x.middlename << endl << "id: " << x.id;
	return os;
}

ostream& operator<<(ostream &os, teacher &x)
{
	os << x.firstname << " " << x.lastname << " " << x.middlename << endl << "id: " << x.id;
	return os;
}
#endif // TYPES1


