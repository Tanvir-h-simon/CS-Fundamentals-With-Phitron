#include <iostream>
#include <stack>
using namespace std;

class Deque {
private:
    stack<int> frontStack, backStack;

    // Helper function to balance stacks when one is empty
    void balance() {
        if (frontStack.empty()) {
            int half = backStack.size() / 2;
            stack<int> temp;

            // Move half from backStack to temp (reverse order)
            for (int i = 0; i < half; i++) {
                temp.push(backStack.top());
                backStack.pop();
            }

            // Move remaining to frontStack (preserves order)
            while (!backStack.empty()) {
                frontStack.push(backStack.top());
                backStack.pop();
            }

            // Move back from temp to backStack
            while (!temp.empty()) {
                backStack.push(temp.top());
                temp.pop();
            }
        }
        else if (backStack.empty()) {
            int half = frontStack.size() / 2;
            stack<int> temp;

            // Move half from frontStack to temp (reverse order)
            for (int i = 0; i < half; i++) {
                temp.push(frontStack.top());
                frontStack.pop();
            }

            // Move remaining to backStack (preserves order)
            while (!frontStack.empty()) {
                backStack.push(frontStack.top());
                frontStack.pop();
            }

            // Move back from temp to frontStack
            while (!temp.empty()) {
                frontStack.push(temp.top());
                temp.pop();
            }
        }
    }

public:
    // Insert at front
    void pushFront(int x) {
        frontStack.push(x);
        cout << x << " inserted at front.\n";
    }

    // Insert at back
    void pushBack(int x) {
        backStack.push(x);
        cout << x << " inserted at back.\n";
    }

    // Remove from front
    void popFront() {
        if (frontStack.empty()) balance();

        if (frontStack.empty()) {
            cout << "Deque is empty.\n";
            return;
        }

        cout << frontStack.top() << " removed from front.\n";
        frontStack.pop();
    }

    // Remove from back
    void popBack() {
        if (backStack.empty()) balance();

        if (backStack.empty()) {
            cout << "Deque is empty.\n";
            return;
        }

        cout << backStack.top() << " removed from back.\n";
        backStack.pop();
    }

    // Get front element
    int getFront() {
        if (frontStack.empty()) balance();
        if (frontStack.empty()) {
            cout << "Deque is empty.\n";
            return -1;
        }
        return frontStack.top();
    }

    // Get back element
    int getBack() {
        if (backStack.empty()) balance();
        if (backStack.empty()) {
            cout << "Deque is empty.\n";
            return -1;
        }
        return backStack.top();
    }

    // Check if empty
    bool isEmpty() {
        return frontStack.empty() && backStack.empty();
    }

    // Display contents (for debugging)
    void display() {
        stack<int> f = frontStack, b = backStack;
        stack<int> temp;

        cout << "Deque: ";

        // Print front stack (reverse order)
        while (!f.empty()) {
            temp.push(f.top());
            f.pop();
        }
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }

        // Print back stack (normal order)
        while (!b.empty()) {
            cout << b.top() << " ";
            b.pop();
        }
        cout << endl;
    }
};

int main() {
    Deque dq;

    dq.pushBack(10);   // [10]
    dq.pushBack(20);   // [10, 20]
    dq.pushFront(5);   // [5, 10, 20]
    dq.display();

    dq.popFront();     // Removes 5
    dq.display();

    dq.popBack();      // Removes 20
    dq.display();

    dq.pushFront(100); // [100, 10]
    dq.display();

    cout << "Front: " << dq.getFront() << endl; // 100
    cout << "Back: " << dq.getBack() << endl;   // 10

    return 0;
}