#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class Vector {
public:
    Vector();
    Vector(int);
    ~Vector();
    void Add(Object*);
    friend ostream& operator<<(ostream&, const Vector&);
private:
    Object** beg;
    int size;
    int cur;
};