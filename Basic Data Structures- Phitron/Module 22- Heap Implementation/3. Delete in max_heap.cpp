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

    // Delete root (max element)
    // Replace root with last element
    v[0] = v[v.size() - 1];
    v.pop_back();

    // Heapify-down
    int currentIndex = 0;
    while (true) {
        int leftChild = 2 * currentIndex + 1;
        int rightChild = 2 * currentIndex + 2;

        // Find largest among current, left child, and right child
        int largest = currentIndex;
        if (leftChild < v.size() && v[leftChild] > v[largest]) {
            largest = leftChild;
        }
        if (rightChild < v.size() && v[rightChild] > v[largest]) {
            largest = rightChild;
        }

        // If largest is not current, swap and continue
        if (largest != currentIndex) {
            swap(v[currentIndex], v[largest]);
            currentIndex = largest;
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