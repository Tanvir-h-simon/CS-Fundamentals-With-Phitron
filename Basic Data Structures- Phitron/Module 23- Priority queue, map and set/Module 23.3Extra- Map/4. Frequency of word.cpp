#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    // Use stringstream to split sentence into words
    stringstream ss (s);
    string word;

    map<string, int> freq; 
    /* Why map<string, int>?
    map stores key-value pairs: {word: count}
    Automatically keeps keys (words) sorted alphabetically
    */

    while (ss >> word) {
        freq[word]++;
    }

    /* Why while(ss >> word) ?
    Example,
    string sentence = "apple banana apple";
    stringstream ss(sentence);
    string word;

    // First iteration
    ss >> word;  // word = "apple", returns true
    // Second iteration
    ss >> word;  // word = "banana", returns true
    // Third iteration
    ss >> word;  // word = "apple", returns true
    // Fourth iteration
    ss >> word;  // No more words, returns false → loop exits
    */ 

    // Words are sorted alphabetically in map
    for (auto it = freq.begin(); it != freq.end(); it++) { // O(n logn)
        cout << it->first << " " << it->second << endl; 
    }

    return 0;
}