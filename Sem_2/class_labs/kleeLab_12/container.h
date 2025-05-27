#pragma once
#include <map>
#include <algorithm>
#include <numeric>

template<typename K, typename V>
class Vector {
private:
    std::multimap<K, V> container;
public:
    void fill(const std::initializer_list<std::pair<K, V>>& list) {
        container.insert(list.begin(), list.end());
    }

    void add(const K& key, const V& val) {
        container.insert({key, val});
    }

    void remove(const K& key) {
        container.erase(key);
    }

    void add_max_element_with_new_key() {
        if (container.empty()) return;
        auto max_elem = std::max_element(container.begin(), container.end(),
            [](auto& a, auto& b) { return a.second < b.second; });
        auto min_key = container.begin()->first;
        K new_key = min_key;
        if constexpr(std::is_arithmetic<K>::value)
            new_key = min_key - 1;
        container.insert({ new_key, max_elem->second });
    }

    void remove_min_element() {
        if (container.empty()) return;
        auto min_elem = std::min_element(container.begin(), container.end(),
            [](auto& a, auto& b) { return a.second < b.second; });
        if(min_elem != container.end())
            container.erase(min_elem->first);
    }

    void add_average_to_all() {
        if (container.empty()) return;
        using VT = decltype(container.begin()->second);
        VT sum = std::accumulate(container.begin(), container.end(), VT{},
            [](VT acc, auto& pair) { return acc + pair.second; });
        VT average = sum / static_cast<VT>(container.size());

        for (auto& [key, val] : container) {
            val = val + average;
        }
    }

    template<typename Out>
    void print(Out& os) const {
        for (const auto& [key, val] : container) {
            os << "[" << key << "] = " << val << "\n";
        }
    }
};
