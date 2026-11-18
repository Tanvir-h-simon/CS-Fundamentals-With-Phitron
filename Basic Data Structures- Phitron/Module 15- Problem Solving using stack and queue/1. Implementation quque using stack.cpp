#include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> s1, s2;
public:
    void push(int value) {
        s1.push(value);

        while (!s1.empty()) {
            int topElemenet = s1.top();
            s2.push(topElemenet);
            s1.pop();
        }
    }

    void pop() {
        s2.pop();
    }

    int front() {
        return s2.top();
    }

    int size() {
        return s2.size();
    }
    
    int empty() {
        return s1.empty() && s2.empty();
    }

};

int main() {
    Queue q;
    int value;
    while (cin >> value && value != -1) {
        q.push(value);
    }

    while (q.size() > 0) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}