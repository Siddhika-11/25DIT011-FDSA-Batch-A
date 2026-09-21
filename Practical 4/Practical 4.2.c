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
    Node* head;

public:
    Queue() {
        head = NULL;
    }

    void insertFront(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        display();
    }

    void insertEnd(int x) {
        Node* newNode = new Node(x);

        if (head == NULL) {
            head = newNode;
            display();
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        display();
    }

    void insertPosition(int x, int pos) {
        if (pos < 1) {
            cout << "Invalid position" << endl;
            return;
        }

        if (pos == 1) {
            insertFront(x);
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Position out of range" << endl;
            return;
        }

        Node* newNode = new Node(x);
        newNode->next = temp->next;
        temp->next = newNode;

        display();
    }

    void display() {
        Node* temp = head;

        cout << "Queue: ";

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Queue q;

    int n;
    cout << "Enter number of operations: ";
    cin >> n;

    while (n--) {
        int choice, value, pos;

        cout << "\n1. Insert Front";
        cout << "\n2. Insert End";
        cout << "\n3. Insert Position";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cin >> value;
            q.insertFront(value);
        }
        else if (choice == 2) {
            cin >> value;
            q.insertEnd(value);
        }
        else if (choice == 3) {
            cin >> value >> pos;
            q.insertPosition(value, pos);
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
