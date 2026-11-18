#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> m;
    m["Hello"] = 1; // log(n)
    m["Hi"] = 2;
    m["Hey"] = 3;

    // cout << m["Hello"] << endl;
    // cout << m["Welcome"] << endl;

    for (auto it = m.begin(); it != m.end(); it++) { // O(n logn)
        cout << it->first << " " << it->second << endl; 
    }

    return 0;
}