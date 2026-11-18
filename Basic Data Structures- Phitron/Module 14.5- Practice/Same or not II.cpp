#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;

    stack<int> s;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        s.push(x);
    }

    int M;
    cin >> M;
    queue<int> q;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

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