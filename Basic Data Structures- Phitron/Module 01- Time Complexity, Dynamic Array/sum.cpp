#include <bits/stdc++.h>
using namespace std;

/* Asymptotic notation:
   1. Omega notation (Ω): Lower Bound-  Best Case
   2. Theta notation (θ): Tight Bound- Average Case
   3. Big O notation (O): Upper Bound- Worst Case

   Rules to calculate time complexity:
   i. Always take the worst case.
   ii. Ignore the constant.
*/

int main() {
    int num;
    cin >> num;
    // int sum = 0;
    // for (int i = 1; i <= num; i++) {
    //     sum += i; // Time Complexity = 0(n), where n = num
    // }
    // cout << sum << endl;

    int sum = (num * (num + 1) / 2); // Optimized Code: Time Complexity = O(1)
    cout << sum << endl;
    return 0;
}