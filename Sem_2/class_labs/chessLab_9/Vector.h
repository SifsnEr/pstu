#pragma once
#include <iostream>
#include "error.h"
using namespace std;

const int MAX_SIZE=20;

class Vector {
    int size;
    int *beg;
public:
    Vector() : size(0), beg(nullptr) {}
    Vector(int s);
    Vector(const Vector &v);
    ~Vector();
    const Vector& operator=(const Vector &v);

    int operator[](int i);
    int operator()() { return size; }
    Vector operator+(int a);
    Vector operator-(int n);

    friend ostream& operator<<(ostream& out, const Vector& v);
};
