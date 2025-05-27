#include "Pair.h"
#include "Fraction.h"
#include "Vector.h"
#include <iostream>
using namespace std;

int main() {
    Pair p;
    cin >> p;
    cout << p;

    Fraction f;
    cin >> f;
    cout << f;

    Object* ptr1 = &p;
    Object* ptr2 = &f;

    ptr1->Show();
    ptr2->Show();

    Vector v(5);
    v.Add(ptr1);
    v.Add(ptr2);
    cout << v;

    return 0;
}
