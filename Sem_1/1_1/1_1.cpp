#include <iostream>
using namespace std;
int main() 
{
    int a, b ,c, max;
    cin >> a >> b >> c;
    if (a<=b)
    {
        max = b;
    }
    else
    {
        max = a;
    }
    if (c > max)
    {
        max = c;
    }
    cout << max << endl;
    return 0;
}