#include <iostream>
#include <string>
#include <stack>
using namespace std;

string reverseString(string str) { // O(n)
    string revered;
    stack<char> s;

    for (char ch : str) {
        s.push(ch);
    }
    
    while (!s.empty()) {
        char top = s.top();
        revered += top;
        s.pop();
    }

    return revered;

}

int main() {
    string str;
    cin >> str;

    cout << reverseString(str);

    return 0;
}