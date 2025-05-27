#include <iostream>
#include <complex>
using namespace std;
int add(int a, int b) {return a + b;}
complex<double> add(complex<double> a, complex<double> b) {return a + b;}
int main()
{
    int a1 = 5, b1 = 8;
    cout << "addition of int nubbers: " << add(a1, b1) << endl;
    complex<double> a2(2.5, 0.3), b2(-5.2, 4.3);
    cout << "addition of complex numbers: " << add(a2, b2);
    return 0;
}