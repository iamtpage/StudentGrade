#include "Student.h"
#include <iostream>

using namespace std;

Student::Student()
{
	id = 0;
	fname = "";
	lname = "";
	isValid = true;
}

void Student::setInfo(int newid, string f, string l)
{
	id = newid;
	fname = f;
	lname = l;
}

void Student::printInfo()
{
	cout << "(" << id << ", " << fname << ", " << lname << ")";
}

void Student::setDel(bool flag)
{
	isValid = flag;
}

bool Student::isDel()
{
	return isValid;
}

int Student::getID()
{
	return id;
}
