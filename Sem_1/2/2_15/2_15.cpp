#include <iostream>
using namespace std;
int main()
{
    int n, s;
    bool fl = 0;
    cout << "Введите число и цифру: ";
    cin >> n >> s;
    while (n>0 && !fl)
    {
        if (s == (n%10))
        {
            fl = 1;
            cout << "Цифра входит в число";
        }
        else {n /= 10;}
    }
    if (!fl) {cout << "Цифра не входит в число";}
    return 0;
}