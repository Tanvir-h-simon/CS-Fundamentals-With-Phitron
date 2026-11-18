#include <iostream>
#include <set>
using namespace std;

int main() {
    string word;
    cin >> word; 

    set<char> seen;

    string substring = "";
    for (char ch : word) {
        if (seen.count(ch)) break; // Returns: 1 → if the value exists in the set, 0 → if the value does not exist
        seen.insert(ch);
        substring += ch;
    }
    cout << substring << endl;

    return 0;
}