#include <bits/stdc++.h>
using namespace std;

int main() {
    int size;
    cin >> size;
    // vector<int> v(size);
    // for (int i = 0; i < size; i++) {
    //     cin >> v[i];
    // }

    // for (int i = 0; i < size; i++) {
    //     cout << v[i] << " ";
    // }

    vector<int> v;
    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    
    return 0;
}