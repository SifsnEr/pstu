#pragma once
#include "Pair.h"
class Fraction : public Pair {
public:
    Fraction();
    Fraction(int, int);
    Fraction(const Fraction&);
    ~Fraction();

    void SetWhole(int);
    void SetFrac(int);
    int GetWhole() const;
    int GetFrac() const;

    Fraction& operator=(const Fraction&);
    bool operator==(const Fraction&) const;
    bool operator>(const Fraction&) const;
    bool operator<(const Fraction&) const;
    bool operator>=(const Fraction&) const;
    bool operator<=(const Fraction&) const;
    bool operator!=(const Fraction&) const;

    friend istream& operator>>(istream&, Fraction&);
    friend ostream& operator<<(ostream&, const Fraction&);

    void Show() override;
};