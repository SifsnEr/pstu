#include <iostream>
#include <vector>

void shellSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }
    }
}

int main() {
    std::vector<int> data = {23, 12, 1, 8, 34, 54, 2, 3};

    std::cout << "До сортировки: ";
    for (int val : data) std::cout << val << " ";
    std::cout << "\n";

    shellSort(data);

    std::cout << "После сортировки: ";
    for (int val : data) std::cout << val << " ";
    std::cout << "\n";

    return 0;
}
