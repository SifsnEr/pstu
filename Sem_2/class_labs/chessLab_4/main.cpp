#include <iostream>
#include "Pair.h"
#include "Fraction.h"

using namespace std;

int main() {
    Pair p1, p2;
    cout << "Enter first pair:\n";
    cin >> p1;
    cout << "Enter second pair:\n";
    cin >> p2;

    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;

    if (p1 > p2) {
        cout << "p1 is greater than p2\n";
    } else {
        cout << "p1 is not greater than p2\n";
    }

    Fraction f1, f2;
    cout << "\nEnter first fraction:\n";
    cin >> f1;
    cout << "Enter second fraction:\n";
    cin >> f2;

    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;

    if (f1 == f2) cout << "f1 is equal to f2\n";
    else cout << "f1 is not equal to f2\n";

    if (f1 != f2) cout << "f1 is not equal to f2\n";
    else cout << "f1 is equal to f2\n";

    if (f1 < f2) cout << "f1 is less than f2\n";
    if (f1 <= f2) cout << "f1 is less or equal to f2\n";
    if (f1 > f2) cout << "f1 is greater than f2\n";
    if (f1 >= f2) cout << "f1 is greater or equal to f2\n";

    return 0;
}
