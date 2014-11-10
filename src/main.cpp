#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>

using namespace std;

void runPrompt();
void addStudents(int id, string fname, string lname);
void addGrades(int id, string course, string grade);
void delStudents(int id);
void delGrades(int id, string course);
void disp(bool flag);
void dispGrades();
void error(string s);

//this is where i will store the string tokens
string strarray[10];

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
	if(flag)
	{
		//display students
	}
	
	else
	{
		//display grades
	}
}

void addStudents(int id, string fname, string lname)
{
	//add the students
}

void addGrades(int it, string course, string grade)
{
	//add the grades
}

void delGrades(int id, string course)
{
	//delete the grade
}

void delStudents(int id)
{
	//delete the student
}
void error(string input)
{
		cout << "Error!  Command not recognized: " << input <<endl;
}
