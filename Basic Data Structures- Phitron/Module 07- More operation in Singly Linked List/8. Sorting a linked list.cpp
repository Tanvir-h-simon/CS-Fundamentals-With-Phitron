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

void insert_at_any_position(Node*& head, int position, int value) {
    Node* newNode = new Node(value);
    if (position == 0) {
        insert_at_head(head, value);
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

void print_reverse(Node* head) {
    if (head == NULL) return;
    print_reverse(head->next);
    cout << head->value << " ";
}

void delete_head(Node*& head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void delete_tail(Node*& head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void delete_at_position(Node*& head, int position) {
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
}

void selection_sort(Node* head) {
    if (head == NULL || head->next == NULL) return; // already sorted or empty

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

int main() {
    Node* head = NULL;

    while (true) {
        cout << "\nOption 1: Insert at head" << endl;
        cout << "Option 2: Insert at tail" << endl;
        cout << "Option 3: Insert at any position" << endl;
        cout << "Option 4: Print Linked List" << endl;
        cout << "Option 5: Print Reverse Linked List" << endl;
        cout << "Option 6: Delete head" << endl;
        cout << "Option 7: Delete from any position" << endl;
        cout << "Option 8: Delete tail" << endl;
        cout << "Option 9: Sort the linked list" << endl;
        cout << "Option 10: Terminate" << endl;

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
            int pos, value;
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> value;
            insert_at_any_position(head, pos, value);
        }
        else if (option == 4) {
            print_linked_list(head);
        }
        else if (option == 5) {
            cout << "Reverse Linked List: ";
            print_reverse(head);
            cout << endl;
        }
        else if (option == 6) {
            delete_head(head);
        }
        else if (option == 7) {
            int pos;
            cout << "Enter position: ";
            cin >> pos;
            delete_at_position(head, pos);
        }
        else if (option == 8) {
            delete_tail(head);
        }
        else if (option == 9) {
            selection_sort(head);
            cout << "Linked list sorted successfully." << endl;
        }
        else if (option == 10) {
            cout << "Terminating program." << endl;
            break;
        }

        else {
            cout << "Invalid option." << endl;
        }
    }

    return 0;
}