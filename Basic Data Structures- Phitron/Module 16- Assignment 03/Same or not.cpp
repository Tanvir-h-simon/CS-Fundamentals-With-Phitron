#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    stack<int> s;
    // while (N--) {
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        s.push(x);
    }

    // while (!s.empty()) {
    //     cout << s.top() << " ";
    //     s.pop();
    // } 
    // cout << endl;

    queue<int> q;
    // while (M--) {
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    // while (!q.empty()) {
    //     cout << q.front() << " ";
    //     q.pop();
    // } 
    // cout << endl;

    if (N != M) {
        cout << "NO";
        return 0;
    }

    bool isEqual = true;
    if (M == N) {
        while (!s.empty() && !q.empty()) {
            if (s.top() != q.front()) {
                isEqual = false;
                break;
            }
            s.pop();
            q.pop();
        } 
    }

    if (isEqual) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}