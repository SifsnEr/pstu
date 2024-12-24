#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n, r=0, i=0;
    cin >> n;
    while (n > 0)
    {
        r = r*10 + n%10;
        n /= 10;
        i += 1;
    }
    cout << setfill('0') << setw(i) << r;
    return 0;
}