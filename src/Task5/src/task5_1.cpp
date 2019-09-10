#include <iostream>
using namespace std;

class Task5
{
private:
    const int NUMBER_OF_PLANTS = 4;
    int *production = new int[NUMBER_OF_PLANTS];

public:
    void inputData()
    {
        for (int i = 1; i <= NUMBER_OF_PLANTS; i++)
        {
            cout << endl
                 << "Enter production data for plant number "
                 << i << endl;
            getTotal(production[i - 1]);
        }
    }

    void getTotal(int &amount)
    {
        cout << "Enter a positive integer of units produced by each department, ranging from 1-20.\n"
             << endl;
        cin >> amount;
        while (amount < 0)
        {
            cout << "input again" << endl;
            cin >> amount;
        }
    }

    void graph()
    {
        cout << "\nUnits produced in units:\n";
        for (int i = 1; i <= NUMBER_OF_PLANTS; i++)
        {
            cout << "Plant #" << i << " ";
            printAsterisks(production[i - 1]);
            cout << endl;
        }
    }

    void printAsterisks(int n)
    {
        for (int count = 1; count <= n; count++)
            cout << "*";
    }

    Task5()
    {
        cout << "This program displays a graph showing\n"
             << "production for each plant in the company.\n";

        inputData();
        graph();
    }

    ~Task5()
    {
        delete[] production;
    }
};

int main()
{
    Task5 t;
}


