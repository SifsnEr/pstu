#include <iostream>

int main()
{
    float a, b;
    int c;
    std::cout << "Enter two numbers: " << std::endl;
    std::cin >> a >> b;
    std::cout << "Enter code of operation you want to do: " << std::endl;
    std::cin >> c;
    switch(c)
    {
        case 1:
            std::cout << a + b << std::endl;
            break;
        case 2:
            std::cout << a - b << std::endl;
            break;
        case 3:
            std::cout << a * b << std::endl;
            break;
        case 4:
            if (b != 0)
            {
                std::cout << a / b << std::endl;
                break;
            }
            else
            {
                std::cout << "A Tbl yMeH..." << std::endl;
                break;
            }
        default:
            std::cout << "Invalid operation code" << std::endl;
    }
    return 0;
}