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
        head = NULL;
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

    void sortDescending() {
        if (head == NULL && head->next == NULL) return;

        for (Node* i = head; i != NULL; i = i->next) {
            Node* maxNode = i;
            for (Node* j = i->next; j != NULL; j = j->next) {
                if (j->value > maxNode->value) {
                    maxNode = j;
                }
            }
            if (maxNode != i) {
                swap(i->value, maxNode->value);
            }
        }
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
    int value;
    cout << "Enter value(-1 to stop): " << endl;
    while (cin >> value && value != -1) {
        list.insertAtTail(value);
    }

    list.sortDescending();
    list.printList();

    return 0;
}