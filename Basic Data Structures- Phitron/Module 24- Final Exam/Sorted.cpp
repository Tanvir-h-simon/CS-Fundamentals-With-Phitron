#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int T; // Test cases
    cin >> T;
    
    while (T--) {
        int N; // Size
        cin >> N;
        
        set<int> uniqueNumbers; // Set automatically removes duplicates and sorted in order
        
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            uniqueNumbers.insert(num);
        }
        
        for (int num : uniqueNumbers) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}