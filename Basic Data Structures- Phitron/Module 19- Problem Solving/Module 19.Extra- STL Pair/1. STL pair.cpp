#include <iostream>
#include <utility>
using namespace std;

int main() {
    // pair<int, int> p;
    // // p = make_pair(2, 3);
    // p = {2, 3};
    // cout << p.first << endl;
    // cout << p.second << endl;
    pair<string, int> p;
    // p = make_pair("Hello", 3);
    p = {"Hello", 3};
    cout << p.first << endl;
    cout << p.second << endl;
    return 0;
}