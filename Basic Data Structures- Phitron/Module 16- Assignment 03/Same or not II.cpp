#include <iostream>
#include <vector>
using namespace std;

// class Stack {
//     private:
//         vector<int> v;
//     public:
//         void push(int x) {
//             v.push_back(x);
//         }

//         void pop() {
//             v.pop_back();
//         }

//         int top() {
//             if (!v.empty()) {
//                 return v.front();
//             }
//         }
        
//         int size() {
//             return v.size();
//         }

//         int empty() {
//             return v.empty();
//         }

// };

class Node {
    public:
        Node* next;
        Node* prev;
        int value;

    Node(int value) {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};


class Stack {
    public:
        Node* head = NULL;
        Node* tail = NULL;
        int sz = 0; 

    void push (int value) {
        sz++;
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = tail->next;
    }
    
    void pop() {
        sz--;
        Node* deleteNode = tail;
        tail = tail->prev;
        if (tail == NULL) {
            head = NULL;
        } else {
            tail->next = NULL;
        }
        delete deleteNode;
    }

    int top() {
        return tail->value;
    }

    int size() {
        return sz;
    }

    bool empty() {
        if (sz == 0) {
            return true;
        } else {
            return false;
        }
    }
};

class Queue {
    public:
        Node* head = NULL;
        Node* tail = NULL;
        int sz = 0;
    
    void push(int value) {
        sz++;
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = tail->next;
    }

    void pop() {
        sz--;
        Node* deleteNode = head;
        head = head->next;
        if(head == NULL) {
            tail = NULL;
            delete deleteNode;
            return; 
        }

        head->prev = NULL;
        delete deleteNode;
    }

    int front() {
        return head->value;
    }

    int size () {
        return sz;
    }

    bool empty() {
        if (sz == 0) return true;
        else return false;
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    Stack A;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        A.push(x);
    }

    Queue B;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        B.push(x);
    }

    if (N != M) {
        cout << "NO";
        return 0;
    }

    bool isEqual = true;
    if (M == N) {
        while (!A.empty() && !B.empty()) {
            if (A.top() != B.front()) {
                isEqual = false;
                break;
            }
            A.pop();
            B.pop();
        } 
    }

    if (isEqual) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}