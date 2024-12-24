#include <iostream>
using namespace std;
int main()
{
    int N, P = 1;
    cout << "N = ";
    cin >> N;
    for (int i=1; i <= N; i++)
    {
        P *= i;
    }
    cout << "P = " << P;
    return 0;
}