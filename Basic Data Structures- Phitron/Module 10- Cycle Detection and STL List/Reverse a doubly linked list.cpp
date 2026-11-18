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

        void insert_at_position(int index, int value) {
            if (index < 0 || index > size) {
                throw runtime_error("Invalid index.");
            }

            if (index == 0) {
                insert_at_head(value);
            } else if (index == size - 1) {
                insert_at_tail(value);
            } else {
                Node* newNode = new Node(value);

                Node* current = head;
                for (int i = 0; i < index - 1; i++) {  // Traverse to the previous node
                    current = current->next;
                }
                newNode->next = current->next;
                current->next->prev = newNode;
                
                current->next = newNode;
                newNode->prev = current;

                size++;
            }
        }

        void delete_head() {
            if (head == NULL) {
                return;
            }

            if (head == tail ) { // size == 1
                delete head;
                head = tail = NULL;
            } else {
                Node* temp = head;
                head = head->next;
                head->prev = NULL;
                delete temp;
            }

            size--;
        }

        void delete_tail() {
            if (head == NULL) {
                return;
            }

            if (head == tail ) { // size == 1
                delete head;
                head = tail = NULL;
            } else {
                Node* temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
            }

            size--;
        }

        void delete_from_position(int index) {
            if (index < 0 || index > size - 1) {
                throw runtime_error("Invalid index.");
            }

            if (index == 0) { // size == 1
                delete_head();
            } else if (index == size - 1) {
                delete_tail();
            } else {
                Node* current = head;
                for (int i = 0; i < index - 1; i++) { // Traverse to the previous node
                    current = current->next; 
                }
                Node* temp = current->next;
                // current->next = current->next->next;
                current->next = temp->next;
                // current->next->prev = current;
                temp->next->prev = current;
                delete temp;

                size--;
            } 
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

        int getSize() {
            return size;
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

    cout << "Enter an index and a value: " << endl;
    int index;
    cin >> index >> value;
    
    list.insert_at_position(index, value);
    list.print_forward();

    list.delete_head();
    list.print_forward();

    list.delete_tail();
    list.print_forward();

    cout << "Enter an index to delete node: " << endl;
    cin >> index;
    list.delete_from_position(index);
    list.print_forward();

    list.print_backward();

    cout << "Size: " << list.getSize() << endl;

    list.reverse_doubly_linkedlist();
    list.print_forward();

    return 0;
}