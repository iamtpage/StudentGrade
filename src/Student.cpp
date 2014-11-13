#include <iostream>
#include <string.h>

#include "Student.h"

using namespace std;

Student::Student()
{
	id = -1;
	fname = "";
	lname = "";
	valid = false;
}

void Student::setInfo(int newid, string f, string l)
{
	id = newid;
	fname = f;
	lname = l;
	valid = true;
}

void Student::printInfo()
{
	if(id != -1 && valid)
	{
		cout << "(" << id << ", " << fname << ", " << lname << ")";
	}
}

void Student::setValid(bool flag)
{
	valid = flag;
}

bool Student::isValid()
{
	return valid;
}

int Student::getID()
{
	return id;
}

string Student::getFname()
{
	return fname;
}

string Student::getLname()
{
	return lname;
}
