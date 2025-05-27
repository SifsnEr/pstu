#include "Fraction.h"

Fraction::Fraction() : Pair(), integerPart(0), fractionalPart(0) {}

Fraction::Fraction(int f, int s, int i, int frac) : Pair(f, s), integerPart(i), fractionalPart(frac) {}

Fraction::Fraction(const Fraction& fr) : Pair(fr.first, fr.second), integerPart(fr.integerPart), fractionalPart(fr.fractionalPart) {}

Fraction::~Fraction() {}

int Fraction::getIntegerPart() const { return integerPart; }

int Fraction::getFractionalPart() const { return fractionalPart; }

void Fraction::setIntegerPart(int i) { integerPart = i; }

void Fraction::setFractionalPart(int frac) { fractionalPart = frac; }

bool Fraction::operator==(const Fraction& fr) const {
    return (first == fr.first && second == fr.second && integerPart == fr.integerPart && fractionalPart == fr.fractionalPart);
}

bool Fraction::operator!=(const Fraction& fr) const {
    return !(*this == fr);
}

bool Fraction::operator<(const Fraction& fr) const {
    if (integerPart < fr.integerPart) return true;
    if (integerPart == fr.integerPart && fractionalPart < fr.fractionalPart) return true;
    if (integerPart == fr.integerPart && fractionalPart == fr.fractionalPart)
        return (first < fr.first) || (first == fr.first && second < fr.second);
    return false;
}

bool Fraction::operator<=(const Fraction& fr) const {
    return *this < fr || *this == fr;
}

bool Fraction::operator>(const Fraction& fr) const {
    return !(*this <= fr);
}

bool Fraction::operator>=(const Fraction& fr) const {
    return !(*this < fr);
}

Fraction& Fraction::operator=(const Fraction& fr) {
    if (this == &fr) return *this;
    first = fr.first;
    second = fr.second;
    integerPart = fr.integerPart;
    fractionalPart = fr.fractionalPart;
    return *this;
}

istream& operator>>(istream& in, Fraction& fr) {
    cout << "First: "; in >> fr.first;
    cout << "Second: "; in >> fr.second;
    cout << "Integer part: "; in >> fr.integerPart;
    cout << "Fractional part: "; in >> fr.fractionalPart;
    return in;
}

ostream& operator<<(ostream& out, const Fraction& fr) {
    out << "Pair: (" << fr.first << ", " << fr.second << "), Integer: " << fr.integerPart << ", Fractional: " << fr.fractionalPart;
    return out;
}
