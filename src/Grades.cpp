#include "Grades.h"
#include <iostream>

using namespace std;

Grades::Grades()
{
	id = 0;
	course = "";
	grade = "";
	isValid = true;
}

void Grades::setData(int newid, string newcourse, string newgrade)
{
	id = newid;
	course = newcourse;
	grade = newgrade;
}

void Grades::printGrades()
{
	cout << "(" << id << ", " << course << ", " << grade << ")";
}

void Grades::setDel(bool flag)
{
	isValid = flag;
}

bool Grades::isDel()
{
	return isValid;
}

int Grades::getID()
{
	return id;
}

string Grades::getCourse()
{
	return course;
}
