#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], int node, int source) {
    // Create a visited array to keep track of visited nodes
    vector<bool> visited(node, false); 
    // Create a queue for BFS
    queue<int> q;
    // Mark the source node as visited and enqueue it
    visited[source] = true;
    q.push(source);

    cout << source << " ";
    while (!q.empty()) {
        // Dequeue a vertex from queue and print it
        int current = q.front();
        q.pop();
        cout << current << " ";

        // Get all adjacent vertices of the dequeued vertex
        for (int neighbor : adj[current]) {
            // If an adjacent vertex has not been visited, mark it visited and enqueue it
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}
int main() {
    int node, edge;
    cout << "Enter number of nodes and edges: ";
    cin >> node >> edge;
    // Create adjacency list
    vector<int> adj[node];

    cout << "Enter edges: " << endl;
    for (int i = 0; i < edge; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int source;
    cout << "Enter source node for BFS: ";
    cin >> source;

    // Perform BFS traversal
    bfs(adj, node, source);
    return 0;
}