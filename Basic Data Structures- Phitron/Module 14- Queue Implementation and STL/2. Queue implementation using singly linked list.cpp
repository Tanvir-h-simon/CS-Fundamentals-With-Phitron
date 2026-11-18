#include <iostream>
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

class Queue {
    public:
        Node* head = NULL;
        Node* tail = NULL;

        int sz = 0;

    void push(int value) { // O(1)
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;

        }
        sz++;
    }

    void pop() { // O(1)
        sz--;
        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;
        if (head == NULL) {
            tail = NULL;
            return;
        }
    }

    int front() { // O(1)
        return head->value;
    }

    int size() { // O(1)
        return sz;
    }

    bool empty() { // O(1)
        if (sz == 0) return true;
        else return false;
    }

};

int main() {
    Queue qu;
    // qu.push(10);
    // qu.push(20);
    // qu.push(30);
    // cout << qu.front() << endl;
    // qu.pop();
    // cout << qu.front() << endl;
    // qu.pop();
    // cout << qu.front() << endl;
    cout << "Enter the size: ";
    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        qu.push(x);
    }
    
    while (!qu.empty()) {
        cout << qu.front() << endl;
        qu.pop();
    } 
    return 0;
}