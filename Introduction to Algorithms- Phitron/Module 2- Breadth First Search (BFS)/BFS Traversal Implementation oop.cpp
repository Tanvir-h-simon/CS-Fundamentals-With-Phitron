#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int vertices;
    vector<int> *adj;
    
public:
    Graph(int v) {
        vertices = v;
        adj = new vector<int>[v];
    }
    
    // Destructor to free memory
    ~Graph() {
        delete[] adj;
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }
    
    void BFS(int source) {
        vector<bool> visited(vertices, false);
        queue<int> q;
        
        visited[source] = true;
        q.push(source);
        
        cout << "BFS Traversal: ";
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";
            
            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int node, edge;
    cout << "Enter number of nodes and edges: ";
    cin >> node >> edge;
    
    // Create Graph object
    Graph g(node);
    
    cout << "Enter edges: " << endl;
    for (int i = 0; i < edge; i++) {
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);  // Use the Graph's addEdge method
    }
    
    int source;
    cout << "Enter source node for BFS: ";
    cin >> source;
    
    // Perform BFS traversal using the Graph object
    g.BFS(source);
    
    return 0;
}