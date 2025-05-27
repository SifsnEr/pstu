#include <iostream>
#include "container.h"
#include "Time.h"
using namespace std;

int main() {
    Vector<int, Time> v;

    v.fill({
        {1, Time(1,10,30)},
        {2, Time(2,20,40)},
        {3, Time(0,30,50)},
        {4, Time(3,40,10)},
        {5, Time(0,50,20)}
    });

    v.add_max_element_with_new_key();
    v.remove_min_element();
    v.add_average_to_all();

    v.print(cout);
    return 0;
}
