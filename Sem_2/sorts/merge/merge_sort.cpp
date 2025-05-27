#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> leftPart(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> rightPart(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < leftPart.size() && j < rightPart.size()) {
        if (leftPart[i] <= rightPart[j]) {
            arr[k++] = leftPart[i++];
        } else {
            arr[k++] = rightPart[j++];
        }
    }

    while (i < leftPart.size()) {
        arr[k++] = leftPart[i++];
    }
    while (j < rightPart.size()) {
        arr[k++] = rightPart[j++];
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    std::vector<int> data = {38, 27, 43, 3, 9, 82, 10};

    std::cout << "До сортировки: ";
    for (int val : data) std::cout << val << " ";
    std::cout << "\n";

    mergeSort(data, 0, data.size() - 1);

    std::cout << "После сортировки: ";
    for (int val : data) std::cout << val << " ";
    std::cout << "\n";

    return 0;
}
