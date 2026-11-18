#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main() {
    string sentence;
    getline (cin , sentence);

    stringstream ss(sentence);
    string word;

    map<string, int> freq; 

    string mostFrequentWord = "";
    int countOfMostFrequentWord = 0;

    while (ss >> word) {
        freq[word]++; 
        
        /* Accesses or creates the entry for 'word'
        Example, map<string, int> freq;
                    freq["apple"] = 5;
                    int count = freq["apple"];  // Returns 5

                map<string, int> freq;
                int count = freq["banana"];  // Auto-creates {"banana": 0}, returns 0
        
        */  
        
        if (freq[word] > countOfMostFrequentWord) {
            countOfMostFrequentWord = freq[word];
            
            mostFrequentWord = word;
        }
    }
    
    cout << mostFrequentWord << " " << countOfMostFrequentWord << endl;

    return 0;
}