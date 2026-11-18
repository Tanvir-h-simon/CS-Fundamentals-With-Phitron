#include <iostream>
using namespace std;

class Node {
    public:
        Node* next;
        Node* prev;
        string value;

        Node (string value) {
            this->next = NULL;
            this->prev = NULL;
            this->value = value;
        }
};

class DoublyLinkedlist {
    private:
        Node* head;
        Node* tail;
        Node* current;
        int size;
    public:
        DoublyLinkedlist() {
            this->head = NULL;
            this->tail = NULL;
            this->current = NULL;
            this->size = 0;
        }

        void insertAtTail(string value) {
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

        Node* visitNode(string addressName) {
            Node* temp = head;
            while (temp != NULL) {
                if (temp->value == addressName) {
                    // Node* current = temp;
                    current = temp; // Store the temp (visited) node and return it
                    cout << current->value << endl;
                    return current;
                }
                temp = temp->next;
            }
            cout << "Not Available" << endl;
            return current;
        }

        void nextNode() {
            // if (current != NULL && current->next != NULL) {
            if (current && current->next) {
                current = current->next;
                cout << current->value << endl;
            } else {
                cout << "Not Available" << endl;
            }
        }

        void prevNode() {
            // if (current != NULL && current->prev  != NULL) {
            if (current && current->prev) {
                current = current->prev;
                cout << current->value << endl;
            } else {
                cout << "Not Available" << endl;
            }
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

    // cout << "Enter value (Type \"end\" to stop): " << endl;
    string address;
    while (cin >> address && address != "end") {
        list.insertAtTail(address);
    }
    // list.printForward();

    int queries;
    cin >> queries;
    while (queries--) {
        string command; 
        cin >> command;
        if (command == "visit") {
            string addressName;
            cin >> addressName; 
            list.visitNode(addressName);
        } else if (command == "next") {
            list.nextNode();
        } else if (command == "prev") {
            list.prevNode();
        }
    }

    return 0;
}