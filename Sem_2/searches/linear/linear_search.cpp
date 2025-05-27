#include <iostream>
#include <vector>

int linearSearch(const std::vector<int>& data, int target) {
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i] == target) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int main() {
    std::vector<int> arr = {10, 23, 45, 70, 11, 5};
    int target = 70;

    int index = linearSearch(arr, target);

    if (index != -1)
        std::cout << "Элемент " << target << " найден на позиции " << index << std::endl;
    else
        std::cout << "Элемент " << target << " не найден." << std::endl;

    return 0;
}
