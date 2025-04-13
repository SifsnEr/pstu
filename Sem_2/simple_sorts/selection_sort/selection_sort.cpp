#include <iostream>

using namespace std;
int main()
{
    int len = 10, arr[len]{}, t, min_i;
    for (int i = 0; i < len; i++)
    {
        arr[i] = len-i;
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < len-1; i++)
    {   
        min_i = i;
        for (int j = i+1; j < len; j++)
        {
            if (arr[j] < arr[min_i]) 
            {
                min_i = j;
            }
        }
        t = arr[i];
        arr[i] = arr[min_i];
        arr[min_i] = t;
    }
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}