#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    int n;
    cin >> n;

    while (n--) {
        int value;
        cin >> value;
        s.insert(value);
    }

    for (auto it = s.begin(); it != s.end(); it++) { // O(logn)
        cout << *it << " "; 
    }

    if (s.count(5)) cout << "\nFound";
    else cout << "\nNot found";

    return 0;
}