#include "Vector.h"

Vector::Vector(int s, int k) {
    size = s;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = k;
    beg.elem = &data[0];
    end.elem = &data[size];
}

Vector::Vector(const Vector& a) {
    size = a.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = a.data[i];
    beg = a.beg;
    end = a.end;
}

Vector::~Vector() {
    delete[] data;
    data = nullptr;
}

Vector& Vector::operator=(const Vector& a) {
    if (this == &a) return *this;
    if (data != nullptr) delete[] data;
    size = a.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = a.data[i];
    beg = a.beg;
    end = a.end;
    return *this;
}

int& Vector::operator[](int index) {
    if (index < size) return data[index];
    else {
        cout << "\nError! Index>size\n";
        exit(1);
    }
}

Vector Vector::operator+(const int k) {
    Vector temp(size);
    for (int i = 0; i < size; ++i)
        temp.data[i] = data[i] + k;
    return temp;
}

int Vector::operator()() {
    return size;
}

ostream& operator<<(ostream& out, const Vector& a) {
    for (int i = 0; i < a.size; ++i)
        out << a.data[i] << " ";
    return out;
}

istream& operator>>(istream& in, Vector& a) {
    for (int i = 0; i < a.size; ++i)
        in >> a.data[i];
    return in;
}
