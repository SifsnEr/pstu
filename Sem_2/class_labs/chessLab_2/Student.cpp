#include "Student.h"

Student::Student() : FIO(""), group(""), avg_mark(0.0f) {}

Student::Student(string f, string g, float m) : FIO(f), group(g), avg_mark(m) {}

Student::Student(const Student& s) : FIO(s.FIO), group(s.group), avg_mark(s.avg_mark) {}

Student::~Student() {}

string Student::get_FIO() { return FIO; }
void Student::set_FIO(string f) { FIO = f; }

string Student::get_group() { return group; }
void Student::set_group(string g) { group = g; }

float Student::get_avg_mark() { return avg_mark; }
void Student::set_avg_mark(float m) { avg_mark = m; }

void Student::show() const {
    cout << "FIO: " << FIO << endl;
    cout << "Group: " << group << endl;
    cout << "Average mark: " << avg_mark << endl;
}
