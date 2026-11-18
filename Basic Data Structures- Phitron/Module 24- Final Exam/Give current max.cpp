#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Student {
    string name;
    int roll;
    int marks;
};

struct CompareStudent {
    bool operator()(Student& a, Student& b) {
        if (a.marks == b.marks) {
            return a.roll > b.roll;
        } else {
            return a.marks < b.marks;
        }
    }
};

int main() {
    int N;
    cin >> N;
    priority_queue<Student, vector<Student>, CompareStudent> pq;
    
    for (int i = 0; i < N; i++) {
        Student s;
        cin >> s.name >> s.roll >> s.marks;
        pq.push(s);
    }
    
    int Q;
    cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        int command;
        cin >> command;
        
        if (command == 0) {
            Student s;
            cin >> s.name >> s.roll >> s.marks;
            pq.push(s);
            Student top = pq.top();
            cout << top.name << " " << top.roll << " " << top.marks << endl;
        } else if (command == 1) {
            if (pq.empty()) {
                cout << "Empty" << endl;
            } else {
                Student top = pq.top();
                cout << top.name << " " << top.roll << " " << top.marks << endl;
            }
        } else if (command == 2) {
            if (pq.empty()) {
                cout << "Empty" << endl;
            } else {
                pq.pop();
                if (pq.empty()) {
                    cout << "Empty" << endl;
                } else {
                    Student top = pq.top();
                    cout << top.name << " " << top.roll << " " << top.marks << endl;
                }
            }
        }
    }
    
    return 0;
}