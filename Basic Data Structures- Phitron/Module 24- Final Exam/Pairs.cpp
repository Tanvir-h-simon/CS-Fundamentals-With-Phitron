#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b) {
    // If strings are same, sort by number
    if (a.first == b.first) {
        return a.second > b.second;
    }
    // Otherwise sort by string alphabetically
    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<string, int>> list;
    
    for (int i = 0; i < n; i++) {
        string name;
        int number;
        cin >> name >> number;
        list.push_back(make_pair(name, number));
    }

    sort(list.begin(), list.end(), compare);
    
    for (int i = 0; i < n; i++) {
        cout << list[i].first << " " << list[i].second << endl;
    }
    
    return 0;
}