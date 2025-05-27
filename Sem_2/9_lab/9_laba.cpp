#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

int main() {
    std::string file1 = "F1.txt";
    std::string file2 = "F2.txt";

    std::ofstream outF1(file1);
    if (!outF1) {
        std::cerr << "Ошибка при создании файла F1\n";
        return 1;
    }

    for (int i = 1; i <= 10; ++i) {
        outF1 << "Это строка номер " << i << std::endl;
    }
    outF1.close();

    std::ifstream inF1(file1);
    std::ofstream outF2(file2);
    if (!inF1 || !outF2) {
        std::cerr << "Ошибка при открытии файлов\n";
        return 1;
    }

    std::string line;
    int lineNumber = 1;
    while (std::getline(inF1, line)) {
        if (lineNumber % 2 == 0) {
            outF2 << line << std::endl;
        }
        ++lineNumber;
    }
    inF1.close();
    outF2.close();

    std::uintmax_t sizeF1 = std::filesystem::file_size(file1);
    std::uintmax_t sizeF2 = std::filesystem::file_size(file2);

    std::cout << "Размер файла F1: " << sizeF1 << " байт\n";
    std::cout << "Размер файла F2: " << sizeF2 << " байт\n";

    return 0;
}
