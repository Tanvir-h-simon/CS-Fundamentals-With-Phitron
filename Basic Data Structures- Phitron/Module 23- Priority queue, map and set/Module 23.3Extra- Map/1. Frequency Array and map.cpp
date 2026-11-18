#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int arr[n];
    
    cout << "Enter " << n << " elements (Between 1 and 100000): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // // // Frequency array to store count of each element
    // // int freq[n];
    // // // Array to track which elements are already counted
    // // bool visited[n];
    // // for (int i = 0; i < n; i++) {
    // //     visited[i] = false;
    // //     freq[i] = 0;
    // // }

    // int freq[n] = {false};
    // bool visited[n] = {0};
    
    // // Calculate frequencies
    // for (int i = 0; i < n; i++) {
    //     if (visited[i] == true) // Skip if already counted
    //         continue;
        
    //     // Count frequency of arr[i]
    //     int count = 1;
    //     for (int j = i + 1; j < n; j++) {
    //         if (arr[i] == arr[j]) {
    //             count++;
    //             visited[j] = true;
    //         }
    //     }
        
    //     // Store frequency in frequency array
    //     freq[i] = count;
    // }
    
    // for (int i = 0; i < n; i++) {
    //     if (freq[i] != 0) {
    //         cout << arr[i] << " appears " << freq[i] << " time(s)" << endl;
    //     }
    // }

    // Map to store frequency (key = element, value = frequency)
    map<int, int> freq;
    
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    
    for (auto it : freq) {
        cout << it.first << " appears " << it.second << " time(s)" << endl;
    }
    
    return 0;
}