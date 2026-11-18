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

    int getSize() {
        return size;
    }
};


int main() {
    Linkedlist list1;
    while (true) {
        cout << "Enter value for list1(-1 to stop): ";
        int value;
        cin >> value;
        if (value == -1) {
            break;
        }
        list1.insertAtTail(value);
    }
    list1.printList();

    Linkedlist list2;
    while (true) {
        cout << "Enter value for list2(-1 to stop): ";
        int value;
        cin >> value;
        if (value == -1) {
            break;
        }
        list2.insertAtTail(value);
    }
    list2.printList();
    
    if (list1.getSize() == list2.getSize()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}