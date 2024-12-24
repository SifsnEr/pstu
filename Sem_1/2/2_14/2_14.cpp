#include <iostream>
using namespace std;
int main()
{
    int n, s=0;
    cout << "Введите число: ";
    cin >> n;
    while (n>0)
    {
        s += n%10;
        n /= 10;
    }
    cout << "Сумма цифр числа: " << s;
    return 0;
}