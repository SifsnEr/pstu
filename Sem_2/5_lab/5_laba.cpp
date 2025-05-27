#include <iostream>
using namespace std;
void func(int a)
{
    for (int i = 0; i < 3; i++ )
    {   
        cout << "(";
        for (int j = 0; j < 10-1; j++)
        {
            if (a[i][j] == 0)
            {
                cout << ",";
            }
            else cout << a[i][j];
        }
        cout << ")";
    }
}
int main()
{
    int a[3][10] = {{1,2,3,0,4,5,6,0,9,0}, {1,2,3,0,4,5,6,0,9,0}, {1,2,3,0,4,5,6,0,9,0}};
    
    return 0;
}