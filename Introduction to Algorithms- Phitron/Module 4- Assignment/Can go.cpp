#include <iostream>
using namespace std;

// Global arrays to store the building map and track visited cells
char map[1001][1001];
bool visited[1001][1001];
int rows, columns;

// Function to check if we can reach from current position to target
bool findPath(int r, int c, int targetR, int targetC) {
    // Check boundaries - can't go outside the building
    /* if (r < 0 || r >= rows || c < 0 || c >= columns) {
        return false;
    } */
    
    // Check if current cell is a wall
    /* if (map[r][c] == '#') {
        return false;
    } */
    
    // Avoid revisiting same cell to prevent infinite loops
    /* if (visited[r][c] == true) {
        return false;
    } */
    
    // Success! We reached room B
    /* if (r == targetR && c == targetC) {
        return true;
    } */
    
    // Mark current position as visited
    /* visited[r][c] = true; */
    
    // Try all 4 directions: up, down, left, right
    /* if (findPath(r-1, c, targetR, targetC)) {
        return true;
    }
    
    if (findPath(r+1, c, targetR, targetC)) {
        return true;
    }
    
    if (findPath(r, c-1, targetR, targetC)) {
        return true;
    }
    
    if (findPath(r, c+1, targetR, targetC)) {
        return true;
    } */
    
    // No path found from this position
    /* return false; */
    
    // Proper implementation:
    if (r < 0 || r >= rows || c < 0 || c >= columns) return false;
    if (map[r][c] == '#') return false;
    if (visited[r][c]) return false;
    if (r == targetR && c == targetC) return true;
    
    visited[r][c] = true;
    
    return findPath(r-1, c, targetR, targetC) || 
           findPath(r+1, c, targetR, targetC) ||
           findPath(r, c-1, targetR, targetC) ||
           findPath(r, c+1, targetR, targetC);
}

int main() {
    // Read building dimensions
    /* cin >> rows >> columns; */
    
    // Variables to store room positions
    /* int aRow, aCol;  
    int bRow, bCol; */
    
    // Read the map and find rooms A and B
    /* for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> map[i][j];
            
            if (map[i][j] == 'A') {
                aRow = i;
                aCol = j;
            }
            if (map[i][j] == 'B') {
                bRow = i;
                bCol = j;
            }
        }
    } */
    
    // Initialize visited array
    /* for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            visited[i][j] = false;
        }
    } */
    
    // Check if path exists and output result
    /* if (findPath(aRow, aCol, bRow, bCol)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    } */
    
    // Proper implementation:
    cin >> rows >> columns;
    
    int aRow, aCol, bRow, bCol;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'A') { aRow = i; aCol = j; }
            if (map[i][j] == 'B') { bRow = i; bCol = j; }
            visited[i][j] = false; // Initialize while reading
        }
    }
    
    cout << (findPath(aRow, aCol, bRow, bCol) ? "YES" : "NO") << endl;
    
    return 0;
}