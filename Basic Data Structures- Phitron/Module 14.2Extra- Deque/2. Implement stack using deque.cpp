#include <iostream>
#include <deque>
using namespace std;

class Queue {
private:
    deque<int> dq;

public:
    // Enqueue: insert element at the back
    void enqueue(int x) {
        dq.push_back(x);
        cout << x << " enqueued.\n";
    }

    // Dequeue: remove element from the front
    void dequeue() {
        if (dq.empty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << dq.front() << " dequeued.\n";
        dq.pop_front();
    }

    // Get the front element
    int front() {
        if (dq.empty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return dq.front();
    }

    // Check if queue is empty
    bool isEmpty() {
        return dq.empty();
    }

    // Display all elements
    void display() {
        if (dq.empty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int x : dq)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);  // dq: [10]
    q.enqueue(20);  // dq: [10, 20]
    q.enqueue(30);  // dq: [10, 20, 30]
    q.display();

    q.dequeue();    // removes 10 → dq: [20, 30]
    q.display();

    cout << "Front element: " << q.front() << endl; // 20
    cout << "Queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}