#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    int value;
    
    Node(int value) {
        this->next = NULL;
        this->value = value;
    }
};

class LinkedList {
private:
    Node* head;
    int size;
public:
    LinkedList() {
        this->head = NULL;
        this->size = 0;
    }

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->value << "-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int getSize() {
        return size;
    }
};

int main() {
    LinkedList list;
    int value;
    while (true) {
        cout << "Enter value (-1 to stop): ";
        cin >> value;
        if (value == -1) break;
        list.insertAtHead(value);
    }
    cout << "Linked list: ";
    list.printList();
    cout << "Size: " << list.getSize() << endl;
}