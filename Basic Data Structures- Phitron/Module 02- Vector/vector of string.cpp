#include <bits/stdc++.h>
using namespace std;

int main() {
    int num;
    cin >> num;
    cin.ignore();
    vector<string> v(num);
    for (int i = 0; i < num; i++) {
        // cin >> v[i];
        getline(cin, v[i]);
    }

    for (string s : v) {
        cout << s << " ";
    }
    return 0;
}