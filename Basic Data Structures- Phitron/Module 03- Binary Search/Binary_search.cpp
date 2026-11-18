#include <bits/stdc++.h>
using namespace std;

int main() {
    // int size_array, query; // query = number of values you're going to search for in the array.
    // cin >> size_array >> query;
    // int arr[size_array];

    // for (int i = 0; i < size_array; i++){
    //     cin >> arr[i];
    // }

    // while(query--) {
    //     int x;
    //     cin >> x;
    //     bool flag = false;
    //     for (int i = 0; i <size_array; i++) {
    //         if (arr[i] == x) {
    //             flag = true; // isfound
    //             break;
    //         }
    //     }
    //     if (flag == true) {
    //         cout << "Found" << endl;
    //     } else {
    //         cout << "Not Found" << endl;
    //     }
    // }

    int arr_length;
    cin >> arr_length;
    
    int arr[arr_length]; //Sorted array
    for (int i = 0; i < arr_length; i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    int left = 0; // Left index is the 0th index
    int right = arr_length - 1; // Right index is the last index of the array

    bool isFound = false;
    while (left <= right) {
        int mid = (left + right) / 2; // Mid index of the array
        if (arr[mid] == x) {
            isFound = true;
            break;
        }
        if (x > arr[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (isFound == true) {
        cout << "Found" << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}