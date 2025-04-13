#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{   
    srand(time(NULL));
    int n, k, j;
    cout << "Введите кол-во элементов массива: ";
    cin >> n;
    cout << "Введите номер эдемента для удаления: ";
    cin >> k;
    int a[n] = {}, b[n-1] = {}, c[(n-1)+n/2];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
        cout << a[i] << " ";
    }
    cout << endl;
    j = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == k-1)
        {
            continue;
        }
        else
        {
            b[j] = a[i];
            j++;
        }
    }
    j = 0;
    bool fl = 0;
    for (int i = 0; i < ((n-1)+n/2); i++)
    {
        if (j%2 == 0 && fl)
        {
            c[i] = 0;
            cout << c[i] << " ";
            fl = 0;
        }
        else
        {
            c[i] = b[j];
            j++;
            cout << c[i] << " ";
            fl = 1;
        }
    }
    return 0;
}