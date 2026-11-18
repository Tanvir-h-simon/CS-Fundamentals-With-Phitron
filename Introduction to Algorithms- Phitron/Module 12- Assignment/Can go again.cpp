#include <iostream>
#include <vector>
#include <climits>  // For LLONG_MAX
using namespace std;

class Edge {
    public:
    int u, v, w;
    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    
    int source;
    cin >> source;
    
    int t;
    cin >> t;
    vector<int> destinations(t);
    for (int i = 0; i < t; i++) {
        cin >> destinations[i];
    }
    
    // Initialize distances with infinity
    long long INF = LLONG_MAX;
    vector<long long> dist(n + 1, INF);
    dist[source] = 0;
    
    // Bellman-Ford Algorithm
    for (int i = 0; i < n - 1; i++) {
        for (Edge& e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }
    
    // Check for negative weight cycles
    bool hasNegativeCycle = false;
    for (Edge& e : edges) {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "Negative Cycle Detected" << endl;
    } else {
        for (int dest : destinations) {
            if (dist[dest] == INF) {
                cout << "Not Possible" << endl;
            } else {
                cout << dist[dest] << endl;
            }
        }
    }

    return 0;
}