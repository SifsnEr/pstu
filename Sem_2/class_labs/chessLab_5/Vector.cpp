#include "Vector.h"

Vector::Vector() : beg(nullptr), size(0), cur(0) {}
Vector::Vector(int n) : size(n), cur(0) {
    beg = new Object*[n];
}
Vector::~Vector() {
    if (beg) delete[] beg;
    beg = nullptr;
}
void Vector::Add(Object* p) {
    if (cur < size) {
        beg[cur++] = p;
    }
}
ostream& operator<<(ostream& out, const Vector& v) {
    if (v.size == 0) {
        out << "Empty" << endl;
        return out;
    }
    for (int i = 0; i < v.cur; ++i) {
        v.beg[i]->Show();
    }
    return out;
}