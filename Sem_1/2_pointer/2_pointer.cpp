#include <iostream>
using namespace std;
int main()
{
    int a, b, *pa=&a, *pb=&b;
    cin >> a >> b;
    cout << *pa + *pb << endl;
    return 0;
}