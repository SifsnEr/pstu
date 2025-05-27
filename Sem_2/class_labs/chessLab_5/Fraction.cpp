#include "Fraction.h"

Fraction::Fraction() : Pair() {}
Fraction::Fraction(int w, int f) : Pair(w, f) {}
Fraction::Fraction(const Fraction& fr) : Pair(fr.first, fr.second) {}
Fraction::~Fraction() {}

void Fraction::SetWhole(int w) { first = w; }
void Fraction::SetFrac(int f) { second = f; }
int Fraction::GetWhole() const { return first; }
int Fraction::GetFrac() const { return second; }

Fraction& Fraction::operator=(const Fraction& fr) {
    if (this == &fr) return *this;
    first = fr.first;
    second = fr.second;
    return *this;
}
bool Fraction::operator==(const Fraction& fr) const { return Pair::operator==(fr); }
bool Fraction::operator>(const Fraction& fr) const { return Pair::operator>(fr); }
bool Fraction::operator<(const Fraction& fr) const { return Pair::operator<(fr); }
bool Fraction::operator>=(const Fraction& fr) const { return Pair::operator>=(fr); }
bool Fraction::operator<=(const Fraction& fr) const { return Pair::operator<=(fr); }
bool Fraction::operator!=(const Fraction& fr) const { return Pair::operator!=(fr); }

istream& operator>>(istream& in, Fraction& fr) {
    cout << "Whole: "; in >> fr.first;
    cout << "Fraction: "; in >> fr.second;
    return in;
}
ostream& operator<<(ostream& out, const Fraction& fr) {
    out << "Whole: " << fr.first << ", Fraction: " << fr.second << endl;
    return out;
}
void Fraction::Show() {
    cout << *this;
}
