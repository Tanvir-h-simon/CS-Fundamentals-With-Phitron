#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T value;
    Node* next;

    // Node (T value) {
    //     this->value = value;
    //     this->next = NULL;
    // }
    Node(T value) : value(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
public:
    // LinkedList() {
    //     this->head = NULL;
    // }
    LinkedList() : head(nullptr) {}

    void insertAtHead(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node<T>* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void insertAtPosition(int position, T value) {
        if (position < 0) {
            cout << "Invalid position." << endl;
            return;
        }
        if (position == 0) {
            insertAtHead(value);
            return;
        }

        Node<T>* temp = head;
        for (int i = 1; i < position && temp; i++) temp = temp->next;

        if (!temp) {
            cout << "Invalid position." << endl;
            return;
        }

        Node<T>* newNode = new Node<T>(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteHead() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteTail() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node<T>* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAtPosition(int position) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        if (position == 0) {
            deleteHead();
            return;
        }

        Node<T>* temp = head;
        for (int i = 1; i < position && temp->next; i++) temp = temp->next;

        if (!temp->next) {
            cout << "Invalid position." << endl;
            return;
        }

        Node<T>* deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;
    }

    void selectionSort() {
        for (Node<T>* i = head; i && i->next; i = i->next) {
            Node<T>* minNode = i;
            for (Node<T>* j = i->next; j; j = j->next) {
                if (j->value < minNode->value) minNode = j;
            }
            swap(i->value, minNode->value);
        }
    }

    void printList() const {
        Node<T>* temp = head;
        cout << "Linked List: ";
        while (temp) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printReverse(Node<T>* node) const {
        if (!node) return;
        printReverse(node->next);
        cout << node->value << " ";
    }

    void printReverseList() const {
        cout << "Reverse Linked List: ";
        printReverse(head);
        cout << endl;
    }

    bool isEmpty() const { return head == nullptr; }
};

int main() {
    // LinkedList<int> list;
    // int choice, value, position;

    LinkedList<string> list;
    int choice, position;
    string value;

    while (true) {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Print List\n";
        cout << "5. Print Reverse List\n";
        cout << "6. Delete Head\n";
        cout << "7. Delete from Position\n";
        cout << "8. Delete Tail\n";
        cout << "9. Sort List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtHead(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtTail(value);
                break;
            case 3:
                cout << "Enter position and value: ";
                cin >> position >> value;
                list.insertAtPosition(position, value);
                break;
            case 4:
                list.printList();
                break;
            case 5:
                list.printReverseList();
                break;
            case 6:
                list.deleteHead();
                break;
            case 7:
                cout << "Enter position: ";
                cin >> position;
                list.deleteAtPosition(position);
                break;
            case 8:
                list.deleteTail();
                break;
            case 9:
                list.selectionSort();
                cout << "List sorted.\n";
                break;
            case 0:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}