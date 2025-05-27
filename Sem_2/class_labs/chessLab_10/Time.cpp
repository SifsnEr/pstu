#include "Time.h"

Time::Time() : minutes(0), seconds(0) {}
Time::Time(int m, int s) {
    minutes = m + s / 60;
    seconds = s % 60;
}
Time::Time(const Time& t) {
    minutes = t.minutes;
    seconds = t.seconds;
}

Time Time::operator+(const Time& t) const {
    int total_sec = (minutes + t.minutes) * 60 + (seconds + t.seconds);
    return Time(total_sec / 60, total_sec % 60);
}

bool Time::operator==(const Time& t) const {
    return (minutes == t.minutes && seconds == t.seconds);
}

ostream& operator<<(ostream& out, const Time& t) {
    out << t.minutes << ":" << (t.seconds < 10 ? "0" : "") << t.seconds;
    return out;
}

istream& operator>>(istream& in, Time& t) {
    int m, s;
    char sep;
    in >> m >> sep >> s;
    if (sep != ':') {
        in.setstate(ios::failbit);
        return in;
    }
    t.minutes = m + s / 60;
    t.seconds = s % 60;
    return in;
}

fstream& operator>>(fstream& fin, Time& t) {
    fin >> t.minutes >> t.seconds;
    return fin;
}

fstream& operator<<(fstream& fout, const Time& t) {
    fout << t.minutes << " " << t.seconds << "\n";
    return fout;
}
