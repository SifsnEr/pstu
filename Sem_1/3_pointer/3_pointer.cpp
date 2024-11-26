#include <iostream>
using namespace std;
int main()
{
    float a, b, *pa=&a, *pb=&b;
    cin >> a >> b;
    cout << *pa + *pb << endl;
    return 0;
}