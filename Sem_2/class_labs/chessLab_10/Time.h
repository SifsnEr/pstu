#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Time {
public:
    Time();
    Time(int m, int s);
    Time(const Time& t);

    Time operator+(const Time& t) const;
    bool operator==(const Time& t) const;

    friend ostream& operator<<(ostream& out, const Time& t);
    friend istream& operator>>(istream& in, Time& t);

    friend fstream& operator>>(fstream& fin, Time& t);
    friend fstream& operator<<(fstream& fout, const Time& t);

private:
    int minutes;
    int seconds;
};
