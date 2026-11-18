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
    public:
        DoublyLinkedlist() {
            this->head = NULL;
            this->tail = NULL;
        }

        void insert_at_head(int value) {
            Node* newNode = new Node(value);

            if (head == NULL) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }

        void insert_at_tail(int value) {
            Node* newNode = new Node(value);
            if (head == NULL) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        void print_forward() {
            Node* current = head;
            while (current != NULL) {
                cout << current->value << "->";
                current = current->next;
            }
            cout << "NULL" << endl;
        }

};

int main() {
    DoublyLinkedlist list;
    
    cout << "Enter value(-1 to stop): " << endl;
    int value;
    while (cin >> value && value != -1) {
        list.insert_at_tail(value);
    }

    list.print_forward();

    return 0;
}