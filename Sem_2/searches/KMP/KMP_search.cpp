#include <iostream>
#include <vector>
#include <string>

std::vector<int> computePrefixFunction(const std::string& pattern) {
    int m = (int)pattern.size();
    std::vector<int> pi(m, 0);
    int k = 0;

    for (int q = 1; q < m; ++q) {
        while (k > 0 && pattern[k] != pattern[q])
            k = pi[k - 1];
        if (pattern[k] == pattern[q])
            ++k;
        pi[q] = k;
    }
    return pi;
}

int kmpSearch(const std::string& text, const std::string& pattern) {
    if (pattern.empty()) return 0;
    int n = (int)text.size();
    int m = (int)pattern.size();
    std::vector<int> pi = computePrefixFunction(pattern);
    int q = 0;

    for (int i = 0; i < n; ++i) {
        while (q > 0 && pattern[q] != text[i])
            q = pi[q - 1];
        if (pattern[q] == text[i])
            ++q;
        if (q == m) {
            return i - m + 1;
        }
    }
    return -1;
}

int main() {
    std::string text = "ababcabcabababd";
    std::string pattern = "ababd";

    int pos = kmpSearch(text, pattern);

    if (pos != -1)
        std::cout << "Подстрока найдена на позиции " << pos << std::endl;
    else
        std::cout << "Подстрока не найдена" << std::endl;

    return 0;
}
