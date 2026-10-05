#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void arrive(int patient) {
        Node* newNode = new Node(patient);

        if (rear == NULL) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }

        displayFront();
    }

    void attend() {
        if (front == NULL) {
            cout << "Error: Ward is empty" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;

        displayFront();
    }

    void displayFront() {
        if (front == NULL)
            cout << "Front: Empty" << endl;
        else
            cout << "Front: " << front->data << endl;
    }
};

int main() {
    Queue q;

    int n;
    cout << "Enter number of operations: ";
    cin >> n;

    while (n--) {
        int choice;

        cin >> choice;

        if (choice == 1) {
            int patient;
            cin >> patient;
            q.arrive(patient);
        }
        else if (choice == 2) {
            q.attend();
        }
        else {
            cout << "Invalid operation" << endl;
        }
    }

    return 0;
}
