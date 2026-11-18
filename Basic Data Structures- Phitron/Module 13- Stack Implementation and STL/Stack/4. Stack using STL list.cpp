#include <iostream>
#include <list>
using namespace std;

class myStack {
    private:
        list<int> l;
    public:
        void push(int value) {
            l.push_back(value);
        }
        void pop() {
            l.pop_back();
        }
        int top() {
            return  l.back();
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
    myStack st;
    cout << "Enter the size: ";
    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        st.push(x);
    }

    while (!st.isEmpty()) {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}