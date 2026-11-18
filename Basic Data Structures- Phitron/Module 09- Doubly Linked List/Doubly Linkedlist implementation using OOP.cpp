#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T value;
    Node* next;
    Node* prev;

    // Node (T value) {
    //     this->value = value;
    //     this->next = NULL;
    //     this->prev = NULL;
    // }
    Node(T val) : value(val), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    // DoublyLinkedList() {
    //     this->head = NULL;
    //     this->tail = NULL;
    //     this->size = 0;
    // }
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void insertAtHead(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void insertAtTail(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void insertAtPosition(int index, T value) {
        if (index < 0 || index > size) throw runtime_error("Invalid index");

        if (index == 0) {
            insertAtHead(value);
        } else if (index == size) {
            insertAtTail(value);
        } else {
            Node<T>* newNode = new Node<T>(value);
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next->prev = newNode;
            current->next = newNode;
            newNode->prev = current;
            size++;
        }
    }

    void deleteHead() {
        if (!head) return;
        Node<T>* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

    void deleteTail() {
        if (!head) return;
        Node<T>* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        size--;
    }

    void deleteFromPosition(int index) {
        if (index < 0 || index >= size) throw runtime_error("Invalid index");

        if (index == 0) {
            deleteHead();
        } else if (index == size - 1) {
            deleteTail();
        } else {
            Node<T>* current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            size--;
        }
    }

    void printForward() {
        Node<T>* current = head;
        while (current) {
            cout << current->value << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }

    void printBackward() {
        Node<T>* current = tail;
        while (current) {
            cout << current->value << " -> ";
            current = current->prev;
        }
        cout << "NULL\n";
    }

    int getSize() const { return size; }

    bool search(T value) {
        Node<T>* current = head;
        while (current) {
            if (current->value == value) return true;
            current = current->next;
        }
        return false;
    }
};

int main() {
    // DoublyLinkedList<int> list;
    // int choice, index, value;

    DoublyLinkedList<string> list;
    int choice, index;
    string value;

    do {
        cout << "\n1. Insert at Head\n2. Insert at Tail\n3. Insert at Position\n4. Delete Head\n5. Delete Tail\n6. Delete from Position\n7. Print Forward\n8. Print Backward\n9. Search\n0. Exit\n";
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
            cout << "Enter index and value: ";
            cin >> index >> value;
            list.insertAtPosition(index, value);
            break;
        case 4:
            list.deleteHead();
            break;
        case 5:
            list.deleteTail();
            break;
        case 6:
            cout << "Enter index: ";
            cin >> index;
            list.deleteFromPosition(index);
            break;
        case 7:
            list.printForward();
            break;
        case 8:
            list.printBackward();
            break;
        case 9:
            cout << "Enter value: ";
            cin >> value;
            cout << (list.search(value) ? "Found\n" : "Not Found\n");
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}