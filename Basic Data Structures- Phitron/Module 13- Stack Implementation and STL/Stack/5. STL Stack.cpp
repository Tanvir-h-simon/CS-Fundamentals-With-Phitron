#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;
    // st.push(10);
    // st.push(20);

    // cout << st.top() << endl;
    // st.pop();
    // cout << st.top() << endl;
    // st.pop();
    // if (!st.empty()) {
    //     st.top();
    // }
    // if (!st.empty()) {
    //     st.pop();
    // }
    cout << "Enter the size: ";
    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        st.push(x);
    }
    
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    } 
    return 0;
}