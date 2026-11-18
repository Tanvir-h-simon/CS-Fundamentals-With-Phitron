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

    int getIndex(int x) {
        Node* current = head;
        for (int i = 0; current != NULL; i++) {
            if (current->value == x) {
                return i;
            }
            current = current->next;
        }
        return -1;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        Linkedlist list;
        int value;
        while (cin >> value && value != -1) {
            list.insertAtTail(value);
        }

        // list.printList();

        int x;
        cin >> x;

        int idx = list.getIndex(x);
        cout << idx << endl;
    }

    return 0;
}