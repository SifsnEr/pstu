#include <iostream>
#include <vector>

int lomutoPartition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;        
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortLomuto(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = lomutoPartition(arr, low, high);
        quickSortLomuto(arr, low, pivotIndex - 1);
        quickSortLomuto(arr, pivotIndex + 1, high);
    }
}

int main() {
    std::vector<int> data = {34, 7, 23, 32, 5, 62};

    std::cout << "До сортировки: ";
    for (int val : data) std::cout << val << " ";
    std::cout << "\n";

    quickSortLomuto(data, 0, data.size() - 1);

    std::cout << "После сортировки: ";
    for (int val : data) std::cout << val << " ";
    std::cout << "\n";

    return 0;
}
