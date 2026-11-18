#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool hasDuplicateParentheses(string expr) {
    stack<char> s;

    for (char ch : expr) {
        if (ch == ')') {
            int count = 0;

            while (!s.empty() && s.top() != '(') {
                s.pop();
                count++;
            }

            if (count <= 1) {
                return true;
            }

            if (!s.empty()) s.pop();
        } 
        else {
            s.push(ch);
        }
    }

    // No duplicate found
    return false;
}

int main() {
    string expr;
    getline(cin, expr);

    if (hasDuplicateParentheses(expr))
        cout << "Duplicate parentheses found." << endl;
    else
        cout << "No duplicate parentheses." << endl;

    return 0;
}
