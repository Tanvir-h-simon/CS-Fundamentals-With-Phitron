#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // for (int i = 1; i <= sqrt(n); i++) { // O(sqrt(n))
    //     cout << i << " ";
    // }

    // cout << endl;

    // Find divisor

    // for (int i = 1; i <= n; i++) { // O(n)
    //     if (n % i == 0) {
    //         cout << i << " "; 
    //     }
    // }

    // cout << endl;

    for (int i = 1; i <= sqrt(n); i++) { // Optimized code- O(sqrt(n))
        if (n % i == 0) {
            cout << i << " "; 
            if (i != n / i) { 
                cout << n / i << " ";
            }
        }    
    }

    cout << endl;

    return 0;
}