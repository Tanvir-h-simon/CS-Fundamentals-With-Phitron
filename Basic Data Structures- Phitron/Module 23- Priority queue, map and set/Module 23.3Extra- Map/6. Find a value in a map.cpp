#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> students = {
        {1, "Tanvir"},
        {2, "Aisha"},
        {3, "John"}
    };

    string target = "Aisha";
    bool found = false;

    int targetKey = 3;

    auto it = students.find(targetKey);
    if (it != students.end()) // if (map.find(key) != map.end()) => O(log n)
        cout << "Found: " << it->second << endl;
    else
        cout << "Key not found." << endl;

    return 0;
}