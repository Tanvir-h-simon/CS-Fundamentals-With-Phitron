#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t; // test case
    cin >> t;

    while (t--) {
        int n; // size of array
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // bool isSorted = true;
        // for (int i = 0; i < n; i++) { // O(n^2)
        //     for (int j = i + 1; j < n; j++) {
        //         if (arr[i] >= arr[j]) {
        //             isSorted = false;
        //         }
        //     }
        //     if (isSorted) break;
        // }

        bool isSorted = true;
        for (int i = 1; i < n; i++) { //O(n)
            if (arr[i] < arr[i - 1]) {
                isSorted = false;
                break;
            }
        }

        if (isSorted) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}