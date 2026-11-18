#include <iostream>
#include <vector>
using namespace std;

// Bruteforce solution
int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> arr(N + 1); // vector<int> arr(size, value);
    for (int i = 1; i <= N; i++) { // O(N)
        cin >> arr[i];
    }

    while (Q--) { // O(QN)
        int L, R;
        cin >> L >> R;

        int sum = 0;
        for (int i = L; i <= R; i++) {
            sum += arr[i];
        }
        cout << sum << endl;
    }

    // Time complexity: O(QN)

    return 0;
}