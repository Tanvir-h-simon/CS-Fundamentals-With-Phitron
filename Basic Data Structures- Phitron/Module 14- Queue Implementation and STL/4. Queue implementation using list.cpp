#include <iostream>
#include <list>
using namespace std;

class myQueue {
    private:
        list<int> l;
    public:
        void push(int value) {
            l.push_back(value);
        }
        void pop() {
            l.pop_front();
        }
        int top() {
            return l.front();
        }
        int size() {
            return l.size();
        }
        bool isEmpty() {
            if (l.size() == 0) {
                return true;
            } else {
                return false;
            }
        }      
};

int main() {
    myQueue qu;
    cout << "Enter the size: ";
    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        qu.push(x);
    }

    while (!qu.isEmpty()) {
        cout << qu.top() << endl;
        qu.pop();
    }
    return 0;
}