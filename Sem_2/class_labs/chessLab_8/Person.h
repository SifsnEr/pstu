#pragma once
#include <iostream>
#include <string>
#include "event.h"
using namespace std;

class Person {
public:
    Person() : age(0), name("") {}
    Person(string n, int a) : name(n), age(a) {}
    Person(const Person& p) : name(p.name), age(p.age) {}
    virtual ~Person() {}

    void SetName(string n) { name = n; }
    void SetAge(int a) { age = a; }
    string GetName() const { return name; }
    int GetAge() const { return age; }

    virtual void Show() {
        cout << "Name: " << name << "\nAge: " << age << "\n";
    }
    virtual void Input() {
        cout << "Name: "; cin >> name;
        cout << "Age: "; cin >> age;
    }
    virtual void HandleEvent(const TEvent& e) = 0;

protected:
    string name;
    int age;
};
