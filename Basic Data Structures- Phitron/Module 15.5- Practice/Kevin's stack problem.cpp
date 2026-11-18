#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int T; 
    cin >> T; // Number of test cases
    
    while (T--) {
        string S;
        cin >> S;
        
        stack<char> st;

        // Push all characters of S into stack
        for (char c : S) {
            st.push(c);
        }

        // Pop characters to form reversed string
        string reversed = "";
        while (!st.empty()) {
            reversed += st.top();
            st.pop();
        }

        cout << reversed << endl;
    }

    return 0;
}