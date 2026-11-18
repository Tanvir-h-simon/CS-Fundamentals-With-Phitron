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
        int size;
    public:
        Linkedlist () {
            this->head = NULL;
            this->tail = NULL;
            this->size = 0;
        }
    
    void insertAtHead (int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }    
    
    void insertAtTail (int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    void deleteHead() {
        if (head == NULL) {
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head == NULL) {
            tail = NULL;
        }

        delete temp;

        size--;
    }

    void deleteAtPosition(int index) {
        /* When X(index) = 2:
            1. If V == 0 -> remove head.
            2. If 0 < V < length -> remove that position.
            3. If V >= length -> do nothing.
        */
        if (index < 0 || index >= size) {
            return;
        }

        if (index == 0) {
            deleteHead();
            return;
        }

        Node* current = head;
        for (int i = 0; i < index - 1; i++) { // Traverse to the previous node
            current = current->next;
        }
        Node* temp = current->next; // temp node = index'th node
        current->next = temp->next;

        if (temp == tail) {
            tail = current;
        }

        delete temp;

        size--;
    }

    void printList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Linkedlist list;

    int q; // Queries
    cin >> q;

    int x, v; // x = index, v = value
    while (q--) {
        cin >> x >> v;
        if (x == 0) {
            list.insertAtHead(v);
        } else if (x == 1){
            list.insertAtTail(v);
        } else if (x == 2) {
            list.deleteAtPosition(v); // When X == 2, Index == V
        }
        list.printList();
    }

    return 0;
}