#include "Pair.h"

Pair::Pair() : first(0), second(0) {}

Pair::Pair(int f, int s) : first(f), second(s) {}

Pair::Pair(const Pair& p) : first(p.first), second(p.second) {}

Pair::~Pair() {}

int Pair::getFirst() const { return first; }

int Pair::getSecond() const { return second; }

void Pair::setFirst(int f) { first = f; }

void Pair::setSecond(int s) { second = s; }

bool Pair::operator>(const Pair& p) const {
    return (first > p.first) || (first == p.first && second > p.second);
}

Pair& Pair::operator=(const Pair& p) {
    if (this == &p) return *this;
    first = p.first;
    second = p.second;
    return *this;
}

istream& operator>>(istream& in, Pair& p) {
    cout << "First: "; in >> p.first;
    cout << "Second: "; in >> p.second;
    return in;
}

ostream& operator<<(ostream& out, const Pair& p) {
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}
