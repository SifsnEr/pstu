#include <iostream>
#include <vector>

int interpolationSearch(const std::vector<int>& data, int target) {
    int low = 0;
    int high = static_cast<int>(data.size()) - 1;

    while (low <= high && target >= data[low] && target <= data[high]) {
        if (low == high) {
            if (data[low] == target) return low;
            return -1;
        }

        int pos = low + ((target - data[low]) * (high - low)) / (data[high] - data[low]);

        if (data[pos] == target)
            return pos;
        if (data[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}

int main() {
    std::vector<int> arr = {10, 20, 30, 40, 50, 60, 70};
    int target = 40;

    int index = interpolationSearch(arr, target);

    if (index != -1)
        std::cout << "Интерполяционный поиск: элемент " << target << " найден на позиции " << index << '\n';
    else
        std::cout << "Интерполяционный поиск: элемент не найден\n";

    return 0;
}
