#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

class Time {
public:
    int hour, min, sec;
    Time(int h=0,int m=0,int s=0): hour(h), min(m), sec(s) { normalize(); }
    void normalize() {
        if (sec >= 60) { min += sec / 60; sec %= 60; }
        if (min >= 60) { hour += min / 60; min %= 60; }
        if (hour < 0 || min < 0 || sec < 0) hour = min = sec = 0;
    }
    Time operator+(const Time& t) const {
        return Time(hour+t.hour, min+t.min, sec+t.sec);
    }
    Time& operator+=(const Time& t) {
        hour += t.hour; min += t.min; sec += t.sec;
        normalize();
        return *this;
    }
    Time operator/(int d) const {
        int tot = hour*3600 + min*60 + sec;
        tot /= d;
        return Time(tot/3600, (tot%3600)/60, tot%60);
    }
    bool operator==(const Time& t) const {
        return hour==t.hour && min==t.min && sec==t.sec;
    }
    bool operator<(const Time& t) const {
        if (hour != t.hour) return hour < t.hour;
        if (min != t.min) return min < t.min;
        return sec < t.sec;
    }
    bool operator>(const Time& t) const { return t < *this; }
    friend ostream& operator<<(ostream& os, const Time& t) {
        os << t.hour << ":" << t.min << ":" << t.sec;
        return os;
    }
};

typedef vector<Time> TVector;
typedef stack<Time> TStack;
typedef multiset<Time> TSet;

void print_vector(const TVector& v) {
    for (auto& e : v) cout << e << endl;
}
void print_stack(TStack s) {
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
}
void print_set(const TSet& s) {
    for (auto& e : s) cout << e << endl;
}

void zadacha1() {
    TVector v = { {1,10,5},{2,20,10},{3,30,15},{4,40,20},{5,50,25} };
    auto max_it = max_element(v.begin(), v.end());
    if (max_it != v.end())
        replace(v.begin(), v.end(), *max_it, Time(0,0,0));
    sort(v.begin(), v.end());
    print_vector(v);
    cout << "---\n";
    sort(v.begin(), v.end(), greater<Time>());
    print_vector(v);
    cout << "---\n";
    Time target(3,30,15);
    auto found = find(v.begin(), v.end(), target);
    if (found != v.end())
        cout << "Found: " << *found << "\n";
    else
        cout << "Not found\n";
}

void zadacha2() {
    TStack s;
    s.push(Time(5,0,0));
    s.push(Time(2,15,0));
    s.push(Time(3,30,0));
    s.push(Time(1,45,0));
    s.push(Time(4,0,0));

    vector<Time> temp;
    while (!s.empty()) {
        temp.push_back(s.top());
        s.pop();
    }
    auto min_it = min_element(temp.begin(), temp.end());
    if (min_it != temp.end()) {
        temp.erase(min_it);
    }
    for (auto& t : temp) s.push(t);

    print_stack(s);
}

void zadacha3() {
    TSet s = { {1,0,0}, {2,0,0}, {3,0,0}, {4,0,0}, {5,0,0} };
    Time sum(0,0,0);
    for (auto& t : s) sum += t;
    Time avg = sum / static_cast<int>(s.size());

    TSet new_s;
    for (auto& t : s) {
        Time new_t(t.hour + avg.hour, t.min + avg.min, t.sec + avg.sec);
        new_s.insert(new_t);
    }
    print_set(new_s);
}

int main() {
    zadacha1();
    cout << "=====\n";
    zadacha2();
    cout << "=====\n";
    zadacha3();
    return 0;
}
