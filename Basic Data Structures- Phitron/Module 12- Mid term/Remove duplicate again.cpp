#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> stlList;
    int value;

    // cout << "Enter value(-1 to stop): ";
    while (true) {
        cin >> value;
        if (value == -1) break;
        stlList.push_back(value); // Add the entered value of the end of the list
    }

    stlList.sort(); // Sort in ascending order
    stlList.unique(); // Remove duplicates
    
    // cout << "Sorted unique list: ";
    while (!stlList.empty()) {
        cout << stlList.front() << " "; // Print the first(front) element of the list
        stlList.pop_front(); // Remove the first(front) element of the list
    }
    cout << endl;

    return 0;
}