#include <iostream>
#include <vector>
using namespace std;

int main() {
    int size;
    cin >> size;
    vector<int> v(size);
    for (int i = 0; i < size; i++) {
        cin >> v[i];
    }

    if (v.empty()) {
        cout << "Heap is empty" << endl;
        return 0;
    }

    // Delete root (min element)
    // Replace root with last element
    v[0] = v[v.size() - 1];
    v.pop_back();

    // Heapify-down
    int currentIndex = 0;
    while (true) {
        int leftChild = 2 * currentIndex + 1;
        int rightChild = 2 * currentIndex + 2;
        
        // Find smallest among current, left child, and right child
        int smallest = currentIndex;
        if (leftChild < v.size() && v[leftChild] < v[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < v.size() && v[rightChild] < v[smallest]) {
            smallest = rightChild;
        }

        // If smallest is not current, swap and continue
        if (smallest != currentIndex) {
            swap(v[currentIndex], v[smallest]);
            currentIndex = smallest;
        } else {
            break;
        }
    }

    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}