#include <iostream>
#include <vector>
using namespace std;


// vector<int> calculatePrefixSum(vector<int> arr) // Pass by value- has significant drawbacks
vector<int> runningSum (vector<int> &arr) { // Pass by reference
    int size = arr.size();

    // To store prefix sum
    vector<int> prefixSum(size);
    // Initialize the prefix sum
    prefixSum[0] = arr[0];

    for (int i = 1; i < size; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    return prefixSum;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> prefixSum = runningSum(arr);
    for (int i : prefixSum) {
        cout << i << " ";
    }

    return 0;
}