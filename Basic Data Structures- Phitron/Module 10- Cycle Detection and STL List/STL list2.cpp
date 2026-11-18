#include <iostream>
#include <list>
using namespace std;

void printList(const list<int>& linkedList) {
    for (int value : linkedList) {
        cout << value << " ";
    }
    cout << endl;
}

void insertAtPosition(list<int>& linkedList) {
    if (linkedList.empty()) {
        cout << "List is empty!" << endl;
        return;
    }
    int position, newValue;
    cout << "Enter position and value: ";
    cin >> position >> newValue;
    if (position < 0 || position > linkedList.size()) {
        cout << "Invalid Index!" << endl;
        return;
    }
    auto it = linkedList.begin();
    for (int i = 0; i < position; i++) {
        it++;
    }
    linkedList.insert(it, newValue);
}

void deleteHead(list<int>& linkedList) {
    if (!linkedList.empty()) {
        linkedList.pop_front();
    } else {
        cout << "List is empty!" << endl;
    }
}

void deleteTail(list<int>& linkedList) {
    if (!linkedList.empty()) {
        linkedList.pop_back();
    } else {
        cout << "List is empty!" << endl;
    }
}

void deleteAtPosition(list<int>& linkedList) {
    if (linkedList.empty()) {
        cout << "List is empty!" << endl;
        return;
    }
    int position;
    cout << "Enter position to delete value: ";
    cin >> position;
    if (position < 0 || position >= linkedList.size()) {
        cout << "Invalid Position!" << endl;
        return;
    }
    auto it = linkedList.begin();
    for (int i = 0; i < position; i++) {
        it++;
    }
    linkedList.erase(it);
}

void printForward(const list<int>& linkedList) {
    cout << "Print Forward: ";
    for (auto it = linkedList.begin(); it != linkedList.end();) {
        cout << *it;
        it++; // Move iterator forward first
        if (it != linkedList.end()) {
            cout << "->";
        }
    }
    cout << endl;
}

void printBackward(const list<int>& linkedList) {
    cout << "Print Backward: ";
    for (auto it = linkedList.rbegin(); it != linkedList.rend();) {
        cout << *it;
        it++; // Move iterator forward first
        if (it != linkedList.rend()) {
            cout << "->";
        }
    }
    cout << endl;
}

int main() {
    list<int> linkedList;
    int value;

    cout << "Enter value (-1 to stop): ";
    while (cin >> value && value != -1) {
        linkedList.push_back(value); // Insert at tail
    }

    printList(linkedList);
    insertAtPosition(linkedList);
    printList(linkedList);
    deleteHead(linkedList);
    printList(linkedList);
    deleteTail(linkedList);
    printList(linkedList);
    deleteAtPosition(linkedList);
    printList(linkedList);
    printForward(linkedList);
    printBackward(linkedList);

    return 0;
}