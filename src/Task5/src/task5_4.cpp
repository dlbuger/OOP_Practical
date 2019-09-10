
#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int numUnits;
    string *unitList;
    
    public : Student(string name, int numUnits)
    {
        this->name = name;
        this->numUnits = numUnits;
        unitList = new string[numUnits];

        string input = "";
        int counter = 0;
        do
        {
            input = getInput();
            unitList[counter] = input;
            counter++;
        } while (counter != numUnits);
    }

    void display()
    {
        cout<<"The Student name --> "<< name<<endl;
        for (int i=0;i<numUnits;i++)
            cout<<unitList[i] << "\t";

    }
    ~Student()
    {
        delete[] unitList;
    }

private:
    string getInput()
    {
        cout << "Please enter the Units --> ";
        string tmp;
        cin >> tmp;
        return tmp;
    }
};

int main()
{
    Student s1("Jason", 4);
    s1.display();
}
