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

void insert_at_head(Node* &head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;

    cout << "Inserted at head." << endl;
}

void print_linked_list(Node* head) {
    if (head == NULL) {
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

void delete_linked_list(Node* &head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = NULL;

    while (true) {
        cout << "\nOption 1: Insert at head." << endl;
        cout << "Option 2: Print linked list." << endl;
        cout << "Option 3: Terminate." << endl;

        int option;
        cin >> option;

        if (option == 1) {
            int value;
            cout << "Enter value to insert: ";
            cin >> value;
            insert_at_head(head, value);
        } 
        else if (option == 2) {
            print_linked_list(head);
        }
        else if (option == 3) {
            delete_linked_list(head);
            cout << "All nodes deleted. Terminating program..." << endl;
            break;
        }
        else {
            cout << "Invalid option. Try again." << endl;
        }
    }

    return 0;
}
