#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, W;
        cin >> N >> W;

        vector<int> weight(N), value(N);
        for (int i = 0; i < N; i++) {
            cin >> weight[i];
        } 
        
        for (int i = 0; i < N; i++) {
            cin >> value[i];
        } 

        vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

        for (int i = 1; i <= N; i++) {
            for (int w = 0; w <= W; w++) {
                dp[i][w] = dp[i-1][w];
                if (w >= weight[i-1]) {
                    dp[i][w] = max(dp[i][w], value[i-1] + dp[i-1][w - weight[i-1]]);
                }
            }
        }

        cout << dp[N][W] << endl;
    }
    return 0;
}