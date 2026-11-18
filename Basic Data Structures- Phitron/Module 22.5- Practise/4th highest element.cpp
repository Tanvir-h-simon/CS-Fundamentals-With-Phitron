#include <iostream>
#include <algorithm>
using namespace std;


int getFourthLargest(int arr[], int n) {
    sort(arr, arr + n); // Ascending order

    int forthHighest = arr[n - 4];
    
    if (n < 4) return -2147483648;
    else return forthHighest;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    cout << getFourthLargest(arr, n);    

    return 0;
}