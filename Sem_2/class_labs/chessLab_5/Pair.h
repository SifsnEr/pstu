#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class Pair : public Object {
protected:
    int first;
    int second;
public:
    Pair();
    Pair(int, int);
    Pair(const Pair&);
    virtual ~Pair();

    void SetFirst(int);
    void SetSecond(int);

    int GetFirst() const;
    int GetSecond() const;

    Pair& operator=(const Pair&);
    bool operator>(const Pair&) const;
    bool operator==(const Pair&) const;
    bool operator<(const Pair&) const;
    bool operator>=(const Pair&) const;
    bool operator<=(const Pair&) const;
    bool operator!=(const Pair&) const;

    friend istream& operator>>(istream&, Pair&);
    friend ostream& operator<<(ostream&, const Pair&);

    void Show() override;
};