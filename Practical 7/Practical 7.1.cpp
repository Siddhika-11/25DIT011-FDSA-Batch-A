#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Queue(int n) {
        capacity = n;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    void join(int token) {
        if (size == capacity) {
            cout << "Error: Queue is full" << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = token;
        size++;

        displayFront();
    }

    void serve() {
        if (size == 0) {
            cout << "Error: Queue is empty" << endl;
            return;
        }

        front = (front + 1) % capacity;
        size--;

        displayFront();
    }

    void displayFront() {
        if (size == 0)
            cout << "Front: Empty" << endl;
        else
            cout << "Front: " << arr[front] << endl;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    int n, operations;

    cout << "Enter queue capacity: ";
    cin >> n;

    Queue q(n);

    cout << "Enter number of operations: ";
    cin >> operations;

    while (operations--) {
        int choice;

        cin >> choice;

        if (choice == 1) {
            int token;
            cin >> token;
            q.join(token);
        }
        else if (choice == 2) {
            q.serve();
        }
        else {
            cout << "Invalid operation" << endl;
        }
    }

    return 0;
}
