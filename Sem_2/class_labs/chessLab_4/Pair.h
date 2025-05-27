#pragma once
#include <iostream>
using namespace std;

class Pair {
protected:
    int first;
    int second;
public:
    Pair();
    Pair(int f, int s);
    Pair(const Pair& p);
    ~Pair();

    int getFirst() const;
    int getSecond() const;
    void setFirst(int f);
    void setSecond(int s);

    bool operator>(const Pair& p) const;
    Pair& operator=(const Pair& p);

    friend istream& operator>>(istream& in, Pair& p);
    friend ostream& operator<<(ostream& out, const Pair& p);
};
