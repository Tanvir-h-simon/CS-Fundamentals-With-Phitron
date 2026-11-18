#include <iostream>
#include <stdexcept>
using namespace std;

class Node {
    public:
        Node* next;
        Node* prev;
        int value;

    Node(int value) {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Stack {
    public:
        Node* head = NULL;
        Node* tail = NULL;
        int count = 0; 

    void push (int value) { // O(1)
        count++; 

        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = tail->next;
    }

    // void pop() {  // O(1): Head = Top element of the stack
    //     if (head == NULL) {  
    //         throw runtime_error ("Stack is empty, cannot pop.\n");
    //     }
        
    //     Node* deleteNode = head;
    //     head = head->next;
    //     if (head == NULL) {
    //         tail = NULL;
    //     } else {
    //         head->prev = NULL;
    //     }
    //     delete deleteNode;
    //     count--;
    // }

    
    void pop() {  // O(1): Tail = Top element of the stack
        if (head == NULL) {  
            throw runtime_error ("Stack is empty, cannot pop.\n");
        }

        Node* deleteNode = tail;
        tail = tail->prev;
        if (tail == NULL) {
            head = NULL;
        } else {
            tail->next = NULL;
        }
        delete deleteNode;
        count--;
    }

    int top() {  // O(1)
        if (empty()) {
            throw runtime_error("Stack is empty, cannot top.\n");
            // cout << "Stack is empty, cannot top.\n";
            // return -1;
        }
        // return head->value;
        return tail->value;
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
        return (count == 0);
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