#include <string>

using namespace std;

class Grades
{
    public:
        Grades();
        void setData(int, string, string);
        void printGrades();
        void setValid(bool);
        bool isValid();
        int getID();
        string getCourse();

    private:
        int id;
        bool valid;
        string course;
        string grade;
};


