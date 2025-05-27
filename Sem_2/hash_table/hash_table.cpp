#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <random>
#include <ctime>
#include <algorithm>

struct Record {
    std::string fio;
    std::string group;
    double rating;
};

class HashTable {
private:
    std::vector<std::list<Record>> table;
    int collisions = 0;
    int size;

    int hash(const std::string& key) const {
        unsigned int sum = 0;
        for (char c : key) sum += (unsigned char)c;
        return sum % size;
    }

public:
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size);
    }

    void insert(const Record& rec) {
        int idx = hash(rec.fio);
        if (!table[idx].empty()) collisions++;
        table[idx].push_back(rec);
    }

    bool remove(const std::string& fio) {
        int idx = hash(fio);
        auto& chain = table[idx];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->fio == fio) {
                chain.erase(it);
                return true;
            }
        }
        return false;
    }

    Record* find(const std::string& fio) {
        int idx = hash(fio);
        for (auto& rec : table[idx]) {
            if (rec.fio == fio) return &rec;
        }
        return nullptr;
    }

    int getCollisions() const {
        return collisions;
    }

    void clear() {
        for (auto& chain : table) {
            chain.clear();
        }
        collisions = 0;
    }
};

std::string randomFIO() {
    static const std::vector<std::string> names = {
        "Иванов И.И.", "Петров П.П.", "Сидоров С.С.",
        "Кузнецов К.К.", "Смирнов С.В.", "Попов П.П."
    };
    static std::mt19937 gen((unsigned)time(nullptr));
    std::uniform_int_distribution<> dist(0, (int)names.size()-1);
    return names[dist(gen)];
}

std::string randomGroup() {
    static const std::vector<std::string> groups = {"A1", "B2", "C3", "D4", "E5"};
    static std::mt19937 gen((unsigned)time(nullptr)+1);
    std::uniform_int_distribution<> dist(0, (int)groups.size()-1);
    return groups[dist(gen)];
}

double randomRating() {
    static std::mt19937 gen((unsigned)time(nullptr)+2);
    std::uniform_real_distribution<> dist(1.0, 5.0);
    return dist(gen);
}

void saveToFile(const std::vector<Record>& arr, const std::string& filename) {
    std::ofstream ofs(filename);
    for (const auto& r : arr) {
        ofs << r.fio << ';' << r.group << ';' << r.rating << '\n';
    }
}

void loadFromFile(std::vector<Record>& arr, const std::string& filename) {
    arr.clear();
    std::ifstream ifs(filename);
    std::string line;
    while (std::getline(ifs, line)) {
        size_t pos1 = line.find(';');
        size_t pos2 = line.rfind(';');
        if (pos1 == std::string::npos || pos2 == pos1) continue;
        Record r;
        r.fio = line.substr(0, pos1);
        r.group = line.substr(pos1 + 1, pos2 - pos1 -1);
        r.rating = std::stod(line.substr(pos2 + 1));
        arr.push_back(r);
    }
}

int main() {
    std::vector<Record> records;

    for (int i = 0; i < 100; ++i) {
        records.push_back({randomFIO(), randomGroup(), randomRating()});
    }

    saveToFile(records, "records.txt");
    records.clear();
    loadFromFile(records, "records.txt");

    for (int tableSize : {40, 75, 90}) {
        HashTable ht(tableSize);
        ht.clear();

        for (const auto& rec : records) {
            ht.insert(rec);
        }

        std::cout << "Размер хэш-таблицы: " << tableSize
                  << ", коллизий: " << ht.getCollisions() << "\n";
    }

    if (!records.empty()) {
        HashTable ht(75);
        for (const auto& r : records) ht.insert(r);

        std::string key = records[0].fio;
        Record* found = ht.find(key);
        if (found) {
            std::cout << "Найден: " << found->fio << ", группа: " << found->group
                      << ", рейтинг: " << found->rating << "\n";
        } else {
            std::cout << "Элемент не найден\n";
        }
    }

    return 0;
}
