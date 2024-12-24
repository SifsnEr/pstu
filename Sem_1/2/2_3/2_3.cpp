#include <iostream>
using namespace std;
int main()
{
    int N, S, t;
    cout << "N = ";
    cin >> N;
    for (int i=1; i <= N; i++)
    {
        t = 1;
        for (int j=i; j <= 2*i; j++)
        {
            t *= j;
        }
        S += t;
    }
    cout << "S = " << S;
    return 0;
}