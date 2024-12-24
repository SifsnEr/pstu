#include <iostream>
using namespace std;
int main()
{
    int n, t, max, min;
    cout << "Введите длину последовательности: ";
    cin >> n;
    cout << "Вводите элементы последовательности: ";
    cin >> t;
    max = min = t;
    for (int i = 2; i <= n; i++)
    {
        cin >> t;
        if (t < min) {min = t;}
        else if (t > max) {max = t;}
    }
    cout << "Сумма максимального и минимального: " << max+min;
    return 0;
}