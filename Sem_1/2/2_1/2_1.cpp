#include <iostream>
using namespace std;
int main()
{
    int N, S;
    cout << "N = ";
    cin >> N;
    for (int i=1; i <= N; i++)
    {
        S += i;
    }
    cout << "S = " << S;
    return 0;
}