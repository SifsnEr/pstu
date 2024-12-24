#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int N, s;
    //1_______________________________________
    cout << "N = ";
    cin >> N;
    s = sqrt(N);
    for (int i = 1; i <= s; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    //2_______________________________________
    cout << "N = ";
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    //3_______________________________________
    cout << "N = ";
    cin >> N;
    for (int i = 1; i <= N; i++)
    {   
        if ((i == 1) or (i == N))
        {
            for (int j = 1; j <= N; j++)
            {
            cout << "* ";
            }
        }
        else
        {
            cout << "* ";
            for (int j = 1; j <= N-2; j++)
            {
            cout << "  ";
            }
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}