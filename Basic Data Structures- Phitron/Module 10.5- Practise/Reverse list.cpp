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

        void insert_at_head(int value) {
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

        void insert_at_tail(int value) {
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

        void reverse_doubly_linkedlist() {
            // for (int i = 0, j = n- 1; i < j; i++, j--) {
            //     swap(i , j);
            // }
            for (Node *i = head,  *j = tail; i != j && i->prev != j; i = i->next, j = j->prev) {
                swap(i->value, j->value);
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

        void print_backward() {
            Node* current = tail;
            while (current != NULL) {
                cout << current->value << "->";
                current = current->prev;
            }
            cout << "NULL" << endl;
        }

        Node* getHead() {
            return head;
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
    cout << "Head: " << list.getHead()->value << endl;

    list.print_backward();
    cout << "Head: " << list.getHead()->value << endl;

    list.reverse_doubly_linkedlist();
    cout << "Head: " << list.getHead()->value << endl;

    return 0;
}