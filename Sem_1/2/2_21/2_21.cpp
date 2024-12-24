#include <iostream>
using namespace std;
int main()
{
    int t, nt;
    bool fl = 1;
    cin >> t;
    while (t != 0)
    {
        cin >> nt;
        if (t > nt && nt != 0) {fl = 0;}
        t = nt;
    }
    if (fl) {cout << "Упорядочена";}
    else {cout << "Не упорядочена";}
    return 0;
}