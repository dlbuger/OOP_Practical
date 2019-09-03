
#include <iostream>
using namespace std;

class Student
{
private:
    int id;
    string name;
    int courseNo;
    bool isEnrolled;
public:
    Student(int id, string name, int courseNo, bool isEnrolled)
    {
        this->id = id;
        this->name = name;
        this->courseNo = courseNo;
        this->isEnrolled = isEnrolled;
    }

    void display()
    {
        cout<<"Student Name  -> " << name << endl
            <<"Student ID    -> " << id << endl
            <<"Course Number -> " << courseNo << endl
            <<"Enrollment    -> " << isEnrolled <<endl;
    }
    
};


int main()
{
    Student s1(322,"Jason", 5, true);
    s1.display();
}

