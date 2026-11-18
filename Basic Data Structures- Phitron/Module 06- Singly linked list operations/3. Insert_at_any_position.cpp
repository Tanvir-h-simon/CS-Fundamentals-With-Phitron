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

void insert_at_head(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void insert_at_tail(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void print_linked_list(Node* head) {
    if (!head) {
        cout << "Linked List is empty." << endl;
        return;
    }
    cout << "Your Linked List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insert_at_any_position(Node*& head, int position, int value) {
    if (position < 0) {
        cout << "Invalid position." << endl;
        return;
    }
    Node* newNode = new Node(value);
    if (position == 0) { 
        newNode->next = head;
        head = newNode;
        cout << "Inserted at position 0 (head)." << endl;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position; i++) {
        if (temp == NULL) {
            cout << "Invalid position." << endl;
            delete newNode;
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Invalid position." << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Inserted at position: " << position << endl;
}

int main() {
    Node* head = NULL;

    while (true) {
        cout << "\nOption 1: Insert at head." << endl;
        cout << "Option 2: Insert at tail." << endl;
        cout << "Option 3: Insert at any position." << endl;
        cout << "Option 4: Print Linked List." << endl;
        cout << "Option 5: Terminate." << endl;

        int option;
        cin >> option;

        if (option == 1) {
            cout << "Enter value: ";
            int value;
            cin >> value;
            insert_at_head(head, value);
        } 
        else if (option == 2) {
            cout << "Enter value: ";
            int value;
            cin >> value;
            insert_at_tail(head, value);
        } 
        else if (option == 3) {
            int position, value;
            cout << "Enter position: ";
            cin >> position;
            cout << "Enter value: ";
            cin >> value;
            insert_at_any_position(head, position, value);
        } 
        else if (option == 4) {
            print_linked_list(head);
        } 
        else if (option == 5) {
            cout << "Terminating program..." << endl;
            break;
        } 
        else {
            cout << "Invalid option. Try again." << endl;
        }
    }
    return 0;
}