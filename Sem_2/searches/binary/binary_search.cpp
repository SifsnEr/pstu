#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& data, int target) {
    int left = 0;
    int right = static_cast<int>(data.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (data[mid] == target)
            return mid;
        else if (data[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    int target = 7;

    int index = binarySearch(arr, target);

    if (index != -1)
        std::cout << "Бинарный поиск: элемент " << target << " найден на позиции " << index << '\n';
    else
        std::cout << "Бинарный поиск: элемент не найден\n";

    return 0;
}
