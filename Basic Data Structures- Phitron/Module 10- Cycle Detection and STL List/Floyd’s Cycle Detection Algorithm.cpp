#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    Node* prev;
    int value;

    Node(int value) {
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
        head = NULL;
        tail = NULL;
        size = 0;
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

    // Create cycle in 'next' pointers
    void create_cycle(int pos) {
        if (pos < 0) return;
        Node* cycleNode = NULL;
        Node* temp = head;
        int index = 0;
        while (temp->next != NULL) {
            if (index == pos) cycleNode = temp;
            temp = temp->next;
            index++;
        }
        if (cycleNode != NULL) {
            temp->next = cycleNode;   // forward link creates cycle
            cycleNode->prev = temp;   // maintain prev pointer
        }
    }

    // Detect cycle using Floyd's algorithm
    bool has_cycle() {
        if (head == NULL || head->next == NULL) return false;

        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;         // move 1 step
            fast = fast->next->next;   // move 2 steps

            if (slow == fast) {
                return true; // cycle detected
            }
        }
        return false; // no cycle
    }

    // Find starting node of the cycle
    Node* cycle_start_node() {
        if (!has_cycle()) return NULL;

        Node* slow = head;
        Node* fast = head;

        // First find meeting point
        do {
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        // Move one pointer to head
        slow = head;

        // Move both one step until they meet
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow; // starting node of cycle
    }

    void print_forward(int limit = 20) { // limit prevents infinite loop if cycle
        Node* current = head;
        int count = 0;
        while (current != NULL && count < limit) {
            cout << current->value << "->";
            current = current->next;
            count++;
        }
        cout << (count == limit ? "..." : "NULL") << endl;
    }
};

int main() {
    DoublyLinkedlist list;

    // Insert some nodes
    list.insert_at_tail(1);
    list.insert_at_tail(2);
    list.insert_at_tail(3);
    list.insert_at_tail(4);
    list.insert_at_tail(5);

    // Create a cycle: tail connects to node at index 2 (value 3)
    list.create_cycle(2);

    // Test cycle detection
    if (list.has_cycle()) {
        cout << "Cycle detected!" << endl;
        Node* start = list.cycle_start_node();
        if (start != NULL) {
            cout << "Cycle starts at node with value: " << start->value << endl;
        }
    } else {
        cout << "No cycle detected." << endl;
    }

    // Try to print (will stop at limit if cycle exists)
    list.print_forward();

    return 0;
}