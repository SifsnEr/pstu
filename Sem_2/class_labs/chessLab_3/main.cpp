#include "Time.h"
#include <iostream>
using namespace std;

int main() {
    Time a, b;
    cin >> a;
    cin >> b;

    Time c = a + b;
    cout << "a + b = " << c << endl;

    if (a == b) {
        cout << "a and b are equal" << endl;
    } else {
        cout << "a and b are NOT equal" << endl;
    }

    return 0;
}
