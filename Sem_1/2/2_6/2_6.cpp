#include <iostream>
using namespace std;
int main()
{
    int N;
    cout << "N = ";
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int k = 1; k <= i*2; k++)
        {
            cout << " ";
        }
        for (int j = N-i+1; j >= 1; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
