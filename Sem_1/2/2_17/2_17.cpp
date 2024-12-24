#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    float x, s=1, fact=1;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
        s += (pow(x, i)/fact);
    }
    cout << s;
    return 0;
}