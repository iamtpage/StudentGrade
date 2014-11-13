#include "Grades.h"
#include <iostream>

using namespace std;

Grades::Grades()
{
	id = -1;
	course = "";
	grade = "";
	valid = false;
}

void Grades::setData(int newid, string newcourse, string newgrade)
{
	id = newid;
	course = newcourse;
	grade = newgrade;
	valid = true;
}

void Grades::printGrades()
{
	if(id != -1 && valid)
	{
		cout << "(" << id << ", " << course << ", " << grade << ")";
	}
}

void Grades::setValid(bool flag)
{
	valid = flag;
}

bool Grades::isValid()
{
	return valid;
}

int Grades::getID()
{
	return id;
}

string Grades::getCourse()
{
	return course;
}
