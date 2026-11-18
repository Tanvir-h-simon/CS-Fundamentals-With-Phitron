#include <iostream>
#include <queue>
using namespace std;

class Stack {
private:
    queue<int> q;

public:
    void push(int value) {
        q.push(value);

        for (int i = 1; i < q.size(); i++) {
            int frontValue = q.front();
            q.pop();
            q.push(frontValue);
        }

        /* 
        Step-by-Step Execution
        Start:
        q = []
        push(1):
        q.push(1) → q = [1]
        Loop: q.size() = 1, so for loop doesn’t run.
        Final:
        q = [1]
        Stack top = 1

        push(2):
        q.push(2) → q = [1, 2]
        Loop runs once (i = 1):
        frontValue = 1
        Pop 1, push 1 → q = [2, 1]
        Final:
        q = [2, 1]
        Stack top = 2

        push(3):
        q.push(3) → q = [2, 1, 3]
        Loop runs twice (i = 1, 2):
        First iteration: pop 2, push 2 → q = [1, 3, 2]
        Second iteration: pop 1, push 1 → q = [3, 2, 1]
        Final:
        q = [3, 2, 1]
        Stack top = 3
        */ 
    }

    void pop() {
        if (q.empty()) return;

        q.pop();
    }

    int top() {
        if (q.empty()) return -1;

        return q.front();
    }

    int size() {
         return q.size(); 
    }

    int empty() {
        return q.empty();
    }
};


int main() {
    Stack s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    int value;
    while (cin >> value && value != -1) {
        s.push(value);
    }

    // cout << s.top() << endl;
    // s.pop();
    // cout << s.top() << endl;
    // s.pop();
    // cout << s.top() << endl;

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}