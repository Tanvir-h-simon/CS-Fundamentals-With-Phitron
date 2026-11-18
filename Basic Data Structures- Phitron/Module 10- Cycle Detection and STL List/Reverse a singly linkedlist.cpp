#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        this->next = NULL;
    }
};

class SinglyLinkedlist {
private:
    Node* head;
    Node* tail;
public:
    SinglyLinkedlist() {
        head = NULL;
        tail = NULL;
    }

    void insert_at_head(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insert_at_tail(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void insert_at_any_position(int position, int value) {
        if (position == 0) {
            insert_at_head(value);
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position; i++) {
            if (temp == NULL) {
                cout << "Invalid position." << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Invalid position." << endl;
            return;
        }
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == NULL) tail = newNode;
    }

    void delete_head() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == NULL) tail = NULL;
    }

    void delete_tail() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        tail = temp;
    }

    void delete_at_position(int position) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (position == 0) {
            delete_head();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position; i++) {
            if (temp->next == NULL) {
                cout << "Invalid position." << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << "Invalid position." << endl;
            return;
        }
        Node* deleteNode = temp->next;
        temp->next = temp->next->next;
        if (temp->next == NULL) tail = temp;
        delete deleteNode;
    }

    void selection_sort() {
        if (head == NULL || head->next == NULL) return;
        for (Node* i = head; i->next != NULL; i = i->next) {
            Node* minNode = i;
            for (Node* j = i->next; j != NULL; j = j->next) {
                if (j->value < minNode->value) {
                    minNode = j;
                }
            }
            if (minNode != i) {
                swap(minNode->value, i->value);
            }
        }
    }
    void reverse_recursive(Node* temp) {
        if (temp == NULL || temp->next == NULL) { // Base case
            head = temp; // Last node becomes new head
            return;
        }

        reverse_recursive(temp->next);

        temp->next->next = temp; // Reverse link
        temp->next = NULL;       // Break old link
    }

    void reverse_linked_list() {
        tail = head; // Old head will become new tail
        reverse_recursive(head);
    }

    void print_linked_list() {
        cout << "Your Linked List: ";
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};

int main() {
    SinglyLinkedlist list;
    
    cout << "Enter values (-1 to stop): " << endl;
    int value;
    while (cin >> value && value != -1) {
        list.insert_at_tail(value);
    }

    list.print_linked_list();
    list.selection_sort();
    list.print_linked_list();
    list.reverse_linked_list();
    list.print_linked_list();
    return 0;
}