#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> readNumbers(const string& filename) {
    ifstream fin(filename);
    vector<int> numbers;
    int num;
    while (fin >> num) {
        numbers.push_back(num);
    }
    return numbers;
}

void writeNumbers(const string& filename, const vector<int>& numbers) {
    ofstream fout(filename);
    for (int num : numbers) {
        fout << num << ' ';
    }
}

vector<vector<int>> splitIntoRuns(const vector<int>& numbers) {
    vector<vector<int>> runs;
    if (numbers.empty()) return runs;

    vector<int> currentRun = { numbers[0] };
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] >= numbers[i - 1]) {
            currentRun.push_back(numbers[i]);
        } else {
            runs.push_back(currentRun);
            currentRun = { numbers[i] };
        }
    }
    runs.push_back(currentRun);
    return runs;
}

vector<int> mergeTwo(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) result.push_back(a[i++]);
        else result.push_back(b[j++]);
    }
    while (i < a.size()) result.push_back(a[i++]);
    while (j < b.size()) result.push_back(b[j++]);
    return result;
}

void multiPhaseMergeSort(const string& inputFile, const string& outputFile) {
    vector<int> numbers = readNumbers(inputFile);
    if (numbers.empty()) return;

    vector<vector<int>> runs = splitIntoRuns(numbers);

    while (runs.size() > 1) {
        vector<vector<int>> newRuns;
        for (size_t i = 0; i < runs.size(); i += 2) {
            if (i + 1 < runs.size())
                newRuns.push_back(mergeTwo(runs[i], runs[i + 1]));
            else
                newRuns.push_back(runs[i]);
        }
        runs = newRuns;
    }

    if (!runs.empty())
        writeNumbers(outputFile, runs[0]);
}

int main() {
    const string inputFile = "input.txt";
    const string outputFile = "output.txt";

    writeNumbers(inputFile, {17, 1263, 45, 7, 34, 8, 53, 90, 53, 4, 146, 4, 51, 3, 98, -181, 80});

    cout << "Исходные данные: ";
    vector<int> before = readNumbers(inputFile);
    for (int v : before) cout << v << ' ';
    cout << '\n';

    multiPhaseMergeSort(inputFile, outputFile);

    cout << "Отсортированные данные: ";
    vector<int> after = readNumbers(outputFile);
    for (int v : after) cout << v << ' ';
    cout << '\n';

    return 0;
}
