#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;
    Node(int value) {
        this->value = value;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = tail = NULL;
    }

    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void sortAscending() {
        if (!head || !head->next) return;

        for (Node* i = head; i != NULL; i = i->next) {
            for (Node* j = i->next; j != NULL; j = j->next) {
                if (i->value > j->value) {
                    swap(i->value, j->value);
                }
            }
        }
    }

    void printForward() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->value;
            if (temp->next != NULL) cout << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    int val;

    while (cin >> val) {
        if (val == -1) break;
        list.insertAtTail(val);
    }

    list.sortAscending();
    list.printForward();

    return 0;
}