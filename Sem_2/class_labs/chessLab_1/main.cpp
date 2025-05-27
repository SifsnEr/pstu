#include <iostream>
#include "fraction.h"

fraction make_fraction(int n, int d)
{
    fraction t;
    t.Init(n, d);
    return t;
}

int main()
{
    try
    {
        fraction A, B;
        A.Init(7, 3);
        B.Read();

        A.Show();
        std::cout << "A.ipart() = " << A.ipart() << '\n';

        B.Show();
        std::cout << "B.ipart() = " << B.ipart() << '\n';

        fraction* X = new fraction;
        X->Init(10, 4);
        X->Show();
        std::cout << "X.ipart() = " << X->ipart() << '\n';
        delete X;

        fraction mas[3];
        for (auto& f : mas) f.Read();
        for (const auto& f : mas)
            std::cout << "ipart(" << f.first << '/' << f.second << ") = "
                      << f.ipart() << '\n';

        fraction* p_mas = new fraction[3];
        for (int i = 0; i < 3; ++i) p_mas[i].Read();
        for (int i = 0; i < 3; ++i)
            std::cout << "ipart(" << p_mas[i].first << '/' << p_mas[i].second << ") = "
                      << p_mas[i].ipart() << '\n';
        delete[] p_mas;

        int y, z;
        std::cout << "\nNew fraction:\nNumerator?  "; std::cin >> y;
        std::cout << "Denominator? "; std::cin >> z;
        fraction F = make_fraction(y, z);
        F.Show();
        std::cout << "F.ipart() = " << F.ipart() << '\n';
    }
    catch (const std::exception& ex)
    {
        std::cerr << "\nError: " << ex.what() << '\n';
        return 1;
    }
    return 0;
}
