#include <iostream>

using namespace std;

double quotient(int a, int b);
int remainder(int a, int b);


int main()
{
        cout<<"Quotient --> ";
        cout<<quotient(20, 10)<<endl;

        cout<<"Remainder --> ";
        cout<<remainder(5 ,10)<<endl;

}

double quotient(int a, int b)
{
        return a / b;
}

int remainder(int a, int b)
{
        return a % b;
}
