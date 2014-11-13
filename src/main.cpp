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
		
		if(strarray[1] == "add")
		{
			//strarray[] = students|grades add (id) (fname)|(course) (lname)|(grade)
			
			if(strarray[2] != "" && strarray[3] != "" && strarray[4] != "" && strarray[6] == "")
			{
				
				if(strarray[0] == "grades")
				{
					int sid = atoi(strarray[2].c_str());
					addGrades(sid, strarray[3], strarray[4]);
				}
			
				if(strarray[0] == "students")
				{
					int sid = atoi(strarray[2].c_str());
					addStudents(sid, strarray[3], strarray[4]);
				}
				
				else
				{
					cout << "Erorr! Invalid Format.\n";
				}
			}
			
			else
			{
				cout << "Error! Wrong format.\n";
			}
		}

		//if(input.find("delete") != string::npos && !firstarg)
		if(strarray[1] == "delete")
		{
			//strarray[] = grades delete (id) (course)
			//strarray[] = students delete (id)
			
			int sid = atoi(strarray[2].c_str());
			
			if(strarray[0] == "students") //students
			{	
				delStudents(sid);
			}
			
			if(strarray[0] == "grades")
			{
				delGrades(sid, strarray[3]);
			}
		}


		//if(input.find("display") != string::npos && input.find("students") != string::npos)
		if(strarray[1] == "display")
		{
			//strarray[] = students|grades add (id) (fname)|(course) (lname)|(grade)
			if(strarray[0] == "students")
			{
				disp(true);
			}
			
			if(strarray[0] == "grades")
			{
				disp(false);
			}
		}
		
		//if(input.find("quit") != string::npos)
		if(strarray[0] == "quit")
        {
			break;
		}
		
        if(strarray[0] != "quit" && strarray[0] != "students" && strarray[0] != "grades")
		{
			error(input);
		}

		int x;
		for(x = 0; x < 10; x++)
		{
			strarray[x] = "";
		}
	}
}

void disp(bool flag)
{
	int i;
	bool empty = true;
	
	//display students
	for(i = 0; i < 128; i++)
	{
		if(flag && studentarray[i].isValid() && studentarray[i].getID() != -1) //students
		{
			empty = false;
			studentarray[i].printInfo();
				
			if(studentarray[i+1].isValid())
			{
				cout << ",";
			}
		}
		
		if(!flag && gradearray[i].isValid() && gradearray[i].getID() !=-1) //grades
		{
			empty = false;
			gradearray[i].printGrades();
			
			if(gradearray[i+1].isValid())
			{
					cout << ",";
			}
		}
		
	}
	
	
	if(empty)
	{
		cout << "empty table";
	}
	
	cout << endl;		
}

void addStudents(int id, string fname, string lname)
{
	//add the students
	int i;
	bool dupeflag = false;
	
	for(i = 0; i < 128; i++)
	{
		if(studentarray[i].getID() == id)
		{
			dupeflag = true;
			break;
		}
		
		if(studentarray[i].getFname() == fname && studentarray[i].getLname() == lname)
		{
			dupeflag = true;
			break;
		}
	}
	
	if(dupeflag)
	{
		cout << "Error, duplicate entry!\n";
	}
	
	for(i = 0; i < 128; i++)
	{
		if(!studentarray[i].isValid() && !dupeflag)
		{
			studentarray[i].setInfo(id, fname, lname);
			studentarray[i].setValid(true);
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
		if(!gradearray[i].isValid())
		{
			gradearray[i].setData(id, course, grade);
			gradearray[i].setValid(true);
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
		if(gradearray[i].getID() == id && gradearray[i].getCourse().compare(course) == 0)
		{
			gradearray[i].setValid(false);
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
			studentarray[i].setValid(false);
			break;
		}
		
	}
	
	//also delete corresponding grades
	for(i = 0; i < 128; i++)
	{
		if(gradearray[i].getID() == id)
		{
			gradearray[i].setValid(false);
		}
		
	}
}
void error(string input)
{
		cout << "Error!  Command not recognized: " << input <<endl;
}
