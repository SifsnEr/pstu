#pragma once
#include "Time.h"
#include <iostream>
#include <fstream>
using namespace std;

int make_file(const char* f_name) {
    fstream stream(f_name, ios::out | ios::trunc);
    if (!stream) return -1;

    int n; cout << "N? "; cin >> n;
    Time t;
    for (int i = 0; i < n; i++) {
        cout << "Time (mm:ss)? ";
        cin >> t;
        stream << t;
    }
    stream.close();
    return n;
}

int print_file(const char* f_name) {
    fstream stream(f_name, ios::in);
    if (!stream) return -1;

    Time t;
    int count = 0;
    while (stream >> t) {
        cout << t << "\n";
        count++;
    }
    stream.close();
    return count;
}

int del_file(const char* f_name, Time val) {
    fstream stream(f_name, ios::in);
    if (!stream) return -1;
    fstream temp("temp", ios::out);

    Time t;
    int count = 0;
    while (stream >> t) {
        if (!(t == val)) {
            temp << t;
        } else {
            count++;
        }
    }

    stream.close();
    temp.close();
    remove(f_name);
    rename("temp", f_name);
    return count; // количество удалённых
}

int add_end(const char* f_name, Time t) {
    fstream stream(f_name, ios::app);
    if (!stream) return -1;
    stream << t;
    stream.close();
    return 1;
}

int add_file(const char* f_name, int k, Time t) {
    fstream stream(f_name, ios::in);
    if (!stream) return -1;
    fstream temp("temp", ios::out);

    Time curr;
    int i = 0, added = 0;
    while (stream >> curr) {
        i++;
        temp << curr;
        if (i == k) {
            temp << t;
            added++;
        }
    }
    stream.close();
    temp.close();

    remove(f_name);
    rename("temp", f_name);

    return added;
}

int increase_time(const char* f_name, Time val) {
    fstream stream(f_name, ios::in);
    if (!stream) return -1;
    fstream temp("temp", ios::out);

    Time t;
    int count = 0;
    Time add(1, 30);
    while (stream >> t) {
        if (t == val) {
            t = t + add;
            count++;
        }
        temp << t;
    }

    stream.close();
    temp.close();
    remove(f_name);
    rename("temp", f_name);

    return count;
}
