#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int value) {
        this->value = value;
        this->next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() { 
        this->head = NULL; 
    }

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    bool insertAtIndex(int index, int value) {
        if (index < 0) return false;

        if (index == 0) {
            insertAtHead(value);
            return true;
        }

        Node* temp = head;
        int count = 0;
        while (temp != NULL && count < index - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) return false;

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
        return true;
    }

    void printList() {
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
    LinkedList list;

    while (true) {
        cout << "Enter value(-1 to stop): ";
        int value;
        cin >> value;
        if (value == -1) break;
        list.insertAtTail(value);
    }

    list.printList();

    cout << "Enter number of queries: ";
    int q;
    cin >> q;

    while (q--) {
        cout << "Enter position and value: ";
        int index, value;
        cin >> index >> value;
        if (!list.insertAtIndex(index, value)) {
            cout << "Invalid" << endl;
        } else {
            list.printList();
        }
    }

    return 0;
}