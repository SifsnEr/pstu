#include <iostream>
#include "Vector.h"
#include "Time.h"
using namespace std;

int main() {
    Vector<int> A(5, 0);
    cin >> A;
    cout << A << endl;
    Vector<int> B(10, 1);
    cout << B << endl;
    B = A;
    cout << B << endl;
    cout << A[2] << endl;
    cout << "size=" << A() << endl;
    B = A + 10;
    cout << B << endl;

    Time t;
    cin >> t;
    cout << t << endl;

    Vector<Time> VA(5, t);
    cin >> VA;
    cout << VA << endl;
    Vector<Time> VB(10, t);
    cout << VB << endl;
    VB = VA;
    cout << VB << endl;
    cout << VA[2] << endl;
    cout << "size=" << VA() << endl;
    VB = VA + t;
    cout << VB << endl;

    return 0;
}
