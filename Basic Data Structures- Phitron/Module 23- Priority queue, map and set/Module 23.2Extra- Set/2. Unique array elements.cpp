#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    // int arr[] = {5, 2, 5, 8, 2, 1, 8};
    // int size = sizeof(arr) / sizeof(arr[0]);

    // set<int> uniqueElements;

    // // for (int i = 0; i < size; i++) {
    // //     uniqueElements.insert(arr[i]); // duplicates ignored
    // // }

    // set<int> uniqueElements(arr, arr + size);

    vector<int> arr = {5, 2, 5, 8, 2, 1, 8};

    set<int> uniqueElements(arr.begin(), arr.end());

    cout << "Unique elements: ";
    // for(int i = 0; i < uniqueElements.size(); i++) { // Error- set does not support indexing 
    for (int num : uniqueElements) { 
        cout << num << " ";
    }

    return 0;
}