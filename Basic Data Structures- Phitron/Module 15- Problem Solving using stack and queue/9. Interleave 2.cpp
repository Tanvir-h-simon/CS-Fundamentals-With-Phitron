#include <iostream>
#include <queue>
using namespace std;

queue<int> interleaveQueues(queue<int>& q1, queue<int>& q2) {
    queue<int> result;

    while (!q1.empty() || !q2.empty()) {
        if (!q1.empty()) {
            result.push(q1.front());
            q1.pop();
        }
        if (!q2.empty()) {
            result.push(q2.front());
            q2.pop();
        }
    }

    return result;
}

int main() {
    queue<int> q1, q2;

    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);

    q2.push(5);
    q2.push(6);
    q2.push(7);
    q2.push(8);

    queue<int> result = interleaveQueues(q1, q2);

    cout << "Interleaved Queue: ";
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
    cout << endl;

    return 0;
}