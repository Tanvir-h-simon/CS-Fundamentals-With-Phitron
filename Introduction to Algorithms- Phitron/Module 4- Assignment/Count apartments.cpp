#include <iostream>
using namespace std;

// Global arrays to store the building map and track visited rooms
char map[1001][1001];
bool visited[1001][1001];
int rows, columns;

// Function to explore all connected rooms in one apartment
void exploreApartment(int r, int c) {
    // Check boundaries - can't go outside the building
    /* if (r < 0 || r >= rows || c < 0 || c >= columns) {
        return;
    } */
    
    // Check if current cell is a wall
    /* if (map[r][c] == '#') {
        return;
    } */
    
    // Avoid revisiting same room to prevent infinite loops
    /* if (visited[r][c] == true) {
        return;
    } */
    
    // Mark current room as visited
    /* visited[r][c] = true; */
    
    // Explore all 4 directions: up, down, left, right
    /* exploreApartment(r-1, c);
    exploreApartment(r+1, c);
    exploreApartment(r, c-1);
    exploreApartment(r, c+1); */
    
    // Proper implementation:
    if (r < 0 || r >= rows || c < 0 || c >= columns) return;
    if (map[r][c] == '#') return;
    if (visited[r][c]) return;
    
    visited[r][c] = true;
    
    exploreApartment(r-1, c);  // Up
    exploreApartment(r+1, c);  // Down
    exploreApartment(r, c-1);  // Left
    exploreApartment(r, c+1);  // Right
}

int main() {
    // Read building dimensions
    /* cin >> rows >> columns; */
    
    // Read the building map
    /* for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> map[i][j];
        }
    } */
    
    // Initialize visited array
    /* for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            visited[i][j] = false;
        }
    } */
    
    // Count apartments by finding connected components
    /* int apartmentCount = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (map[i][j] == '.' && visited[i][j] == false) {
                exploreApartment(i, j);
                apartmentCount++;
            }
        }
    } */
    
    // Output the result
    /* cout << apartmentCount << endl; */
    
    // Proper implementation:
    cin >> rows >> columns;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> map[i][j];
            visited[i][j] = false;  // Initialize while reading
        }
    }
    
    int apartmentCount = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (map[i][j] == '.' && !visited[i][j]) {
                exploreApartment(i, j);
                apartmentCount++;
            }
        }
    }
    
    cout << apartmentCount << endl;
    
    return 0;
}