#pragma once
#include <iostream>

class Time {
    int hours;
    int minutes;
    int seconds;

public:
    Time();
    Time(int h, int m, int s);
    Time(const Time& t);

    Time operator+(const Time& t) const;
    Time operator/(int divisor) const;
    bool operator>(const Time& t) const;
    bool operator<(const Time& t) const;
    bool operator==(const Time& t) const;
    Time operator/(const Time& t) const;

    friend std::istream& operator>>(std::istream& in, Time& t);
    friend std::ostream& operator<<(std::ostream& out, const Time& t);
};
