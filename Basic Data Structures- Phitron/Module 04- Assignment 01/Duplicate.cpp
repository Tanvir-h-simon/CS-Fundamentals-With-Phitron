#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end()); // O(n log n)
    bool isFound = false;
    for (int i = 1; i < n; i++) {// O(n) // Loop index starts from 2nd index (i = 1)
        if (arr[i] == arr[i - 1]) {
            isFound = true;
            break;
        }
    }
    
    // bool isFound = false;
    // for (int i = 0; i < n; i++) { // O(n^2)
    //     for (int j = i + 1; j < n; j++) {
    //         if (arr[i] == arr[j]) {
    //             isFound = true;
    //             break;
    //         }
    //     }
    //     if (isFound) break;
    // }

    if (isFound) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }


    return 0;
}