#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; // Size of A array
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int m; // Size of B array
    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    int x; // Index
    cin >> x;
    
    // for (int i = 0; i < m; i++) {
    //     A.push_back(B[i]);
    // }

    A.insert(A.begin() + x, B.begin(), B.end());

    for (int i = 0; i < n + m; i++) {
        cout << A[i] << " ";
    }

    return 0;
}