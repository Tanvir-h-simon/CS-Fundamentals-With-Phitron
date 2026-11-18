#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Queue {
    vector<int> v;

public:
    void enqueue(int x) { // O(1) 
        v.push_back(x);
    }

    void dequeue() { // O(n): v[0] = front element of the queue
        if (empty()) throw runtime_error("Queue underflow: Queue is empty");
        v.erase(v.begin()); 
    }

    int front() { // O(1)
        if (empty()) throw runtime_error("Queue is empty");
        return v[0]; // v[0] = front element of the queue
    }

    bool empty() {
         return v.empty(); 
    }

    int size() {
         return v.size(); 
    }
};

int main() {
    Queue qu;
    cout << "Enter the size: ";
    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        qu.enqueue(x);
    }
    
    while (!qu.empty()) {
        cout << qu.front() << endl;
        qu.dequeue();
    } 
    return 0;
}
