#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;
    int sum = 0;

    for (int i = 1; i < n; i++) {           // O(n)
        sum += i;                           // O(1) per iteration
    }
    // Total time: O(n), space: O(1)

    int arr[n];                             // array of size n → O(n) space
    for (int i = 1; i < n; i++) {           // O(n)
        sum += i;                           // O(1) per iteration
    }
    // Total time: O(n), additional space: O(n)

    return 0;
}
