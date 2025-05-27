#include <iostream>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

void fillContainer(multimap<int,double>& c) {
    c.insert({1, 1.1});
    c.insert({2, 2.2});
    c.insert({3, 3.3});
    c.insert({4, 4.4});
    c.insert({5, 5.5});
}

void addMaxElement(multimap<int,double>& c) {
    if (c.empty()) return;
    auto max_it = max_element(c.begin(), c.end(),
        [](auto& a, auto& b) { return a.second < b.second; });
    int min_key = c.begin()->first;
    int new_key = min_key - 1;
    c.insert({new_key, max_it->second});
}

void removeMinElement(multimap<int,double>& c) {
    if (c.empty()) return;
    auto min_it = min_element(c.begin(), c.end(),
        [](auto& a, auto& b) { return a.second < b.second; });
    if(min_it != c.end())
        c.erase(min_it->first);
}

void addAverage(multimap<int,double>& c) {
    if (c.empty()) return;
    double sum = accumulate(c.begin(), c.end(), 0.0,
        [](double acc, auto& p){ return acc + p.second; });
    double avg = sum / c.size();

    for(auto& [key,val] : c) {
        val += avg;
    }
}

void print(const multimap<int,double>& c) {
    for (const auto& [k,v] : c) {
        cout << "[" << k << "] = " << v << "\n";
    }
}
