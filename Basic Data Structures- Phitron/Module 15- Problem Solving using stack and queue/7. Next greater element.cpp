#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void findNextGreater(vector<int>& arr, vector<int>& answer) {
    stack<int> s;
    int index = arr.size() - 1;
    answer[index] = -1;
    s.push(arr[index]);

    for (index = index - 1; index >= 0; index--) {
        int current = arr[index];
        while (!s.empty() && current >= s.top()) {
            s.pop();
        }

        if (s.empty()) {
            answer[index] = -1;
        } else {
            answer[index] = s.top();
        }

        s.push(current);
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> answer(size);
    findNextGreater(arr, answer);

    return 0;
}