
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> shelves[10];
    int n, code;

    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter book code: ";
        cin >> code;

        int shelf = code % 10;
        shelves[shelf].push_back(code);

        cout << "Book " << code << " placed on shelf " << shelf << endl;
    }

    cout << "\nFinal contents of shelves:\n";

    for (int i = 0; i < 10; i++) {
        cout << "Shelf " << i << ": ";

        if (shelves[i].empty()) {
            cout << "Empty";
        } else {
            for (int j = 0; j < shelves[i].size(); j++) {
                cout << shelves[i][j] << " ";
            }
        }

        cout << endl;
    }

    return 0;
}

