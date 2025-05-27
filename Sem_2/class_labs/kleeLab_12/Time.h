#pragma once
#include <iostream>
using namespace std;

class Time {
private:
    int hour;
    int min;
    int sec;

    void normalize() {
        if (sec >= 60) {
            min += sec / 60;
            sec %= 60;
        }
        if (min >= 60) {
            hour += min / 60;
            min %= 60;
        }
        if (hour < 0 || min < 0 || sec < 0) {
            hour = min = sec = 0;
        }
    }
public:
    Time(int h=0, int m=0, int s=0) : hour(h), min(m), sec(s) {
        normalize();
    }

    friend Time operator+(const Time& a, const Time& b) {
        return Time(a.hour + b.hour, a.min + b.min, a.sec + b.sec);
    }

    friend Time operator/(const Time& t, int divisor) {
        int total_sec = t.hour * 3600 + t.min * 60 + t.sec;
        total_sec /= divisor;
        return Time(total_sec / 3600, (total_sec % 3600) / 60, total_sec % 60);
    }

    friend bool operator<(const Time& a, const Time& b) {
        if (a.hour != b.hour) return a.hour < b.hour;
        if (a.min != b.min) return a.min < b.min;
        return a.sec < b.sec;
    }

    friend std::ostream& operator<<(std::ostream& os, const Time& t) {
        os << t.hour << ":" << t.min << ":" << t.sec;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Time& t) {
        is >> t.hour >> t.min >> t.sec;
        t.normalize();
        return is;
    }
};
