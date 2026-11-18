#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {           // O(n)
        for (int j = 1; j < n; j *= 2) {    // O(log n)
            cout << "(" << i << ", " << j << ")" << endl;
        }
    }

    // Time Complexity = O(n) x O(log n) = O(n log(n))

    return 0;
}