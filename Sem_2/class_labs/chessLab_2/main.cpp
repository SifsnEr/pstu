#include "Student.h"
#include <iostream>
using namespace std;

Student make_student() {
    string fio, group;
    float mark;
    cout << "Enter FIO: "; cin.ignore(); getline(cin, fio);
    cout << "Enter group: "; getline(cin, group);
    cout << "Enter average mark: "; cin >> mark;
    return Student(fio, group, mark);
}

void print_student(Student s) {
    s.show();
}

int main() {
    Student s1;
    s1.show();

    Student s2("Ivanov Ivan Ivanovich", "CS-101", 4.5f);
    s2.show();

    Student s3 = s2;
    s3.set_FIO("Petrova Anna Sergeevna");
    s3.set_group("CS-102");
    s3.set_avg_mark(4.8f);
    print_student(s3);

    s1 = make_student();
    s1.show();

    return 0;
}
