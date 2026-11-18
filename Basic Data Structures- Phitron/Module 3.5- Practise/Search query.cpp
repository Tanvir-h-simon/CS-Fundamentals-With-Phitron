#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >>  arr[i];
    }

    int q;
    cin >> q;

    int value;
    for (int i = 0; i < q; i++) {
        cin >> value;
        bool isFound = false;
        
        for (int j = 0; j < n; j++) {
            if (value == arr[j]) {
                isFound = true;
            }
        }

        if (isFound) {
            cout << "YES" << " ";
        } else {
            cout << "NO" << " ";
        }
    }

    return 0;
}