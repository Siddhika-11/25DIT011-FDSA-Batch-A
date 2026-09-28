#include <iostream>
using namespace std;

class Stack {
    int *a, top, n;

public:
    Stack(int size) {
        n = size;
        a = new int[n];
        top = -1;
    }

    void push(int x) {
        if (top == n - 1) {
            cout << "Error: Stack is full\n";
            return;
        }

        a[++top] = x;
        cout << "Top: " << a[top] << endl;
    }

    void pop() {
        if (top == -1) {
            cout << "Error: Stack is empty\n";
            return;
        }

        top--;

        if (top == -1)
            cout << "Stack is empty\n";
        else
            cout << "Top: " << a[top] << endl;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    Stack s(n);

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int x;
            cin >> x;
            s.push(x);
        }
        else if (op == 2) {
            s.pop();
        }
    }

    return 0;
}
