#include <iostream>
using namespace std;
int main()
{
    int n, *pn=&n, f=1, *pf=&f;
    cout << "N = ";
    cin >> n;
    for (int i = 1; i <= *pn;i++)
    {
        *pf *= i;
    }
    cout << endl << "N! = " << *pf;
    return 0;
}