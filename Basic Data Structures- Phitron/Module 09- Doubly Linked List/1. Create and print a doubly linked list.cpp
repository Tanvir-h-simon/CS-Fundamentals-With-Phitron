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

        void set_head(Node* head) {
            this->head = head;
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

    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* tail = new Node(40);

    head->next = a;
    a->prev = head;

    a->next = b;
    b->prev = a;

    b->next = tail;
    tail->prev = b;

    list.set_head(head);
    list.print_forward();

    return 0;
}