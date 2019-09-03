#include <iostream>

using namespace std;

void testDefaultArg(int day = 1, string month= "Jan",int year = 2017) {
        cout << "Today is " << day <<" "
                << month << " " << year << endl;
}

int main ()
{
        testDefaultArg(); // default arguments;
        testDefaultArg(10);
        testDefaultArg(10, "Jul");
        testDefaultArg(10,"Jul", 2019);
}
