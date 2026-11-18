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
        v.push_back(x);
    }

    for (int i = N - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }


    return 0;
}