#include <iostream>
#include <vector>
#include <climits>  // For LLONG_MAX
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // Initialize distance matrix with infinity
    long long INF = LLONG_MAX;
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));
    
    // Initialize diagonal to 0
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (dist[u][v] > w) {
            dist[u][v] = w;
        }
    }
    
    // Floyd-Warshall Algorithm
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        
        if (dist[u][v] == INF) {
            cout << -1 << endl;
        } else {
            cout << dist[u][v] << endl;
        }
    }
    
    return 0;
}