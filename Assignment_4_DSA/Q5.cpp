#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2;

void push(int x) {
    q2.push(x);
    while(!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1, q2);
}

int pop() {
    if(q1.empty()) return -1;
    int val = q1.front();
    q1.pop();
    return val;
}

int top() {
    if(q1.empty()) return -1;
    return q1.front();
}

bool isEmpty() {
    return q1.empty();
}

int main() {
    push(10);
    push(20);
    push(30);

    cout << pop() << endl;
    cout << top() << endl;
    cout << pop() << endl;
    return 0;
}

// int pop() {
//     if(q1.empty()) return -1;
//     while(q1.size() > 1) {
//         q2.push(q1.front());
//         q1.pop();
//     }
//     int val = q1.front();
//     q1.pop();
//     swap(q1, q2);
//     return val;
// }