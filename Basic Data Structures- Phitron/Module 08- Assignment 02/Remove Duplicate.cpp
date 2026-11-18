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

    // void sortAscending() {
    //     if (head == NULL || head->next == NULL) return;

    //     for (Node* i = head; i != NULL; i = i->next) {
    //         Node* minNode = i;
    //         for (Node* j = i->next; j != NULL; j = j->next) {
    //             if (j->value < minNode->value) {
    //                 minNode = j;
    //             }
    //         }
    //         if (minNode != i) {
    //             swap(i->value, minNode->value);
    //         }
    //     }
    // }

    void removeDuplicate() {
        Node* current = head;

        while (current != NULL) {
            Node* prev = current;  
            Node* temp = current->next;

            // Compare current node with all following nodes
            while (temp != NULL) {
                if (temp->value == current->value) {
                    // Remove duplicate
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                } else {
                    // No duplicate, move both pointers forward
                    prev = temp;
                    temp = temp->next;
                }
            }
            current = current->next;
        }
    }

    void printList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->value;
            if (current->next != NULL) {
                cout << " ";
            }
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Linkedlist list;

    int value;
    while (cin >> value && value != -1) {
        list.insertAtTail(value);
    }

    // list.sortAscending();
    list.removeDuplicate();
    list.printList();

    return 0;
}