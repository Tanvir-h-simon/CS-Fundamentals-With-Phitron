#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        
        if ( x > 0) {
            v.push_back(1);
        } else if (x < 0) {
            v.push_back(2);
        } else {
            v.push_back(0);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << v[i] << " ";
    }

    return 0;
}