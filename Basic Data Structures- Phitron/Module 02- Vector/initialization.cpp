#include <bits/stdc++.h>
using namespace std;

int main() {
    // vector<int> v;
    // vector<int> v(5);
    int a[6] = {1, 2, 3, 4, 5};
    vector<int> v(a, a + 5);
    // for(int i = 0; i < v.size(); i++) {
    //     cout << v[i] << " ";
    // }

    for (int e : v) {
        cout << e << " ";
    }

    // cout << endl;

    // cout << v.size() << endl;
    return 0;
}