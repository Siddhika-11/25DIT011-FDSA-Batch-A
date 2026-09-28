#include <iostream>
#include <string>
using namespace std;

class Browser {
    string *history;
    int top;
    int capacity;

public:
    Browser() {
        capacity = 2;
        history = new string[capacity];
        top = -1;
    }

    void visit(string page) {
        if (top + 1 == capacity) {
            capacity *= 2;
            string *temp = new string[capacity];

            for (int i = 0; i <= top; i++)
                temp[i] = history[i];

            delete[] history;
            history = temp;
        }

        history[++top] = page;
        cout << "Current Page: " << history[top] << endl;
    }

    void back() {
        if (top == 0) {
            cout << "No previous page" << endl;
            cout << "Current Page: " << history[top] << endl;
            return;
        }

        if (top == -1) {
            cout << "No page in history" << endl;
            return;
        }

        top--;
        cout << "Current Page: " << history[top] << endl;
    }

    Browser() {
        delete[] history;
    }
};

int main() {
    Browser browser;

    int n;
    cout << "Enter number of operations: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int choice;
        cin >> choice;

        if (choice == 1) {
            string page;
            cin >> page;
            browser.visit(page);
        }
        else if (choice == 2) {
            browser.back();
        }
        else {
            cout << "Invalid operation" << endl;
        }
    }

    return 0;
}
