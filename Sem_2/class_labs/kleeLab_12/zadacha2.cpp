#include <iostream>
#include <map>
#include <algorithm>
#include <numeric>
#include "Time.h"
using namespace std;

void fillContainer(multimap<int, Time>& c) {
    c.insert({1, Time(1,10,30)});
    c.insert({2, Time(2,20,40)});
    c.insert({3, Time(0,30,50)});
    c.insert({4, Time(3,40,10)});
    c.insert({5, Time(0,50,20)});
}

void addMaxElement(multimap<int, Time>& c) {
    if (c.empty()) return;
    auto max_it = max_element(c.begin(), c.end(),
        [](auto& a, auto& b) { return a.second < b.second; });
    int min_key = c.begin()->first;
    int new_key = min_key - 1;
    c.insert({new_key, max_it->second});
}

void removeMinElement(multimap<int, Time>& c) {
    if (c.empty()) return;
    auto min_it = min_element(c.begin(), c.end(),
        [](auto& a, auto& b) { return a.second < b.second; });
    if(min_it != c.end())
        c.erase(min_it->first);
}

void addAverage(multimap<int, Time>& c) {
    if (c.empty()) return;
    Time sum;
    for(const auto& [k,v] : c) sum = sum + v;
    Time avg = sum / static_cast<int>(c.size());
    for(auto& [k,v] : c) {
        v = v + avg;
    }
}

void print(const multimap<int, Time>& c) {
    for (const auto& [k,v] : c) {
        cout << "[" << k << "] = " << v << "\n";
    }
}
