#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    // while (t--) {
    //     int n;
    //     cin >> n;
        
    //     vector<int> heights(n);
    //     for (int i = 0; i < n; i++) {
    //         cin >> heights[i];
    //     }
        
    //     int maxHeight = 0;
    //     int leftIndex = 0, rightIndex = 0;
        
    //     // Check all pairs to find maximum water height
    //     for (int i = 0; i < n; i++) {
    //         for (int j = i + 1; j < n; j++) {
    //             int currentHeight = min(heights[i], heights[j]);
                
    //             if (currentHeight > maxHeight || 
    //                 (currentHeight == maxHeight && i < leftIndex) ||
    //                 (currentHeight == maxHeight && i == leftIndex && j < rightIndex)) {
    //                 maxHeight = currentHeight;
    //                 leftIndex = i;
    //                 rightIndex = j;
    //             }
    //         }
    //     }
        
    //     cout << leftIndex << " " << rightIndex << endl;
    // }

    // while (t--) {
    //     int n;
    //     cin >> n;
        
    //     vector<int> heights(n);
    //     for (int i = 0; i < n; i++) {
    //         cin >> heights[i];
    //     }
        
    //     int maxHeight = 0;
    //     int leftIndex = 0, rightIndex = 0;
        
    //     // Two pointer approach
    //     int left = 0, right = n - 1;
        
    //     while (left < right) {
    //         int currentHeight = min(heights[left], heights[right]);
            
    //         if (currentHeight > maxHeight) {
    //             maxHeight = currentHeight;
    //             leftIndex = left;
    //             rightIndex = right;
    //         }
            
    //         // Move the pointer with smaller height
    //         if (heights[left] < heights[right]) {
    //             left++;
    //         } else {
    //             right--;
    //         }
    //     }
        
    //     cout << leftIndex << " " << rightIndex << endl;
    // }

    while (t--) {
        int N;
        cin >> N;
        vector<int> H(N);
        for (int i = 0; i < N; i++) {
            cin >> H[i];
        }
        
        int firstValue = -1;
        int secondValue = -1;
        int firstIndex = -1;
        int secondIndex = -1;
        
        for (int i = 0; i < N; i++) {
            if (H[i] > firstValue) {
                secondValue = firstValue;
                secondIndex = firstIndex;
                firstValue = H[i];
                firstIndex = i;
            } else if (H[i] > secondValue) {
                secondValue = H[i];
                secondIndex = i;
            }
        }
        
        if (firstIndex < secondIndex) {
            cout << firstIndex << " " << secondIndex << endl;
        } else {
            cout << secondIndex << " " << firstIndex << endl;
        }
    }
    return 0;
}