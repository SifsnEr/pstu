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
            k = 1;
        }
        else if (a == max) {k+=1;}
    }
    cout << "Максимальный жлемент: " << max << "Их количество" << k;
    return 0;
}