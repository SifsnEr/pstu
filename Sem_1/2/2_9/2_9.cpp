#include <iostream>
using namespace std;
int main()
{
    int N, d;
    cout << "N = ";
    cin >> N;
    d = N/2;

    for (int i = 1; i <= d; i++) {cout << " ";}
    for (int i = 1; i <= N; i++) {cout << "* ";}
    cout << endl;
    for (int i = 1; i <= d-1; i++) {cout << " ";}
    cout << "* ";
    for (int i = 1; i <= N-2; i++) {cout << "  ";}
    cout << "**";
    cout << endl;
    for (int i = 1; i < d; i++)
    {
        if (i == d-1)
        {
            for (int j = 1; j <= N; j++) {cout << "* ";}
            for (int j = 1; j < i; j++) {cout << " ";}
            cout << "* ";
        }
        else
        {
            for (int j = 1; j <= d-i-1; j++) {cout << " ";}
            cout << "* ";
            for (int j = 1; j <= N-2; j++) {cout << "  ";}
            cout << "* ";
            for (int j = 1; j < i; j++) {cout << " ";}
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = 1; i <= d; i++)
    {
            cout << "* ";
            for (int j = 1; j <= N-2; j++) {cout << "  ";}
            cout << "* ";
            for (int j = 1; j < d-1; j++) {cout << " ";}
            cout << "* ";
            cout << endl;
    }
    for (int i = 1; i <= d; i++)
    {
        if (i == d)
        {
            for (int j = 1; j <= N; j++) {cout << "* ";}
        }
        else if (i == d-1)
        {
            cout << "* ";
            for (int j = 1; j <= N-2; j++) {cout << "  ";}
            cout << "*";
            for (int j = 1; j < d-i;j++) {cout << " ";}
            cout << "* ";
            cout << endl;
        }
        else
        {
            cout << "* ";
            for (int j = 1; j <= N-2; j++) {cout << "  ";}
            cout << "* ";
            for (int j = 1; j < d-i-1;j++) {cout << " ";}
            cout << "* ";
            cout << endl;
        }
    }
    return 0;
}