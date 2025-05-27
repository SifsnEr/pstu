#pragma once
#include <iostream>
#include <stdexcept>

struct fraction
{
    int first;
    int second;

    void Init(int num, int den);

    void Read();
    void Show() const;

    int ipart() const;
};
