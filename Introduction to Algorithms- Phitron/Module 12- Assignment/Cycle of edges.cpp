#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
    public:
    vector<int> parent, rank;
    
    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) {
            return false; // Already in same set
        }
        
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        
        return true; // No cycle
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    UnionFind uf(n);
    int cycleEdges = 0;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        if (!uf.unite(u, v)) {
            cycleEdges++;
        }
    }
    
    cout << cycleEdges << endl;
    
    return 0;
}