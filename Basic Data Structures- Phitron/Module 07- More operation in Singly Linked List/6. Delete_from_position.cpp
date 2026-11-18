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
    cout << "Inserted at head." << endl; 
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
    cout << "Inserted at tail." << endl;
}

void insert_at_any_position(Node*& head, int position, int value) {
    Node* newNode = new Node(value);
    if (position == 0) {
        newNode->next = head;
        head = newNode;
        cout << "Inserted at position: " << position << endl;
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

void print_reverse(Node* head) {
    if (!head) return;
    print_reverse(head->next);
    cout << head->value << " ";
}

void delete_head(Node*& head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* deleteNode = head;
    head = head->next;
    delete deleteNode;
    cout << "Deleted head." << endl;
}

void delete_from_position(Node*& head, int position) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    if (position == 0) {
        delete_head(head);
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
    delete deleteNode;
    cout << "Deleted from position: " << position << endl;
}

int main() {
    Node* head = NULL;

    while (true) {
        cout << "\nOption 1: Insert at head." << endl;
        cout << "Option 2: Insert at tail." << endl;
        cout << "Option 3: Insert at any position." << endl;
        cout << "Option 4: Print Linked List." << endl;
        cout << "Option 5: Print Reverse Linked List." << endl;
        cout << "Option 6: Delete head." << endl;
        cout << "Option 7: Delete from any position." << endl;
        cout << "Option 8: Terminate." << endl;

        int option;
        cin >> option;

        if (option == 1) {
            int value;
            cout << "Enter value: ";
            cin >> value;
            insert_at_head(head, value);
        } 
        else if (option == 2) {
            int value;
            cout << "Enter value: ";
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
            if (!head) {
                cout << "Linked List is empty." << endl;
            } else {
                cout << "Linked List in reverse: ";
                print_reverse(head);
                cout << endl;
            }
        } 
        else if (option == 6) {
            delete_head(head);
        } 
        else if (option == 7) {
            int position;
            cout << "Enter position: ";
            cin >> position;
            delete_from_position(head, position);
        } 
        else if (option == 8) {
            cout << "Terminating program." << endl;
            break;
        } 
        else {
            cout << "Invalid option. Try again." << endl;
        }
    }

    return 0;
}