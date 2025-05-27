#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void buildBadCharTable(const std::string& pattern, std::vector<int>& badChar) {
    int ALPHABET_SIZE = 256;
    badChar.assign(ALPHABET_SIZE, -1);
    for (int i = 0; i < (int)pattern.size(); ++i) {
        badChar[(unsigned char)pattern[i]] = i;
    }
}

int boyerMooreSearch(const std::string& text, const std::string& pattern) {
    int n = (int)text.size();
    int m = (int)pattern.size();

    if (m == 0) return 0;
    if (m > n) return -1;

    std::vector<int> badChar;
    buildBadCharTable(pattern, badChar);

    int shift = 0;
    while (shift <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[shift + j])
            --j;

        if (j < 0) {
            return shift;
        } else {
            int badCharIndex = badChar[(unsigned char)text[shift + j]];
            int move = j - badCharIndex;
            shift += (move > 0) ? move : 1;
        }
    }
    return -1;
}

int main() {
    std::string text = "HERE IS A SIMPLE EXAMPLE";
    std::string pattern = "EXAMPLE";

    int pos = boyerMooreSearch(text, pattern);

    if (pos != -1)
        std::cout << "Подстрока найдена на позиции " << pos << std::endl;
    else
        std::cout << "Подстрока не найдена" << std::endl;

    return 0;
}
