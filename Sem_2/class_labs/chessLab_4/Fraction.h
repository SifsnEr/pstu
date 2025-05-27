#pragma once
#include "Pair.h"

class Fraction : public Pair {
    int integerPart;
    int fractionalPart;
public:
    Fraction();
    Fraction(int f, int s, int i, int frac);
    Fraction(const Fraction& fr);
    ~Fraction();

    int getIntegerPart() const;
    int getFractionalPart() const;
    void setIntegerPart(int i);
    void setFractionalPart(int frac);

    bool operator==(const Fraction& fr) const;
    bool operator!=(const Fraction& fr) const;
    bool operator<(const Fraction& fr) const;
    bool operator<=(const Fraction& fr) const;
    bool operator>(const Fraction& fr) const;
    bool operator>=(const Fraction& fr) const;

    Fraction& operator=(const Fraction& fr);

    friend istream& operator>>(istream& in, Fraction& fr);
    friend ostream& operator<<(ostream& out, const Fraction& fr);
};
