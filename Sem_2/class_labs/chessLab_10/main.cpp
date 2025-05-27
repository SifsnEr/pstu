#include "Time.h"
#include "file_work.h"
#include <iostream>
using namespace std;

int main() {
    int c, k, nom;
    char file_name[30];
    Time t;

    do {
        cout << "\n1. Make file";
        cout << "\n2. Print file";
        cout << "\n3. Delete records equal to given time";
        cout << "\n4. Increase all equal records by 1:30";
        cout << "\n5. Add K records after element with given number";
        cout << "\n0. Exit\n";

        cin >> c;
        switch (c) {
            case 1:
                cout << "File name? "; cin >> file_name;
                k = make_file(file_name);
                if (k < 0) cout << "Can't make file\n";
                break;

            case 2:
                cout << "File name? "; cin >> file_name;
                k = print_file(file_name);
                if (k < 0) cout << "Can't read file\n";
                if (k == 0) cout << "Empty file\n";
                break;

            case 3:
                cout << "File name? "; cin >> file_name;
                cout << "Time to delete (mm:ss)? "; cin >> t;
                k = del_file(file_name, t);
                if (k < 0) cout << "Can't read file\n";
                else cout << "Deleted " << k << " records\n";
                break;

            case 4:
                cout << "File name? "; cin >> file_name;
                cout << "Time to increase (mm:ss)? "; cin >> t;
                k = increase_time(file_name, t);
                if (k < 0) cout << "Can't read file\n";
                else cout << "Increased " << k << " records\n";
                break;

            case 5:
                cout << "File name? "; cin >> file_name;
                cout << "Position after which to add records? "; cin >> nom;
                cout << "How many records to add? "; cin >> k;
                for (int i = 0; i < k; i++) {
                    cout << "New time (mm:ss)? ";
                    cin >> t;
                    int res = add_file(file_name, nom + i, t);
                    if (res < 0) {
                        cout << "Can't read file\n";
                        break;
                    }
                }
                break;

            case 0:
                break;

            default:
                cout << "Invalid option\n";
        }
    } while (c != 0);

    return 0;
}
