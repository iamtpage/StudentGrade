#include <string>

using namespace std;

class Grades
{
    public:
        Grades();
        void setData(int, string, string);
        void printGrades();
        void setDel(bool);
        bool isDel();
        int getID();
        string getCourse();

    private:
        int id;
        bool isValid;
        string course;
        string grade;
};


