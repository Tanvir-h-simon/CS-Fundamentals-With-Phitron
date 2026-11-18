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

        void print_forward() {
            Node* current = head;
            while (current != NULL) {
                cout << current->value << "->";
                current = current->next;
            }
            cout << "NULL" << endl;
        }

        bool isEqual(DoublyLinkedlist &other) {
            if (size != other.size) {
                return false;
            }

            Node* current1 = head;
            Node* current2 = other.head;

            while(current1 && current2) {
                if (current1->value != current2->value) {
                    return false;
                }
                current1 = current1->next;
                current2 = current2->next;
            }
            return true;
        }
};

int main() {
    DoublyLinkedlist list1, list2;
    
    cout << "Enter value(-1 to stop): " << endl;
    int value;
    while (cin >> value && value != -1) {
        list1.insert_at_tail(value);
    }
    list1.print_forward();

    cout << "Enter value(-1 to stop): " << endl;
    while (cin >> value && value != -1) {
        list2.insert_at_tail(value);
    }
    list2.print_forward();

    if (list1.isEqual(list2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}