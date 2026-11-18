#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void stockSpanProblem(const vector<int>& stock, vector<int>& span) {
    stack<int> s;
    s.push(0);
    span[0] = 1;

    for (int i = 1; i < stock.size(); i++) {
        // Pop indices while current price >= price at stack top
        while (!s.empty() && stock[i] >= stock[s.top()]) {
            s.pop();
        }

        // If stack becomes empty, all previous prices are smaller
        if (s.empty()) {
            span[i] = i + 1;
        } else {
            span[i] = i - s.top();
        }

        // Push this index to stack
        s.push(i);
    }

    for (int i = 0; i < span.size(); i++) {
        cout << span[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    // vector<int> span = {0, 0, 0, 0, 0, 0, 0};
    vector<int> span(stock.size(), 0);

    stockSpanProblem(stock, span);
    return 0;
}