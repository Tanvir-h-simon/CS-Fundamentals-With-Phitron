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

class LinkedList {
private:
    Node* head;
public:
    LinkedList () {
        this->head = NULL;
    }

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void printList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->value << "->";
            current = current->next;
        }
        cout << "NULL" << endl;

    }

    void sortList() {
        if (head == NULL || head->next == NULL) return;

        for (Node* i = head; i->next != NULL; i = i->next) { // O(n*n)
            Node* minNode = i; // Assume the current node is the smallest
            for (Node* j = i->next; j != NULL; j = j->next) {
                if (j->value < minNode->value) {
                    minNode = j; // Update the smallest node
                }
            }
            if (minNode != i) {
                swap(minNode->value, i->value);
            }
        }
    }

    bool findDuplicate() {
        Node* current = head;
        while (current != NULL && current->next != NULL) {
            if (current->value == current->next->value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // bool findDuplicate() { // O(n*n)
    //     Node* current = head;
    //     while (current != NULL) {
    //         Node* runner = current->next;
    //         while (runner != NULL) {
    //             if (runner->value == current->value) {
    //                 return true;
    //             }
    //             runner = runner->next;
    //         }
    //         current = current->next;
    //     }
    //     return false;
    // }
};

int main() {
    LinkedList list;
    while (true) {
        cout << "Enter value(-1 to stop): ";
        int value;
        cin >> value;
        if (value == -1) {
            break;
        }
        list.insertAtHead(value);
    }

    list.printList();
    cout << "Sorted linked list: ";
    list.sortList();
    list.printList();

    if (list.findDuplicate()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}