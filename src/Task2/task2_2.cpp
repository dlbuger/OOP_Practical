#include <iostream>

using namespace std;
void testOverloading( int numerator, int denominator);
void testOverloading(double numerator, double denominator);
void testOverloading(int numerator, double denominator);
int main()
{
        testOverloading(5,6);
        testOverloading(3.2, 4.5);
        testOverloading(6, 6.6);

}

void testOverloading( int numerator, int denominator) {
        int fraction = numerator / denominator;
        cout << "Fraction1 = " << fraction << endl;
}
void testOverloading(double numerator, double denominator) {
        double fraction = numerator / denominator;
        cout << "Fraction2 = " << fraction << endl;
}
void testOverloading(int numerator, double denominator) {
        double fraction = numerator / denominator;
        cout << "Fraction3 = " << fraction << endl;
}

