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
    int size;
public:
    Linkedlist () {
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

    // void printMiddleElement() {
    //     cout << "Middle element: ";
    //     Node* current = head;
    //     if (size % 2 != 0) {
    //         for (int i = 1; i <= size / 2; i++) {
    //             current = current->next;
    //         }
    //         cout << current->value;
    //     } else {
    //         for (int i = 1; i < size / 2; i++) {
    //             current = current->next;
    //         }
    //         cout << current->value << " ";
    //         cout << current->next->value;
    //     }
    // }

    void printMiddleElement() {
        if (head == NULL) return;

        Node* slow = head;
        Node* fast = head;

        // Move fast 2 steps and slow 1 step
        while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
       
        if (fast != NULL && fast->next != NULL) { // Even length
            cout << slow->value << " " << slow->next->value << endl;
        } else { // Odd length- (fast->next == NULL)
            cout << slow->value << endl;
        }
    }
};

int main() {
    Linkedlist list;
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
    list.printMiddleElement();

    return 0;
}