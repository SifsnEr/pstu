#include <iostream>
using namespace std;
int main()
{
    int n, t, max=-2147483648;
    cout << "Введите длину последовательности: ";
    cin >> n;
    cout << "Вводите элементы последовательности: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        if (t > max) {max = t;}
    }
    cout << "Max = " << max;
    return 0;
}