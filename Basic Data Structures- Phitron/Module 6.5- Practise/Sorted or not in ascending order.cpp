#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    int value;

    Node (int value) {
        this->next = NULL;
        this->value = value;
    }
};

class Linkedlist {
private:
    Node* head;
    Node* tail;
public:
    Linkedlist () {
        this->head = NULL;
        this->tail = NULL;
    }    

    void insertAtHead (int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail (int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // bool isSorted () { // O(n*n)
    //     for (Node* i = head; i->next != NULL; i = i->next) {
    //         for (Node* j = i->next; j->next != NULL; j = j->next) {
    //             if (i->value > j->value) return false; 
    //         }
    //     }
    //     return true;
    // }

    bool isSorted() {
        if (head == NULL || head->next == NULL) return true;

        Node* current = head;
        while (current->next != NULL) { // O(n)
            if (current->value > current->next->value) {
                return false;
            }
            current = current->next;
        }
        return true;
    }

    void printList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->value;
            if (current->next != NULL) {
                cout << "->";
            }
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Linkedlist list;
    while (true) {
        cout << "Enter value(-1 to stop): ";
        int value;
        cin >> value;
        if (value == -1) {
            break;
        }
        list.insertAtTail(value);
    }
    list.printList();

    if (list.isSorted()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}