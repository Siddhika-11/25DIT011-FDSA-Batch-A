
#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;
    int table[SIZE];

    for (int i = 0; i < SIZE; i++) {
        table[i] = -1;
    }

    int n, id;
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter student ID: ";
        cin >> id;

        int h1 = id % SIZE;
        int h2 = 7 - (id % 7);
        int j = 0;
        int pos;

        while (j < SIZE) {
            pos = (h1 + j * h2) % SIZE;

            if (table[pos] == -1) {
                table[pos] = id;
                cout << "Student " << id << " stored at slot " << pos << endl;
                break;
            }

            j++;
        }

        if (j == SIZE) {
            cout << "Hash table is full. ID " << id << " not stored.\n";
        }
    }

    cout << "\nFinal Hash Table:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Slot " << i << ": ";
        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];
        cout << endl;
    }

    return 0;
}
