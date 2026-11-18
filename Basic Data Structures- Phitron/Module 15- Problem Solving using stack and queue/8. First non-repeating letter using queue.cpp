#include <iostream>
#include <queue>
#include <map>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;  // To store characters in order of appearance
    map<char, int> freq;  // To count frequency of each character

    for (char ch : str) {
        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (!q.empty())
            cout << q.front() << " ";
        else
            cout << "# "; // '#' means no non-repeating character yet
    }
    cout << endl;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    cout << "First non-repeating characters at each step:\n";
    firstNonRepeating(str);

    return 0;
}