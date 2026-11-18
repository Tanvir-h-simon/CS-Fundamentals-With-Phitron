#include <bits/stdc++.h>
using namespace std;

int main() {
    int node, edge;
    cin >> node >> edge;
    vector<pair<int, int>> list;

    while (edge--) {
        int a, b;
        cin >> a >> b;
        list.push_back({a, b});
    }

    for (pair<int, int> x : list) {
        cout << x.first << " " << x.second << endl;
    }

    // for (auto x : list) {
    //     cout << x.first << " " << x.second <<  endl;
    // }

    return 0;
}