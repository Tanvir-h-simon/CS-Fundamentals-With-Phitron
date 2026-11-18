#include <iostream>
#include <deque>
using namespace std;

class Stack {
private:
    deque<int> dq;

public:
    // Push element onto stack
    void push(int x) {
        dq.push_back(x);   // push at the back (top of stack)
        cout << x << " pushed to stack.\n";
    }

    // Pop element from stack
    void pop() {
        if (dq.empty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << dq.back() << " popped from stack.\n";
        dq.pop_back();
    }

    // Get top element
    int top() {
        if (dq.empty()) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return dq.back();
    }

    // Check if stack is empty
    bool isEmpty() {
        return dq.empty();
    }

    // Display stack elements
    void display() {
        if (dq.empty()) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack (top to bottom): ";
        for (auto it = dq.rbegin(); it != dq.rend(); ++it)
            cout << *it << " ";
        cout << endl;
    }
};

int main() {
    Stack st;

    st.push(10);  // Stack: [10]
    st.push(20);  // Stack: [10, 20]
    st.push(30);  // Stack: [10, 20, 30]
    st.display();

    st.pop();     // removes 30 → Stack: [10, 20]
    st.display();

    cout << "Top element: " << st.top() << endl;  // 20
    cout << "Stack empty? " << (st.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}