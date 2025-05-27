#include <iostream>
using namespace std;
int main()
{   
    string s;
    getline(cin, s);
    int l = s.length();
    bool fl = 1;
    for (int i = 0; i < l/2; i++)
    {
        if (s[i] != s[l-i-1]) 
        {
            fl = 0;
            break;
        }
        else continue;
    }
    if (fl) cout << "Is palindrome.";
    else cout << "Nope.";
    return 0;
}