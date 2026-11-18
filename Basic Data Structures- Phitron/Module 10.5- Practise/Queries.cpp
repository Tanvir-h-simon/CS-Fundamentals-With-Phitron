#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    Node* prev;
    int value;

    Node(int value) {
        this->next = NULL;
        this->prev = NULL;
        this->value = value;
    }
};

class DoublyLinkedlist {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedlist() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    bool insertAtIndex(int index, int value) {
        if (index < 0 || index > size) {
            return false;
        }

        if (index == 0) {
            insertAtHead(value);
        } 
        else if (index == size) {
            insertAtTail(value);
        } 
        else {
            Node* newNode = new Node(value);
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
            size++;
        }
        return true;
    }

    void printForward() {
        Node* current = head;
        while (current != NULL) {
            cout << current->value;
            if (current->next != NULL) cout << " ";
            current = current->next;
        }
        cout << endl;
    }

    void printBackward() {
        Node* current = tail;
        while (current != NULL) {
            cout << current->value;
            if (current->prev != NULL) cout << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedlist list;
    int Q;
    cin >> Q;
    int X, V;

    while (Q--) {
        cin >> X >> V;
        if (!list.insertAtIndex(X, V)) {
            cout << "Invalid" << endl;
        } else {
            list.printForward();
            list.printBackward();
        }
    }
    return 0;
}