#include "Vector.h"
#include "error.h"
#include <iostream>
using namespace std;

int main() {
    try {
        Vector v(3);
        cout << v;
        for(int i = 0; i < v(); i++)
            cout << "v[" << i << "] = " << v[i] << endl;

        Vector w = v + 5;
        cout << "After adding 5:\n" << w;

        Vector u = w - 2;
        cout << "After removing 2 elements:\n" << u;

        cout << u[10] << endl;

    } catch(error &e) {
        e.what();
    }
    return 0;
}
