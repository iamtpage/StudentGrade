#include <iostream>
#include <string.h>

#include "Student.h"

using namespace std;

Student::Student()
{
	//initialize the variables
	id = -1;
	fname = "";
	lname = "";
	valid = false;
}

void Student::setInfo(int newid, string f, string l)
{
	//set the information given by parameters
	id = newid;
	fname = f;
	lname = l;
	valid = true;
}

void Student::printInfo()
{
	//cases when we should print it out
	if(id != -1 && valid)
	{
		cout << "(" << id << ", " << fname << ", " << lname << ")";
	}
}

void Student::setValid(bool flag)
{
	//option to toggle if this spot in the array is valid
	valid = flag;
}

bool Student::isValid()
{
	//returns if the index is valid
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
