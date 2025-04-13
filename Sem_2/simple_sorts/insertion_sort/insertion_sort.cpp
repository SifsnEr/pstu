#include <iostream>

using namespace std;
int main()
{
    int len = 10, arr[len]{}, t;
    for (int i = 0; i < len; i++)
    {
        arr[i] = len-i;
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 1; i < len; i++)
    {   
        t = arr[i];
        for (int j = i-1; (j >= 0)&&(arr[j] > t); j--)
        {
                arr[j+1] = arr[j];
                arr[j] = t;
        }
    }
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}