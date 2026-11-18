#include <iostream>
#include <set>
using namespace std;

int main() {
    string word;
    cin >> word;

    set<char> seen;

    int left = 0; // Left index

    string longestSubstring = "";
    int size = word.size();
    for (int i = 0; i < size; i++) {
        while (seen.count(word[i])) {
            seen.erase(word[left]); // Remove left chars until duplicate is gone
            left++;
        }
        seen.insert(word[i]); // Insert current character
        
        // Check if current substring is the longest
        string currentSubstring = word.substr(left, i - left + 1);
        if (currentSubstring.size() > longestSubstring.size()) {
            longestSubstring = currentSubstring;
        }
    }

    cout << longestSubstring << endl;

    return 0;
}