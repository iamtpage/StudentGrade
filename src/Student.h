#include <string>

using namespace std;

class Student
{
    public:
        Student();
        void setInfo(int, string, string);
        void printInfo();
        void setDel(bool);
        bool isDel();
        int getID();

    private:
        int id;
        bool isValid;
        string fname;
        string lname;
};

