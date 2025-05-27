#pragma once
#include <iostream>
#include "event.h"
using namespace std;

class Object {
public:
    virtual ~Object() {}
    virtual void Show() = 0;
    virtual void Input() = 0;
    virtual void HandleEvent(const TEvent& e) = 0;
};

class Vector {
public:
    Vector(int n = 10) {
        size = n;
        cur = 0;
        beg = new Object*[size];
    }
    virtual ~Vector() {
        if (beg) delete[] beg;
        beg = nullptr;
    }
    void Add(Object* p) {
        if (cur < size) {
            beg[cur++] = p;
        }
    }
    void Del() {
        if (cur > 0) cur--;
    }
    void Show() {
        if (cur == 0) {
            cout << "Empty\n";
            return;
        }
        for (int i = 0; i < cur; i++) {
            beg[i]->Show();
        }
    }
    int operator()() {
        return cur;
    }
    void HandleEvent(const TEvent& e) {
        if (e.what == evMessage) {
            for (int i = 0; i < cur; i++) {
                beg[i]->HandleEvent(e);
            }
        }
    }
    Object* Get(int index) {
        if (index >= 0 && index < cur) return beg[index];
        else return nullptr;
    }

private:
    Object** beg;
    int size;
    int cur;
};
