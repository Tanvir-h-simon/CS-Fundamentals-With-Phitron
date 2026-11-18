#include <iostream>
#include <stdexcept>
using namespace std;

class Node {
    public:
        Node* next;
        int value;

    Node(int value) {
        this->value = value;
        this->next = NULL;
    }
};

class Stack {
    public:
        Node* head = NULL;
        // Node* tail = NULL;
        int count = 0; 

    void push (int value) { // O(1)
        Node* newNode = new Node(value);

        // if (head == NULL) {
        //     head = newNode;
        //     // tail = newNode;
        // } else {
        //     newNode->next = head;
        //     head = newNode;
        // }

        newNode->next = head;
        head = newNode;

        count++; 
    }

    // void pop() {  // O(n): Tail = Top element
    //     if (head == NULL) {
    //         throw runtime_error("Stack is empty, cannot pop.\n");
    //     }
    //     if (head == tail) {
    //         delete head;
    //         head = tail = NULL;
    //     } else {
    //         Node* current = head;
    //         while (current->next != tail) {  // traverse until node before tail
    //             current = current->next;
    //         }
    //         delete tail;
    //         tail = current;
    //         tail->next = NULL;
    //     }
    //     count--;
    // }

    void pop() {  // O(1): Head = Top element of the stack (no need to track tail)
        if (head == NULL) {  
            throw runtime_error ("Stack is empty, cannot pop.\n");
        }
        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;
        // if (head == NULL) tail = NULL;
        count--;
    }

    int top() {  // O(1)
        if (empty()) {
            throw runtime_error("Stack is empty, cannot top.\n");
            // cout << "Stack is empty, cannot top.\n";
            // return -1;
        }
        // return tail->value;
        return head->value;
    }

    int size() {  // O(1)
        return count;
    }

    bool empty() {  // O(1)
        // if (count == 0) {
        //     return true;
        // } else {
        //     return false;
        // }
        return count == 0;
    }
};

int main() {
    Stack st;
    cout << "Enter the size: ";
    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        st.push(x);
    }

    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}