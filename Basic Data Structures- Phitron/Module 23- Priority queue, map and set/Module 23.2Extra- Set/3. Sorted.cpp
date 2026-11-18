#include <iostream>
#include <vector>
// #include <algorithm>
#include <set>
using namespace std;

int main() {
    int T;
    cin >> T; // Test 
    
    while (T--) {
        int N;
        cin >> N; // Size

        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];   

        // // Sort in Ascending order
        // sort(A.begin(), A.end());
        // // Remove duplicates
        // A.erase(unique(A.begin(), A.end()), A.end()); 

        set<int> uniqueSorted(A.begin(), A.end());

        // for (int i = 0; i < A.size(); i++)
        //     cout << A[i] << " ";

        // for (auto it = uniqueSorted.begin(); it != uniqueSorted.end(); it++)
        //     cout << *it << " ";
        for (int x : uniqueSorted)
            cout << x << " ";

        cout << endl;

    }

    return 0;
}

