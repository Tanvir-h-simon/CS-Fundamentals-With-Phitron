#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class myStack{
    private:
        vector<int> v;
    public: 
        void push(int value) { 
            // v.insert(v.begin(), value); // O(n): v[0] = Top element of the stack- Insert at front
            v.push_back(value); // O(1)
        }

        void pop() {
            if (empty()) {
                throw runtime_error("Stack underflow: cannot pop from empty stack");
            }
            // v.erase(v.begin()); // O(n): v[0] = Top element of the stack- Remove first element
            v.pop_back(); // O(1)
        } 

        int top() { // O(1)
            if (empty()) {
                throw runtime_error("Stack is empty: no top element");
            }
            // return v.front(); // v[0] = Top element of the stack
            return v.back();
        }

        int size() { // O(1)
            return v.size();
        }

        bool empty() { // O(1)
            // if (v.size() == 0) {
            //     return true;
            // } else {
            //     return false;
            // }
            return v.empty();
        }
};

int main() {
    myStack st;
    // st.push(10);
    // st.push(20);
    // st.push(30);

    // cout << st.top() << endl;

    // st.pop();

    // cout << st.top() << endl;

    // st.pop();

    // if (st.isEmpty() == false) {
    //     cout << st.top() << endl;
    // }

    cout << "Enter the size: ";
    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        st.push(x);
    }

    while(!st.empty()) { // (st.empty() == false)
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}