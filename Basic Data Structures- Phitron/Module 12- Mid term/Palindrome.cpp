#include <iostream>
using namespace std;

class Node {
    public:
        Node* next;
        Node* prev;
        int value;

        Node (int value) {
            this->next = NULL;
            this->prev = NULL;
            this->value = value;
        }
};

class DoublyLinkedlist {
    private:
        Node* head;
        Node* tail;
        int size;
    public:
        DoublyLinkedlist() {
            this->head = NULL;
            this->tail = NULL;
            this->size = 0;
        }

        void insertAtHead(int value) {
            Node* newNode = new Node(value);

            if (head == NULL) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            size++;
        }

        void insertAtTail(int value) {
            Node* newNode = new Node(value);
            if (head == NULL) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            size++;
        }

        bool isPalindrome () {
            if (head == NULL) {
                throw runtime_error("Empty list.");
            }

            // for (int i = 0; i < size / 2; i++) {

            //     if (head->value != tail->value) {
            //         return false;
            //     }
            //     head = head->next;
            //     tail = tail->prev;

            // }
            // return true;
            
            Node* left = head;
            Node* right = tail;

            for (int i =0; i < size / 2; i++) {
                if (left->value != right->value) {
                    return false;
                }
                left = left->next;
                right = right->prev;
            }
            return true;
        }

        // void printForward() {
        //     Node* current = head;
        //     while (current != NULL) {
        //         cout << current->value << "->";
        //         current = current->next;
        //     }
        //     cout << "NULL" << endl;
        // }
};

int main() {
    DoublyLinkedlist list;
    
    // cout << "Enter value(-1 to stop): " << endl;
    int value;
    while (cin >> value && value != -1) {
        list.insertAtTail(value);
    }
    // list.printForward();

    if (list.isPalindrome()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}