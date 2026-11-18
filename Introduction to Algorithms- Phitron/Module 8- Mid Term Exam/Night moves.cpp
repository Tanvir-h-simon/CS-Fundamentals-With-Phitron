#include <iostream>
#include <queue>
using namespace std;

// Function to find minimum knight moves using BFS
int knightMoves(int n, int m, int knightX, int knightY, int queenX, int queenY) {
    // If knight is already at queen's position
    /* if (knightX == queenX && knightY == queenY) {
        return 0;
    } */
    
    // Knight can move in 8 directions
    /* int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1}; */
    
    // BFS setup
    /* queue<pair<pair<int, int>, int>> q;  // ((x, y), steps)
    bool visited[n][m];
    
    // Initialize visited array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
        }
    }
    
    // Start BFS from knight position
    q.push({{knightX, knightY}, 0});
    visited[knightX][knightY] = true;
    
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        
        int x = current.first.first;
        int y = current.first.second;
        int steps = current.second;
        
        // Try all 8 knight moves
        for (int i = 0; i < 8; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            // Check if new position is valid
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY]) {
                // If we reached the queen
                if (newX == queenX && newY == queenY) {
                    return steps + 1;
                }
                
                visited[newX][newY] = true;
                q.push({{newX, newY}, steps + 1});
            }
        }
    }
    
    // Queen is unreachable
    return -1; */
    
    // Proper implementation:
    if (knightX == queenX && knightY == queenY) return 0;
    
    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    
    queue<pair<pair<int, int>, int>> q;
    bool visited[n][m];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
        }
    }
    
    q.push({{knightX, knightY}, 0});
    visited[knightX][knightY] = true;
    
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        
        int x = current.first.first;
        int y = current.first.second;
        int steps = current.second;
        
        for (int i = 0; i < 8; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY]) {
                if (newX == queenX && newY == queenY) {
                    return steps + 1;
                }
                
                visited[newX][newY] = true;
                q.push({{newX, newY}, steps + 1});
            }
        }
    }
    
    return -1;
}

int main() {
    // Read number of test cases
    /* int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        int knightX, knightY;
        cin >> knightX >> knightY;
        
        int queenX, queenY;
        cin >> queenX >> queenY;
        
        int result = knightMoves(n, m, knightX, knightY, queenX, queenY);
        cout << result << endl;
    } */
    
    // Proper implementation:
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        int knightX, knightY;
        cin >> knightX >> knightY;
        
        int queenX, queenY;
        cin >> queenX >> queenY;
        
        cout << knightMoves(n, m, knightX, knightY, queenX, queenY) << endl;
    }
    
    return 0;
}