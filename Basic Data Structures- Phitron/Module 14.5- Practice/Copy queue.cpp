#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> q1, q2;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        q1.push(x);
    }

    // Copy to q2 to reverse the order
    // while (!q1.empty()) {
    //     q2.push(q1.front());
    //     q1.pop();
    // }

    stack<int> s; 

    // Move elements from q1 to stack
    while (!q1.empty()) {
        s.push(q1.front());
        q1.pop();
    }

    // Move elements from stack to q2
    while (!s.empty()) {
        q2.push(s.top());
        s.pop();
    }

    while (!q2.empty()) {
        cout << q2.front() << " ";
        q2.pop();
    }

    return 0;
}