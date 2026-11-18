#include <iostream>
#include <stack>
using namespace std;

int main() {
    int T; // T = number of test cases
    cin >> T;



    while (T--) {
        string S;
        cin >> S;

        stack<char> st;

        for (char ch: S) { // Loop through every character of the string
            if (!st.empty() && (ch == '1' && st.top() == '0')) {
                st.pop(); // Eliminate pair 01
            } else {
                st.push(ch); // If stack is empty or don't match the logic, push the character onto the stack
            }
        }

        if (st.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}