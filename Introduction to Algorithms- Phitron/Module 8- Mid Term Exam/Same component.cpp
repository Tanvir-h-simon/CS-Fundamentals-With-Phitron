#include <iostream>
using namespace std;

// Global arrays to store the grid and track visited cells
char grid[1001][1001];
bool visited[1001][1001];
int rows, columns;

// Function to check if we can reach target cell from current position
bool canReachTarget(int r, int c, int targetR, int targetC) {
    // Check boundaries - can't go outside the grid
    /* if (r < 0 || r >= rows || c < 0 || c >= columns) {
        return false;
    } */
    
    // Check if current cell is blocked (minus sign)
    /* if (grid[r][c] == '-') {
        return false;
    } */
    
    // Avoid revisiting same cell to prevent infinite loops
    /* if (visited[r][c] == true) {
        return false;
    } */
    
    // Success! We reached the target cell
    /* if (r == targetR && c == targetC) {
        return true;
    } */
    
    // Mark current cell as visited
    /* visited[r][c] = true; */
    
    // Try all 4 directions: up, down, left, right
    /* if (canReachTarget(r-1, c, targetR, targetC)) {
        return true;
    }
    
    if (canReachTarget(r+1, c, targetR, targetC)) {
        return true;
    }
    
    if (canReachTarget(r, c-1, targetR, targetC)) {
        return true;
    }
    
    if (canReachTarget(r, c+1, targetR, targetC)) {
        return true;
    } */
    
    // No path found from this position
    /* return false; */
    
    // Proper implementation:
    if (r < 0 || r >= rows || c < 0 || c >= columns) return false;
    if (grid[r][c] == '-') return false;
    if (visited[r][c]) return false;
    if (r == targetR && c == targetC) return true;
    
    visited[r][c] = true;
    
    return canReachTarget(r-1, c, targetR, targetC) ||  // Up
           canReachTarget(r+1, c, targetR, targetC) ||  // Down
           canReachTarget(r, c-1, targetR, targetC) ||  // Left
           canReachTarget(r, c+1, targetR, targetC);    // Right
}

int main() {
    // Read grid dimensions
    /* cin >> rows >> columns; */
    
    // Read the grid
    /* for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> grid[i][j];
        }
    } */
    
    // Read first cell coordinates
    /* int x1, y1;
    cin >> x1 >> y1; */
    
    // Read second cell coordinates
    /* int x2, y2;
    cin >> x2 >> y2; */
    
    // Initialize visited array
    /* for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            visited[i][j] = false;
        }
    } */
    
    // Check if we can reach from first cell to second cell
    /* if (canReachTarget(x1, y1, x2, y2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    } */
    
    // Proper implementation:
    cin >> rows >> columns;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> grid[i][j];
            visited[i][j] = false;  // Initialize while reading
        }
    }
    
    int x1, y1, x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    
    cout << (canReachTarget(x1, y1, x2, y2) ? "YES" : "NO") << endl;
    
    return 0;
}