#include <iostream>

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        std::cout << "Переместить диск 1 с " << from << " на " << to << std::endl;
        return;
    }
    hanoi(n - 1, from, aux, to);
    std::cout << "Переместить диск " << n << " с " << from << " на " << to << std::endl;
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    std::cout << "Введите количество дисков: ";
    std::cin >> n;
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
