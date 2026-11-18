#include <iostream>
#include <vector>
using namespace std;

// Pass by value: makes a copy
void addValueByValue(vector<int> v) {
    v.push_back(100);  // only changes the copy
    cout << "Pass by value: ";
    for (int x : v) cout << x << " ";
    cout << endl;
}

// Pass by reference: modifies the original
void addValueByReference(vector<int>& v) {
    v.push_back(200);  // modifies the original vector
    cout << "Pass by reference: ";
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> numbers = {1, 2, 3};

    cout << "Original vector: ";
    for (int x : numbers) cout << x << " ";
    cout << endl;

    addValueByValue(numbers);       // original is unchanged
    addValueByReference(numbers);   // original is modified

    cout << "After both functions: ";
    for (int x : numbers) cout << x << " ";
    cout << endl;

    return 0;
}