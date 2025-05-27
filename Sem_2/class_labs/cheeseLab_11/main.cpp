#include <iostream>
#include "Time.h"
#include "Vector.h"
using namespace std;

int main()
{
    int n;
    cout << "n? ";
    cin >> n;

    Vector<Time> v(n);
    cout << "Initial stack:" << endl;
    v.Print();

    Time max_el = v.Max();
    cout << "Max element: " << max_el << endl;
    v.Add(max_el, 1);
    cout << "After adding max element at position 1:" << endl;
    v.Print();

    v.DelMin();
    cout << "After deleting min element:" << endl;
    v.Print();

    v.AddSredneeToAll();
    cout << "After adding average to all elements:" << endl;
    v.Print();

    return 0;
}
