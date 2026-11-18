#include <iostream>
#include <algorithm>
using namespace std;

bool isPileOfWord(string a, string b) {
    if (a.size() != b.size()) {
        return false;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    return a == b;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << (isPileOfWord(s1, s2) ? "YES" : "NO") << endl;
    }
    return 0;
}