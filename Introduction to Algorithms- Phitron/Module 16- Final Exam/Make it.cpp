#include <iostream>
using namespace std;

bool canReach(long long x) {
    while (x > 1) {
        if (x % 2 == 0) {
            x /= 2;        
        } else {
            x -= 3; 
        }

        if (x < 1) return false;
    }
    return x == 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
        cout << (canReach(x) ? "YES" : "NO") << endl;
    }
    return 0;
}