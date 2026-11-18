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

    int value;
    cin >> value;
    v.push_back(value);
    int currentIndex = v.size() - 1; // Child index
    int parentIndex = (currentIndex - 1) / 2;
    
    while (currentIndex != 0) {
        if (v[parentIndex] > v[currentIndex]) {
            swap(v[parentIndex], v[currentIndex]);
            currentIndex = parentIndex;
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