#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int rowCount, columnCount;
    cin >> rowCount >> columnCount;
    vector<string> grid(rowCount);
    int startRow = -1, startColumn = -1;
    int exitRow = -1, exitColumn = -1;
    
    for (int row = 0; row < rowCount; row++) {
        cin >> grid[row];
        for (int column = 0; column < columnCount; column++) {
            if (grid[row][column] == 'R') {
                startRow = row;
                startColumn = column;
            } else if (grid[row][column] == 'D') {
                exitRow = row;
                exitColumn = column;
            }
        }
    }
    
    if (startRow == -1 || exitRow == -1) {
        for (int row = 0; row < rowCount; row++) {
            cout << grid[row] << endl;
        }
        return 0;
    }
    
    vector<vector<int>> distance(rowCount, vector<int>(columnCount, -1));
    queue<pair<int, int>> queue;
    queue.push({exitRow, exitColumn});
    distance[exitRow][exitColumn] = 0;
    
    int directions[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    
    while (!queue.empty()) {
        int currentRow = queue.front().first;
        int currentColumn = queue.front().second;
        queue.pop();
        for (int index = 0; index < 4; index++) {
            int nextRow = currentRow + directions[index][0];
            int nextColumn = currentColumn + directions[index][1];
            if (nextRow < 0 || nextRow >= rowCount || nextColumn < 0 || nextColumn >= columnCount) continue;
            if (grid[nextRow][nextColumn] == '#') continue;
            if (distance[nextRow][nextColumn] == -1) {
                distance[nextRow][nextColumn] = distance[currentRow][currentColumn] + 1;
                queue.push({nextRow, nextColumn});
            }
        }
    }
    
    if (distance[startRow][startColumn] == -1) {
        for (int row = 0; row < rowCount; row++) {
            cout << grid[row] << endl;
        }
        return 0;
    }
    
    int currentRow = startRow, currentColumn = startColumn;
    while (currentRow != exitRow || currentColumn != exitColumn) {
        bool foundNext = false;
        for (int index = 0; index < 4; index++) {
            int nextRow = currentRow + directions[index][0];
            int nextColumn = currentColumn + directions[index][1];
            if (nextRow < 0 || nextRow >= rowCount || nextColumn < 0 || nextColumn >= columnCount) continue;
            if (distance[nextRow][nextColumn] == -1) continue;
            if (distance[nextRow][nextColumn] == distance[currentRow][currentColumn] - 1) {
                if (grid[nextRow][nextColumn] != 'D') {
                    grid[nextRow][nextColumn] = 'X';
                }
                currentRow = nextRow;
                currentColumn = nextColumn;
                foundNext = true;
                break;
            }
        }
        if (!foundNext) break;
    }
    
    for (int row = 0; row < rowCount; row++) {
        cout << grid[row] << endl;
    }
    
    return 0;
}