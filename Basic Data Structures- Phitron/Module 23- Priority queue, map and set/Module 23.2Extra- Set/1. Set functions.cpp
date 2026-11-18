#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;

    s.insert(30);
    s.insert(10);
    s.insert(20);

    cout << "Elements: ";
    for (int x : s) cout << x << " ";

    cout << "\nSize: " << s.size();

    auto it = s.find(20);
    if (it != s.end()) cout << "\nFound: " << *it;

    s.erase(10);
    cout << "\nAfter erase: ";
    for (int x : s) cout << x << " ";

    cout << "\nLower bound(25): " << *s.lower_bound(25);
}