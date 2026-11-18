#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;

    stack<int> s1, s2;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        s1.push(x);
    }

    // Copy to s2 to reverse the order
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    
    // Print elements in insertion order
    while (!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }

    return 0;
}