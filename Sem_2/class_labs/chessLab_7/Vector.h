#include <iostream>
using namespace std;

template <class T>
class Vector {
public:
    Vector(int s, T k);
    Vector(const Vector<T>& a);
    ~Vector();
    Vector<T>& operator=(const Vector<T>& a);
    T& operator[](int index);
    Vector<T> operator+(const T k);
    int operator()();
    friend ostream& operator<< <>(ostream& out, const Vector<T>& a);
    friend istream& operator>> <>(istream& in, Vector<T>& a);
private:
    int size;
    T* data;
};

template <class T>
Vector<T>::Vector(int s, T k) {
    size = s;
    data = new T[size];
    for (int i = 0; i < size; i++)
        data[i] = k;
}

template <class T>
Vector<T>::Vector(const Vector<T>& a) {
    size = a.size;
    data = new T[size];
    for (int i = 0; i < size; i++)
        data[i] = a.data[i];
}

template <class T>
Vector<T>::~Vector() {
    delete[] data;
    data = nullptr;
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& a) {
    if (this == &a) return *this;
    if (data != nullptr) delete[] data;
    size = a.size;
    data = new T[size];
    for (int i = 0; i < size; i++)
        data[i] = a.data[i];
    return *this;
}

template <class T>
T& Vector<T>::operator[](int index) {
    if (index < size) return data[index];
    else {
        cout << "\nError! Index>size";
        return data[0];
    }
}

template <class T>
Vector<T> Vector<T>::operator+(const T k) {
    Vector<T> temp(size, k);
    for (int i = 0; i < size; ++i)
        temp.data[i] = data[i] + k;
    return temp;
}

template <class T>
int Vector<T>::operator()() {
    return size;
}

template <class T>
ostream& operator<<(ostream& out, const Vector<T>& a) {
    for (int i = 0; i < a.size; ++i)
        out << a.data[i] << " ";
    return out;
}

template <class T>
istream& operator>>(istream& in, Vector<T>& a) {
    for (int i = 0; i < a.size; ++i)
        in >> a.data[i];
    return in;
}
