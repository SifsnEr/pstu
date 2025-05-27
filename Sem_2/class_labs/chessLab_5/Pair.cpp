#include "Pair.h"

Pair::Pair() : first(0), second(0) {}
Pair::Pair(int f, int s) : first(f), second(s) {}
Pair::Pair(const Pair& p) : first(p.first), second(p.second) {}
Pair::~Pair() {}

void Pair::SetFirst(int f) { first = f; }
void Pair::SetSecond(int s) { second = s; }
int Pair::GetFirst() const { return first; }
int Pair::GetSecond() const { return second; }

Pair& Pair::operator=(const Pair& p) {
    if (this == &p) return *this;
    first = p.first;
    second = p.second;
    return *this;
}

bool Pair::operator>(const Pair& p) const {
    return (first > p.first) || (first == p.first && second > p.second);
}
bool Pair::operator==(const Pair& p) const {
    return (first == p.first && second == p.second);
}
bool Pair::operator<(const Pair& p) const {
    return !(*this >= p);
}
bool Pair::operator>=(const Pair& p) const {
    return (*this > p) || (*this == p);
}
bool Pair::operator<=(const Pair& p) const {
    return !(*this > p);
}
bool Pair::operator!=(const Pair& p) const {
    return !(*this == p);
}

istream& operator>>(istream& in, Pair& p) {
    cout << "First: "; in >> p.first;
    cout << "Second: "; in >> p.second;
    return in;
}
ostream& operator<<(ostream& out, const Pair& p) {
    out << "First: " << p.first << ", Second: " << p.second << endl;
    return out;
}
void Pair::Show() {
    cout << *this;
}