#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    // Create a 2D array to store direct connections
    vector<vector<bool>> graph(N, vector<bool>(N, false));
    
    // Initialize self-loops (every node connected to itself)
    for (int i = 0; i < N; i++) {
        graph[i][i] = true;
    }
    
    // Read edges and mark them in the graph
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = true;
    }
    
    int Q;
    cin >> Q;
    
    // Process each query
    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        
        if (graph[u][v] == true) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}