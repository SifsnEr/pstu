#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float a, n, max, k=1;
    cin >> n;
    max = sin(n + 1/n);
    for (int i=2; i<=n; i++)
    {
        a = sin(n + i/n);
        if (a > max) 
        {
            max = a; 
            k = i;
        }
    }
    cout << "Максимальный жлемент: " << max << "Его номер: " << k;
    return 0;
}