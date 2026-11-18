#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_front(2); // dq: [2]
    dq.push_front(1);  // dq: [1, 2]

    dq.push_back(3);  // dq: [1, 2, 3]
    dq.push_back(4);  // dq: [1, 2, 3, 4]

    dq.pop_back();  // removes 4 → dq: [1, 2, 3]
    dq.pop_front();  // removes 1 → dq: [2, 3]

    cout << dq.front() << endl;  // Output: 2
    cout << dq.back() << endl;  // Output: 3

    return 0;
}
