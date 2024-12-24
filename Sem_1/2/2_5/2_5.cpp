#include <iostream>
using namespace std;
int main()
{
    int N;
    cout << "N = ";
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for ( int k = (N-i)*2; k >= 1; k--)
        {
            cout << " ";
        }
        for ( int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
