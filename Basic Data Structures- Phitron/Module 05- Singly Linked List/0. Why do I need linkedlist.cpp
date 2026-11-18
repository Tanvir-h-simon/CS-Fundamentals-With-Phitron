#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5}; 
    for (int i = 0; i < 5; i++) {
        cout << &arr[i] << endl; // Array takes sequential memory
    }

    cout << endl;

    vector<int> v = {1, 2, 3, 4};
    v.push_back(5); // vector capacity growth almost double
    for (int i = 0; i < 5; i++) {
        cout << &v[i] << endl; // Array, even vector takes sequential memory
    }
    return 0;
}