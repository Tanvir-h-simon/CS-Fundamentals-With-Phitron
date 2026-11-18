#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Global arrays to store the grid and track visited cells
char grid[1001][1001];
bool visited[1001][1001];
int rows, columns;

// Function to explore a component and count its area (number of dots)
int exploreComponent(int r, int c) {
    // Check boundaries - can't go outside the grid
    /* if (r < 0 || r >= rows || c < 0 || c >= columns) {
        return 0;
    } */
    
    // Check if current cell is blocked (minus sign)
    /* if (grid[r][c] == '-') {
        return 0;
    } */
    
    // Avoid revisiting same cell to prevent infinite loops
    /* if (visited[r][c] == true) {
        return 0;
    } */
    
    // Mark current cell as visited
    /* visited[r][c] = true; */
    
    // Count this dot and explore all 4 directions
    /* int area = 1;
    area = area + exploreComponent(r-1, c);
    area = area + exploreComponent(r+1, c);
    area = area + exploreComponent(r, c-1);
    area = area + exploreComponent(r, c+1);
    return area; */
    
    // Proper implementation:
    if (r < 0 || r >= rows || c < 0 || c >= columns) return 0;
    if (grid[r][c] == '-') return 0;
    if (visited[r][c]) return 0;
    
    visited[r][c] = true;
    
    return 1 + exploreComponent(r-1, c) +    // Up
               exploreComponent(r+1, c) +    // Down
               exploreComponent(r, c-1) +    // Left
               exploreComponent(r, c+1);     // Right
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
    
    // Initialize visited array
    /* for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            visited[i][j] = false;
        }
    } */
    
    // Store all component areas
    /* vector<int> componentAreas; */
    
    // Find all components and their areas
    /* for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (grid[i][j] == '.' && visited[i][j] == false) {
                int area = exploreComponent(i, j);
                componentAreas.push_back(area);
            }
        }
    } */
    
    // Find minimum area
    /* if (componentAreas.empty()) {
        cout << -1 << endl;
    } else {
        sort(componentAreas.begin(), componentAreas.end());
        cout << componentAreas[0] << endl;
    } */
    
    // Proper implementation:
    cin >> rows >> columns;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> grid[i][j];
            visited[i][j] = false;  // Initialize while reading
        }
    }
    
    vector<int> componentAreas;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                int area = exploreComponent(i, j);
                componentAreas.push_back(area);
            }
        }
    }
    
    if (componentAreas.empty()) {
        cout << -1 << endl;
    } else {
        sort(componentAreas.begin(), componentAreas.end());
        cout << componentAreas[0] << endl;  // First element after sorting is minimum
    }
    
    return 0;
}