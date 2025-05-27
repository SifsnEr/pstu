#include <iostream>
#include <vector>
#include <algorithm>

void countingSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    int maxVal = *std::max_element(arr.begin(), arr.end());

    std::vector<int> count(maxVal + 1, 0);

    for (int num : arr) {
        ++count[num];
    }

    int index = 0;
    for (int val = 0; val <= maxVal; ++val) {
        while (count[val] > 0) {
            arr[index++] = val;
            --count[val];
        }
    }
}

int main() {
    std::vector<int> data = {4, 2, 2, 8, 3, 3, 1};

    std::cout << "До сортировки: ";
    for (int val : data) std::cout << val << " ";
    std::cout << "\n";

    countingSort(data);

    std::cout << "После сортировки: ";
    for (int val : data) std::cout << val << " ";
    std::cout << "\n";

    return 0;
}
