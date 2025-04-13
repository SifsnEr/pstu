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
    for (int i = 0; i < len-1; i++)
    {
        for (int j = 0; j < len-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}