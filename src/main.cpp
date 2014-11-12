#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Student.h"
#include "Grades.h"

using namespace std;

void runPrompt();
void addStudents(int id, string fname, string lname);
void addGrades(int id, string course, string grade);
void delStudents(int id);
void delGrades(int id, string course);
void disp(bool flag);
void error(string s);

//this is where i will store the string tokens
string strarray[10];

Grades gradearray[128];
Student studentarray[128];

int main()
{
	runPrompt();
}

void runPrompt()
{
	string input = "";
	int index;
	
	//to make sure the first argument given is "students" or "grades"
	bool firstarg = true;
	
	//flag for letting us know if they typed students (true) or grades (false)
	bool sorg = false;

	while(input != "quit")
	{
	    index = 0;
		cout << "table> ";
		//get the input and split into iss stream
		getline(cin,input);
		istringstream iss(input);

		while(iss)
		{
			//gather strings delimited by ' ' and store in array
			//index starts at 0, so increment after
			iss >> strarray[index];
			index++;
		}

		if(input.find("add") != string::npos && !firstarg)
		{
			//strarray[] = students|grades add (id) (fname)|(course) (lname)|(grade)
			
			int sid = atoi(strarray[2].c_str());
			
			if(sorg) //students
			{
				
				addStudents(sid, strarray[3], strarray[4]);
			}
			
			if(!sorg)
			{
				addGrades(sid, strarray[3], strarray[4]);
			}
		}
		
		if(input.find("students") != string::npos && firstarg)
		{
			//they typed students
			sorg = true;
			
			//no longer the first argument
			firstarg = false;
		}
		
		if(input.find("grades") != string::npos && firstarg)
		{
			//they typed grades
			sorg = false;
			
			//no longer the first argument
			firstarg = false;
		}

		if(input.find("delete") != string::npos && !firstarg)
		{
			//strarray[] = grades delete (id) (course)
			//strarray[] = students delete (id)
			
			int sid = atoi(strarray[2].c_str());
			
			if(sorg) //students
			{
				
				delStudents(sid);
			}
			
			if(!sorg)
			{
				delGrades(sid, strarray[3]);
			}
		}


		if(input.find("display") != string::npos && !firstarg)
		{
			//display(true) will display students
			//display(false) will display grades
			
			disp(sorg);
		}

		if(input.find("quit") != string::npos)
        {
			break;
		}

		if(input.find("quit") == string::npos && input.find("display") == string::npos
                && input.find("delete") == string::npos && input.find("add") == string::npos
                && firstarg)
		{
			error(input);
		}
	}
}

void disp(bool flag)
{
	int i;
	
	if(flag)
	{
		//display students
		for(i = 0; i < 128; i++)
		{
			if(flag)
			{
				studentarray[i].printInfo();
				
				if(studentarray[i+1].getID() != 0)
				{
					cout << ",";
				}
			}
			
			else
			{
				gradearray[i].printGrades();
				
				if(gradearray[i+1].getID() != 0)
				{
					cout << ",";
				}
			}	
		}
	}
	
	else
	{
		cout << "empty table\n";
	}
}

void addStudents(int id, string fname, string lname)
{
	//add the students
	int i;
	
	for(i = 0; i < 128; i++)
	{
		if(studentarray[i].getID() == 0)
		{
			studentarray[i].setInfo(id, fname, lname);
			break;
		}
	}
}

void addGrades(int id, string course, string grade)
{
	//add the grades
	int i;
	for(i = 0; i < 128; i++)
	{
		if(gradearray[i].getID() == 0)
		{
			gradearray[i].setData(id, course, grade);
			break;
		}
	}
}

void delGrades(int id, string course)
{
	//delete the grade
	int i;
	
	for(i = 0; i < 128; i++)
	{
		if(gradearray[i].getID() == id && strcmp(gradearray[i].getCourse(), course) == 0)
		{
			gradearray[i].setData(0, "", "");
			break;
		}
	}
}

void delStudents(int id)
{
	//delete the student
	int i;
	
	for(i = 0; i < 128; i++)
	{
		if(studentarray[i].getID() == id)
		{
			studentarray[i].setInfo(0, "", "");
		}
	}
}
void error(string input)
{
		cout << "Error!  Command not recognized: " << input <<endl;
}
