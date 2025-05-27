#include <iostream>
using namespace std;
int sum() {
    return 0;
}
template<typename... Args>
int sum(int a, Args... args) {
    return a + sum(args...);
}
int main()
{   
    cout << sum(1, 2, 3) << endl;
    cout << sum(1, 2, 3, 4, 5, 6, 7) << endl;
    cout << sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11) << endl;
    return 0;
}