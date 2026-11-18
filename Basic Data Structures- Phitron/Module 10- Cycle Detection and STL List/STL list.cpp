#include <iostream>
#include <list>
// #include <iterator>
using namespace std;

int main() {
    list<int> linkedList;

    int value;
    cout << "Enter value (-1 to stop): ";
    while (cin >> value && value != - 1) {
        // Insert at head
        // linkedList.push_front(value); 
        // Insert at tail
        linkedList.push_back(value); 
    }

    // Print the list
    for (int value : linkedList) { 
        cout << value << " "; 
    }
    cout << endl;

    // Print the list
    // for (list<int>::iterator iterator = linkedList.begin(); iterator != linkedList.end(); iterator++) { 
    //     cout << *iterator << " "; // Dereference- Get the value at iterator position
    // }

    // Insert at position
    if (linkedList.empty()) {
        cout << "List is empty!" << endl;
        return;
    }
    int position, newValue;
    cout << "Enter position and value: ";
    cin >> position >> newValue;
    if (position < 0 || position > linkedList.size()) {
        cout << "Invalid Index!" << endl;
    } else {
        auto it = linkedList.begin();
        for (int i = 0; i < position; i++) {
            it++;
        }
        linkedList.insert(it,newValue);
    }

    // Print the list
    for (int value : linkedList) { 
        cout << value << " "; 
    }
    cout << endl;

    // Delete head
    if (!linkedList.empty()) {
        linkedList.pop_front();
    } else {
        cout << "List is empty!" << endl;
    }

    // Print the list
    for (int value : linkedList) { 
        cout << value << " "; 
    }
    cout << endl;

    // Delete tail
    if (!linkedList.empty()) {
        linkedList.pop_back();
    } else {
        cout << "List is empty!" << endl;
    }

    // Print the list
    for (int value : linkedList) { 
        cout << value << " "; 
    }
    cout << endl;

    // Delete at position
    if (linkedList.empty()) {
        cout << "List is empty!" << endl;
        return;
    }
    int newPosition;
    cout << "Enter position to delete value: ";
    cin >> newPosition;
    if (newPosition < 0 || newPosition >= linkedList.size()) {
        cout << "Invalid Position!" << endl;
    } else {
        auto it = linkedList.begin();
        for (int i = 0; i < newPosition; i++) {
            it++;
        }
        linkedList.erase(it);
    }

    // Print the list
    for (int value : linkedList) { 
        cout << value << " "; 
    }
    cout << endl;

    // Print Forward
    cout << "Print Forward: ";
    for (auto it = linkedList.begin(); it != linkedList.end();) { 
        cout << *it;
        it++; // Move iterator forward here so we can check before printing "->"
        if (it != linkedList.end()) {
            cout << "->";
        }
    }
    cout << endl;

    // Print Backward
    cout << "Print Backward: ";
    for (auto it = linkedList.rbegin(); it != linkedList.rend();) { 
        cout << *it;
        it++; // Move iterator forward here so we can check before printing "->"
        if (it != linkedList.rend()) {
            cout << "->";
        }
    }
    cout << endl;

    return 0;
}