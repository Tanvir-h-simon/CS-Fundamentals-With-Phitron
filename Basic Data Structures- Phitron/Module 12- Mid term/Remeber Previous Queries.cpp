#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> linkedList;
    int Q;
    cin >> Q;

    while (Q--) {
        int X, V;
        cin >> X >> V;

        if (X == 0) {
            linkedList.push_front(V); // Insert at head

            cout << "L -> ";
            for (auto it = linkedList.begin(); it != linkedList.end(); it++) {
                cout << *it << " ";
            }
            cout << endl;
            cout << "R -> ";
            for (auto it = linkedList.rbegin(); it != linkedList.rend(); it++) {
                cout << *it << " ";
            }
            cout << endl;
        } else if (X == 1) {
            linkedList.push_back(V); // Insert at tail

            cout << "L -> ";
            for (auto it = linkedList.begin(); it != linkedList.end(); it++) {
                cout << *it << " ";
            }
            cout << endl;
            cout << "R -> ";
            for (auto it = linkedList.rbegin(); it != linkedList.rend(); it++) {
                cout << *it << " ";
            }
            cout << endl;
        } else if (X == 2) { // Delete Vth index
            if (V < linkedList.size()){
                auto it = linkedList.begin();
                for (int i = 0; i < V; i++) {
                    it++;
                }
                linkedList.erase(it);
            }

            cout << "L -> ";
            for (auto it = linkedList.begin(); it != linkedList.end(); it++) {
                cout << *it << " ";
            }
            cout << endl;
            cout << "R -> ";
            for (auto it = linkedList.rbegin(); it != linkedList.rend(); it++) {
                cout << *it << " ";
            }
            cout << endl;
        } else {
            cout << "Invalid index";
        }
    }

    return 0;
}