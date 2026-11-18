#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // for (int i = 1; i <= n; i++) { // O(n)
    //     for (int j = 1; j <= n; j++) { // O(n)
    //         cout << "(" << i << ", " << j << ")" << endl;
    //     }
    // }

    // // Time Complexity = O(n) x O(n) = O(n^2) 

    for (int i = 1; i <= n; i++) {         // O(n)
        for (int j = 1; j <= n; j++) {     // O(n)
            for (int k = 1; k <= n; k++) { // O(n)
                cout << "(" << i << ", " << j << ", " << k << ")" << endl;
            }
        }
    }

    // Time Complexity = O(n) x O(n) x O(n) = O(n^3)
    return 0;
}