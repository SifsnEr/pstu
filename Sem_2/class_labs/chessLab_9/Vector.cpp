#include "Vector.h"

Vector::Vector(int s) {
    if(s > MAX_SIZE) throw error("Vector length more than MAX_SIZE\n");
    size = s;
    beg = new int[size];
    for(int i = 0; i < size; i++)
        beg[i] = 0;
}

Vector::Vector(const Vector &v) {
    size = v.size;
    beg = new int[size];
    for(int i = 0; i < size; i++)
        beg[i] = v.beg[i];
}

Vector::~Vector() {
    if (beg != nullptr) delete[] beg;
}

const Vector& Vector::operator=(const Vector &v) {
    if(this == &v) return *this;
    if(beg != nullptr) delete[] beg;
    size = v.size;
    beg = new int[size];
    for(int i = 0; i < size; i++)
        beg[i] = v.beg[i];
    return *this;
}

int Vector::operator[](int i) {
    if(i < 0) throw error("Index < 0");
    if(i >= size) throw error("Index >= size");
    return beg[i];
}

Vector Vector::operator+(int a) {
    Vector temp(size);
    for(int i = 0; i < size; i++)
        temp.beg[i] = beg[i] + a;
    return temp;
}

Vector Vector::operator-(int n) {
    if(n > size) throw error("Remove count greater than vector size");
    Vector temp(size - n);
    for(int i = 0; i < size - n; i++)
        temp.beg[i] = beg[i];
    return temp;
}

ostream& operator<<(ostream& out, const Vector& v) {
    if(v.size == 0) out << "Empty\n";
    else {
        for(int i = 0; i < v.size; i++)
            out << v.beg[i] << " ";
        out << endl;
    }
    return out;
}
