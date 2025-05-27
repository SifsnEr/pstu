#include <iostream>
#include <string>
using namespace std;

class Student {
    string FIO;
    string group;
    float avg_mark;
public:
    Student();
    Student(string, string, float);
    Student(const Student&);
    ~Student();

    string get_FIO();
    void set_FIO(string);

    string get_group();
    void set_group(string);

    float get_avg_mark();
    void set_avg_mark(float);

    void show() const;
};
