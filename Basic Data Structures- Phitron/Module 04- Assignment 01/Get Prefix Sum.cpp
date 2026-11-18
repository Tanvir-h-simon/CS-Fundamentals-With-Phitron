#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<long long> prefixSum(n);

    // Initialize the prefix sum
    prefixSum[0] = arr[0]; // Beacase the loop start from 2nd index (i = 1)

    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        cout << prefixSum[i] << " ";
    }
    return 0;
}