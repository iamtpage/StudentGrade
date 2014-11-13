#include <string.h>

using namespace std;

class Student
{
    public:
        Student();
        void setInfo(int newid, string f, string l);
        void printInfo();
        void setValid(bool);
        bool isValid();
        int getID();
        string getFname();
        string getLname();

    private:
        int id;
        bool valid;
        string fname;
        string lname;
};

