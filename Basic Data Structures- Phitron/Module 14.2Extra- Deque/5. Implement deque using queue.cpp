#include <iostream>
#include <queue>
using namespace std;

class Deque {
private:
    queue<int> q1, q2; // Two queues used to simulate a deque

public:
    // Insert at rear
    void pushBack(int x) {
        q1.push(x);
        cout << x << " inserted at back.\n";
    }

    // Insert at front
    void pushFront(int x) {
        q2.push(x);

        // Move all elements of q1 behind the new element
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);

        cout << x << " inserted at front.\n";
    }

    // Delete from front
    void popFront() {
        if (q1.empty()) {
            cout << "Deque is empty.\n";
            return;
        }
        cout << q1.front() << " removed from front.\n";
        q1.pop();
    }

    // Delete from back
    void popBack() {
        if (q1.empty()) {
            cout << "Deque is empty.\n";
            return;
        }

        // Move all elements except the last to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        cout << q1.front() << " removed from back.\n";
        q1.pop();

        // Swap queues
        swap(q1, q2);
    }

    // Get front element
    int getFront() {
        if (q1.empty()) {
            cout << "Deque is empty.\n";
            return -1;
        }
        return q1.front();
    }

    // Get back element
    int getBack() {
        if (q1.empty()) {
            cout << "Deque is empty.\n";
            return -1;
        }

        int backVal;
        while (!q1.empty()) {
            backVal = q1.front();
            q2.push(backVal);
            q1.pop();
        }

        swap(q1, q2);
        return backVal;
    }

    // Check if empty
    bool isEmpty() {
        return q1.empty();
    }

    // Display elements
    void display() {
        if (q1.empty()) {
            cout << "Deque is empty.\n";
            return;
        }

        queue<int> temp = q1;
        cout << "Deque: ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    Deque dq;

    dq.pushBack(10);   // Deque: [10]
    dq.pushBack(20);   // Deque: [10, 20]
    dq.pushFront(5);   // Deque: [5, 10, 20]
    dq.display();

    dq.popFront();     // Removes 5 → [10, 20]
    dq.display();

    dq.popBack();      // Removes 20 → [10]
    dq.display();

    cout << "Front: " << dq.getFront() << endl; // 10
    cout << "Back: " << dq.getBack() << endl;   // 10

    return 0;
}