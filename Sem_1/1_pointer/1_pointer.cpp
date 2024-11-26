#include <iostream>
using namespace std;
int main()
{
    int a, b, tmp, *pa=&a, *pb=&b;
    cin >> a >> b;
    tmp = *pa;
    *pa = *pb;
    *pb = tmp;
    cout << *pa << *pb;
    return 0;
}