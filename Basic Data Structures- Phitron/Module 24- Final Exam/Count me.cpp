#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

int main() {
    int T; 
    cin >> T;
    cin.ignore();
    
    while (T--) {
        string sentence;
        getline(cin, sentence);
        
        map<string, int> wordCount;
        string firstMaxWord = "";
        int maxCount = 0;
        
        // Use stringstream to split sentence into words
        stringstream ss(sentence);
        string word;
        
        while (ss >> word) {
            wordCount[word]++;
            if (wordCount[word] > maxCount) {
                maxCount = wordCount[word];
                firstMaxWord = word;
            }
        }
        cout << firstMaxWord << " " << maxCount << endl;
    }
    
    return 0;
}