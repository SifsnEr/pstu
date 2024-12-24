#include <iostream>
using namespace std;
int main()
{
    int N, sc, sr = 1;
    cout << "N = ";
    cin >> N;
    sc = N - 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= sc; j++)
        {
            cout << " ";
        }
        sc--;
        for (int k = 1; k <= sr; k++)
        {
            cout << "* ";
        }
        sr++;
        cout << endl;
    }
}