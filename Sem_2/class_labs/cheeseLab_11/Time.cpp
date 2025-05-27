#include "Time.h"

Time::Time() : hours(0), minutes(0), seconds(0) {}

Time::Time(int h, int m, int s) {
    hours = h + m / 60 + s / 3600;
    minutes = (m + s / 60) % 60;
    seconds = s % 60;
}

Time::Time(const Time& t) : hours(t.hours), minutes(t.minutes), seconds(t.seconds) {}

Time Time::operator+(const Time& t) const {
    int total_sec = (hours + t.hours) * 3600 + (minutes + t.minutes) * 60 + (seconds + t.seconds);
    return Time(0, 0, total_sec);
}

Time Time::operator/(int divisor) const {
    int total_sec = hours * 3600 + minutes * 60 + seconds;
    total_sec /= divisor;
    return Time(0, 0, total_sec);
}

Time Time::operator/(const Time& t) const {
    int this_sec = hours * 3600 + minutes * 60 + seconds;
    int t_sec = t.hours * 3600 + t.minutes * 60 + t.seconds;
    return Time(0, 0, this_sec / t_sec);
}

bool Time::operator>(const Time& t) const {
    if (hours != t.hours) return hours > t.hours;
    if (minutes != t.minutes) return minutes > t.minutes;
    return seconds > t.seconds;
}

bool Time::operator<(const Time& t) const {
    if (hours != t.hours) return hours < t.hours;
    if (minutes != t.minutes) return minutes < t.minutes;
    return seconds < t.seconds;
}

bool Time::operator==(const Time& t) const {
    return hours == t.hours && minutes == t.minutes && seconds == t.seconds;
}

std::istream& operator>>(std::istream& in, Time& t) {
    in >> t.hours >> t.minutes >> t.seconds;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Time& t) {
    out << t.hours << ":" << t.minutes << ":" << t.seconds;
    return out;
}
