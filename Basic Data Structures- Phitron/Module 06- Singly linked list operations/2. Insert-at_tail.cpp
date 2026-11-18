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

void insert_at_tail(Node* &head, int val){
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void print_linked_list(Node* head) {
    cout << "Your Linked List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    cout << "Option 1: Insert at Tail." << endl;
    cout << "Option 2: Print Linked List." << endl;
    cout << "Option 3: Terminate." << endl;

    while (true) {
        int option;
        cout << "Enter Option: ";
        cin >> option;

        if (option == 1) {
            cout << "Please enter a value: ";
            int val;
            cin >> val;
            insert_at_tail(head, val);
        } else if (option == 2) {
            print_linked_list(head);
        } else if (option == 3) {
            cout << "Terminating program." << endl;
            break;
        } else {
            cout << "Invalid option. Try again." << endl;
        }
    }

    return 0;
}