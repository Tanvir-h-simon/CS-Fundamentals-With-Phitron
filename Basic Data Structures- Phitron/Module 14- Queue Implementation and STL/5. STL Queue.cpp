#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> qu;
    // qu.push(10);
    // qu.push(20);
    // cout << qu.front() << endl;
    // qu.pop();
    // cout << qu.front() << endl;
    // qu.pop();
    // if (!qu.empty()) {
    //     qu.front();
    // }
    // if (!qu.empty()) {
    //     qu.pop();
    // }
    cout << "Enter the size: ";
    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        qu.push(x);
    }
    
    while (!qu.empty()) {
        cout << qu.front() << endl;
        qu.pop();
    } 
    return 0;
}