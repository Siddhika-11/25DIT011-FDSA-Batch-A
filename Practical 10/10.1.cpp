
#include <iostream>
using namespace std;

int main() {
    int slots[10];

    for (int i = 0; i < 10; i++) {
        slots[i] = -1;
    }

    int n, reg;
    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter registration number: ";
        cin >> reg;

        int pos = reg % 10;
        int count = 0;

        while (slots[pos] != -1 && count < 10) {
            pos = (pos + 1) % 10;
            count++;
        }

        if (count == 10) {
            cout << "Parking lot is full. Vehicle cannot be parked.\n";
        } else {
            slots[pos] = reg;
            cout << "Vehicle parked at slot " << pos << endl;
        }
    }

    cout << "\nFinal parking lot:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Slot " << i << ": ";
        if (slots[i] == -1)
            cout << "Empty";
        else
            cout << slots[i];
        cout << endl;
    }

    return 0;
}
