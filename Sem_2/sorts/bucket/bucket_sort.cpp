#include <iostream>
#include <vector>
#include <algorithm>

void bucketSort(std::vector<float>& arr) {
    int n = arr.size();
    if (n <= 0) return;

    std::vector<std::vector<float>> buckets(n);

    for (int i = 0; i < n; ++i) {
        int index = n * arr[i];
        buckets[index].push_back(arr[i]);
    }

    for (int i = 0; i < n; ++i) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    int idx = 0;
    for (int i = 0; i < n; ++i) {
        for (float value : buckets[i]) {
            arr[idx++] = value;
        }
    }
}

int main() {
    std::vector<float> data = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};

    std::cout << "До сортировки: ";
    for (float val : data) std::cout << val << " ";
    std::cout << "\n";

    bucketSort(data);

    std::cout << "После сортировки: ";
    for (float val : data) std::cout << val << " ";
    std::cout << "\n";

    return 0;
}
