#pragma once
#include "Person.h"
#include "Vector.h"

class Student : public Person {
public:
    Student() : Person(), rating(0.0f) {}
    Student(string n, int a, float r) : Person(n, a), rating(r) {}
    Student(const Student& s) : Person(s), rating(s.rating), group(s.group) {}
    ~Student() {}

    void SetRating(float r) { rating = r; }
    float GetRating() const { return rating; }

    void Show() override {
        Person::Show();
        cout << "Rating: " << rating << "\n";
    }
    void Input() override {
        Person::Input();
        cout << "Rating: "; cin >> rating;
    }

    void HandleEvent(const TEvent& e) override {
        if (e.what == evMessage && e.command == cmGet) {
            cout << "Student Name: " << name << ", Age: " << age << ", Rating: " << rating << "\n";
        }
    }

private:
    float rating;
    Vector* group = nullptr;
};
