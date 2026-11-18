#include <bits\stdc++.h>
using namespace std;

int main() {
    int n; // O(1)
    cin >> n; // O(1)

    for (int i = 1; i <= n; i *= 2) { // O(log n)
        cout << i << " ";
    }

    cout << endl;

    for (int i = n; i >= 1; i /= 2) { // O(log n)
        cout << i << " ";
    }

    cout << endl;

    for (int i = 1; i <= n; i += 2) { // O(n)
        cout << i << " ";
    }

    cout << endl;

    return 0; // 0(1)

    // Time Complexity: O(log n) + O(log n) + O(n) = O(n) (since n dominates log n)
}