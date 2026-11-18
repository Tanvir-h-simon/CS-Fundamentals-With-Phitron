#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;  
    cin >> n;

    // Base cases
    if (n == 0) { 
        cout << 0 << endl; 
        return 0; 
    }

    if (n == 1 || n == 2) {
        cout << 1 << endl; 
        return 0; 
    }

    if (n == 3) {
        cout << 2 << endl; 
        return 0; 
    }

    vector<long long> T(n+1);
    T[0] = 0;
    T[1] = 1;
    T[2] = 1;
    T[3] = 2;

    for (int i = 4; i <= n; i++) {
        T[i] = T[i-1] + T[i-2] + T[i-3] + T[i-4];
    }

    cout << T[n] << endl;
    return 0;
}