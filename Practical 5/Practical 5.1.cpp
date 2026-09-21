
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node *prev;
    Node *next;

    Node(string s) {
        song = s;
        prev = NULL;
        next = NULL;
    }
};

class Playlist {
    Node *head;
    Node *tail;
    int count;

public:
    Playlist() {
        head = NULL;
        tail = NULL;
        count = 0;
    }

    void addFirst(string song) {
        Node *newNode = new Node(song);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        count++;
        display();
    }

    void addLast(string song) {
        Node *newNode = new Node(song);

        if (tail == NULL) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        count++;
        display();
    }

    void insertAfter(string given, string song) {
        Node *temp = head;

        while (temp != NULL && temp->song != given)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Song not found" << endl;
            return;
        }

        Node *newNode = new Node(song);

        newNode->prev = temp;
        newNode->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = newNode;
        else
            tail = newNode;

        temp->next = newNode;

        count++;
        display();
    }

    void removeFirst() {
        if (head == NULL) {
            cout << "Playlist is empty" << endl;
            return;
        }

        Node *temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;

        delete temp;
        count++;

        count--;
        display();
    }

    void display() {
        Node *temp = head;

        cout << "Playlist: ";

        while (temp != NULL) {
            cout << temp->song << " ";
            temp = temp->next;
        }

        cout << "\nCount: " << count << endl;
    }
};

int main() {
    Playlist p;

    int n;
    cin >> n;

    while (n--) {
        int choice;
        cin >> choice;

        if (choice == 1) {
            string song;
            cin >> song;
            p.addFirst(song);
        }
        else if (choice == 2) {
            string song;
            cin >> song;
            p.addLast(song);
        }
        else if (choice == 3) {
            string after, song;
            cin >> after >> song;
            p.insertAfter(after, song);
        }
        else if (choice == 4) {
            p.removeFirst();
        }
    }

    return 0;
}
