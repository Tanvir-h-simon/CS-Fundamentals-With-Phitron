#include <iostream>
#include <vector>
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

        void printReverseListRecursive(Node* current) {
            if (current == NULL) {
                return;
            }
            printReverseListRecursive(current->next);
            cout << current->value;
            if (current != head) cout << "->";
        }

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

    // void printReverseList() {
    //     vector<int> v;
    //     Node* current = head;
    //     while (current != NULL) {
    //         v.push_back(current->value);
    //         current = current->next;
    //     }
        
    //     for (int i = v.size() - 1; i >= 0; i--) {
    //         cout << v[i];
    //         if (i != 0) {
    //             cout << "->";
    //         }
    //     }
    //     cout << endl;
    // }

    void printReverseList() {
        printReverseListRecursive(head);
        cout << endl;
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
    cout << "Forward: ";
    list.printList();

    cout << "Backward: ";
    list.printReverseList();

    return 0;
}