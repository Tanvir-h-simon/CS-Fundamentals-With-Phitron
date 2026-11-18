#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Custom comparator for sorting pairs
// Returns true if 'a' should come before 'b' in sorted order
bool compare(const pair<string, int>& a, const pair<string, int>& b) {
    // If strings are equal, sort by integer in descending order (larger first)
    if (a.first == b.first) 
        return a.second > b.second;  // > for descending
    
    // Otherwise, sort by string in ascending order (alphabetically)
    return a.first < b.first;  // < for ascending
}

int main() {
    int N;
    cin >> N;
    vector<pair<string, int>> list(N);
    
    for (int i = 0; i < N; i++) {
        cin >> list[i].first >> list[i].second;
    }

    // Sort using custom comparator
    sort(list.begin(), list.end(), compare);

    for (int i = 0; i < N; i++) {
        cout << list[i].first << " " << list[i].second << endl;
    }

    return 0;
}