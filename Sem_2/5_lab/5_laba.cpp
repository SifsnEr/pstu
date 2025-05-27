#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printWords(const string& line) {
    cout << "(";
    string word;
    bool first = true;

    for (char ch : line) {
        if (ch != '0') {
            word += ch;
        } else {
            if (!word.empty()) {
                if (!first) cout << ",";
                cout << word;
                word.clear();
                first = false;
            }
        }
    }

    cout << ")";
}

int main() {
    vector<string> lines = {
        "12304506090",
        "2344502340",
        "2344555670"
    };

    for (const string& line : lines)
        printWords(line);

    cout << endl;
    return 0;
}
