#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int N = 8;
int solutionCount = 0;
vector<int> queens(N);

bool isSafe(int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (queens[i] == col || abs(queens[i] - col) == abs(i - row)) {
            return false; 
        }
    }
    return true;
}

void printSolution() {
    cout << "Решение #" << ++solutionCount << ":\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << (queens[i] == j ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

void solve(int row = 0) {
    if (row == N) {
        printSolution();
        return;
    }
    for (int col = 0; col < N; ++col) {
        if (isSafe(row, col)) {
            queens[row] = col;
            solve(row + 1);
        }
    }
}

int main() {
    solve();
    cout << "Всего решений: " << solutionCount << endl;
    return 0;
}
