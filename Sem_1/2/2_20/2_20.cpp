#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int i=1;
    float a, n, s;
    bool fl = 0;
    cin >> n >> s;
    while (i<=n && !fl)
    {
        a = sin(n + i/n);
        if (a==s) {fl = 1;}
        else {i++;}
    }
    if (fl) {cout << "Элемент найден";}
    else {cout << " Элемент не найден";}
    return 0;
}