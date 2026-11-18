#include <iostream>
#include <vector>
using namespace std;

int tetranacci(int n, vector<int>& memo) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    if (n == 3) return 2;

    if (memo[n] != -1) return memo[n];

    memo[n] = tetranacci(n-1, memo) + tetranacci(n-2, memo) + tetranacci(n-3, memo) + tetranacci(n-4, memo);
    return memo[n];
}

int main() {
    int n;
    cin >> n;

    vector<int> memo(n+1, -1);
    cout << tetranacci(n, memo) << endl;
    return 0;
}