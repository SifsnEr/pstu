#include "fraction.h"

static void ensure_positive(int value, const char* name)
{
    if (value <= 0)
        throw std::invalid_argument(std::string(name) + " must be > 0");
}

void fraction::Init(int num, int den)
{
    ensure_positive(num, "Numerator");
    ensure_positive(den, "Denominator");
    first  = num;
    second = den;
}

void fraction::Read()
{
    std::cout << "\nNumerator  (positive int)? ";  std::cin >> first;
    std::cout << "Denominator(positive int)? ";   std::cin >> second;
    ensure_positive(first , "Numerator");
    ensure_positive(second, "Denominator");
}

void fraction::Show() const
{
    std::cout << "\nFraction: " << first << '/' << second << '\n';
}

int fraction::ipart() const
{
    if (second == 0)
        throw std::overflow_error("Division by zero!");

    return first / second;
}
