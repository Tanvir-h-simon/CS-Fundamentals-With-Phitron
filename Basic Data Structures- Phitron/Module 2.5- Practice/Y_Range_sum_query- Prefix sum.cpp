#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<long long> arr(N + 1); // vector<int> arr(size, value);
    for (int i = 1; i <= N; i++) { //  O(N)
        cin >> arr[i];
    }

    vector<long long> prefix(N + 1); 
    for (int i = 1; i <= N; i++) { //  O(N)
        prefix[i] = prefix[i - 1] + arr[i];
    }

    while (Q--) { // O(1)
        int L, R;
        cin >> L >> R;

        long long sum = prefix[R] - prefix[L - 1];
        cout << sum << endl;
    }

    // Time Complexity: O(Q)

    return 0;
}