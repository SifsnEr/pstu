#include <iostream>
#include <vector>
#include <algorithm>

int hoarePartition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        std::swap(arr[i], arr[j]);
    }
}

void quickSortHoare(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = hoarePartition(arr, low, high);
        quickSortHoare(arr, low, p);
        quickSortHoare(arr, p + 1, high);
    }
}

int main() {
    std::vector<int> data = {24, 8, 42, 75, 29, 77, 38, 57};

    std::cout << "До сортировки: ";
    for (int val : data) std::cout << val << " ";
    std::cout << "\n";

    quickSortHoare(data, 0, data.size() - 1);

    std::cout << "После сортировки: ";
    for (int val : data) std::cout << val << " ";
    std::cout << "\n";

    return 0;
}
