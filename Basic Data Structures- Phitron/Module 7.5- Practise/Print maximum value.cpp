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
    
    void insertAtTail (int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
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

    int maximumValue() {
        if (head == NULL) {
            throw runtime_error("List is empty.");
        }
        int maximum = head->value;
        Node* current = head;
        while (current != NULL) {
            if (current->value > maximum) {
                maximum = current->value;
            }
            current = current->next;
        }
        return maximum;
    }
};

int main() {
    Linkedlist list;
    while (true) {
        cout << "Enter value for list1(-1 to stop): ";
        int value;
        cin >> value;
        if (value == -1) {
            break;
        }
        list.insertAtTail(value);
    }
    list.printList();

    cout << list.maximumValue() << endl;

    return 0;
}