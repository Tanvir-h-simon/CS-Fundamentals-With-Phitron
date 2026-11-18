#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; // O(1)
    cin >> n; // O(1)
    vector<int> a(n);
    for (int i = 0; i < n; i++) { 
        cin >> a[i];
    }

    int s = 0;
    for (int i = 0; i < n; i++) { // O(n)
        s += a[i];
    }
    
    cout << s << endl;
    
    return 0; // O(n)

    // Time Complexity = O(n)
}