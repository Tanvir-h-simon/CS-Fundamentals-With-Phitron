#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    // Create adjacency list to store connections
    // adj[i] will store all nodes connected to node i
    vector<vector<int>> adj(N);
    
    // Read all edges
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        // Since it's undirected, add both connections
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int Q;
    cin >> Q;
    
    // Process each query
    for (int i = 0; i < Q; i++) {
        int node;
        cin >> node;
        
        // Check if this node has any connections
        if (adj[node].empty()) {
            cout << -1 << "\n";
        } else {
            // Sort the connected nodes in descending order
            sort(adj[node].begin(), adj[node].end(), greater<int>());
            
            // Print all connected nodes
            for (int j = 0; j < adj[node].size(); j++) {
                cout << adj[node][j];
                if (j < adj[node].size() - 1) {
                    cout << " ";
                }
            }
            cout << "\n";
        }
    }
    
    return 0;
}