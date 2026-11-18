#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i]; 
    }

    int leftSum = 0, rightSum = 0;
    for (int i = 0; i < n; i++) { 
        // leftSum += arr[i];
        rightSum = totalSum - leftSum - arr[i];
        
        if (leftSum == rightSum) {
            cout << i << endl;
            return 0; // If found the index, stop the program
        }
        leftSum += arr[i];
    }

    return 0;
}