#include <iostream>
using namespace std;
int main()
{
    int max, min, n, *pmax=&max, *pmin=&min;
    max = 0;
    min = 9999999;
    cout << "Введите длину последовательности: ";
    cin >> n;
    cout << endl << "Введите элементы последовательности: " << endl;
    for (int i, *pi=&i; n > 0; n--)
    {
        cin >> i;
        if (*pi > *pmax) {*pmax = *pi;}
        if (*pi < *pmin) {*pmin = *pi;}
    }
    cout << "Минимальный элемент: " << *pmin << endl;
    cout << "Максимальный элемент: " << *pmax << endl;
    return 0;
}