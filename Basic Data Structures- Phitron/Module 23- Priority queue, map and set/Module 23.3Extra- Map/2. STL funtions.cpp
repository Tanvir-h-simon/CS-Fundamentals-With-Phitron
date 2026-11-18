#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> people = { {"John", 32}, {"Adele", 45}, {"Bo", 29} };
    // people["John"] = 50;
    people.at("John") = 50;

    people.insert({"Jenny", 22});
    people.insert({"Liam", 24});
    
    // cout << "John is: " << people["John"] << endl;
    // cout << "Adele is: " << people["Adele"] << endl;
    
    // cout << "John is: " << people.at("John") << endl;
    // cout << "Adele is: " << people.at("Adele") << endl;

    // cout << "Jenny is: " << people.at("Jenny") << endl;
    // cout << "Liam is: " << people.at("Liam") << endl;

    people.erase("John");

    // people.clear();
    for (auto person : people) {
        cout << person.first << " is: " << person.second << endl;
    }

    return 0;
}