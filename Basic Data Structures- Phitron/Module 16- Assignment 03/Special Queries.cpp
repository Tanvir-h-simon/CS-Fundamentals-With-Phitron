#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    queue<string> q; // Store names

    while(Q--) {
        int command;
        cin >> command;

        if (command == 0) { // A person enters the line
            string name;
            cin >> name; 
            q.push(name); // Enqueue the name
        } else if (command == 1) {
            if (!q.empty()) {
                cout << q.front() << endl;
                q.pop();
            } else {
                cout << "Invalid" << endl;
            }
        } else {
            cout << "Invalid input" << endl;
        }
    }

    return 0;
}