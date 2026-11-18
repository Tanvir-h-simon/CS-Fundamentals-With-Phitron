#include <bits/stdc++.h>
using namespace std;

int main() {
    int node, edge;
    cin >> node >> edge;
    vector<int> list[node];
    while (edge--) {
        int a, b;
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a); // Undirected
    }

    for (int i = 0; i < node; i++) {
        cout << i << "->";
        // for (int j = 0; j < list[i].size(); j++) {
        //     cout << list[i][j] << " ";
        // }
        for (int x : list[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    
    return 0;
}