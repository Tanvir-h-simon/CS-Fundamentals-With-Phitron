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

    // void printList() {
    //     Node* current = head;
    //     while (current != NULL) {
    //         cout << current->value;
    //         if (current->next != NULL) {
    //             cout << "->";
    //         }
    //         current = current->next;
    //     }
    //     cout << endl;
    // }

    // bool isEqual(Linkedlist &other) {
    //     Node* current1 = this->head;
    //     Node* current2 = other.head;
    //     // Node* current1 = list1.getHead();
    //     // Node* current2 = list2.getHead();

    //     while (current1 != NULL && current2 != NULL) {
    //     if (current1->value != current2->value) {
    //         return false;
    //     }
    //     current1 = current1->next;
    //     current2 = current2->next;
    //     }
    //     return (current1 == NULL && current2 == NULL);
    // }

    int getSize () {
        return size;
    }

    Node* getHead() {
        return head;
    }
};

int main() {
    Linkedlist list1, list2;
    int value;

    while (cin >> value && value != -1) {
        list1.insertAtTail(value);
    }
    // list1.printList();

    while (cin >> value && value != -1) {
        list2.insertAtTail(value);
    }
    // list2.printList();

    // Check if both lists are equal or not
    Node* current1 = list1.getHead();
    Node* current2 = list2.getHead();

    bool equal = true;
    while (current1 != NULL && current2 != NULL) {
        if (current1->value != current2->value) {
            equal = false;
            break;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    // if (list1.isEqual(list2)) {
    //     cout << "YES" << endl;
    // } else {
    //     cout << "NO" << endl;
    // }

    if (list1.getSize() == list2.getSize()) {
        if (equal){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}