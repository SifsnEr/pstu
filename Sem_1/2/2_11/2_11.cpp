#include <iostream>
using namespace std;
int main()
{
    int n, t, neg=0, pos=0;
    cout << "Введите длину последовательности: ";
    cin >> n;
    cout << "Вводите элементы последовательности: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        if (t < 0 && !neg && !pos) {neg = t;}
        else if (t > 0 && !pos && !neg) {pos = t;}
    }
    if (neg) {cout << "Первый отрицательный: " << neg;}
    else if (pos) {cout << "Первый положительный: " << pos;}
    else {cout << "Все нули";}
    return 0;
}