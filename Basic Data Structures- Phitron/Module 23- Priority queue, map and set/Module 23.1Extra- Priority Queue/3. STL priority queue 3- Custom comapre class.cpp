#include <iostream>
#include <queue>
using namespace std;

class Student {
    public:
        string name;
        int roll;
        int marks;

        Student (string name, int roll, int marks) {
            this->name = name;
            this->roll = roll;
            this->marks = marks;
        }
};

class customCompareClass {
    public:
        bool operator()(Student left, Student right) {
            // if (left.marks < right.marks) return true;
            // else return false;
            if (left.marks > right.marks) return true;
            else if (left.marks < right.marks) return false;
            else return left.marks > right.marks;
        }
};

int main() {
    priority_queue<Student, vector<Student>, customCompareClass> pq;
    int numberOfStudents;
    cin >> numberOfStudents;
    for (int i = 0; i < numberOfStudents; i++) {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;

        Student obj(name, roll, marks);
        pq.push(obj);
    }

    while (!pq.empty()) {
        cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << " " << endl;
        pq.pop();    
    }

    return 0;
}