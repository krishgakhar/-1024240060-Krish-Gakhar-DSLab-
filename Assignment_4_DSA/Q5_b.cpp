#include<iostream>
#include<vector>
#include<queue>
using namespace std;

queue<int> q;

void push(int val){
    q.push(val);
    for(int i=0;i<q.size()-1;i++){
        q.push(q.front());
        q.pop();
    }
}

int pop() {
    if(q.empty()) return -1;
    int val = q.front();
    q.pop();
    return val;
}

int top() {
    if(q.empty()) return -1;
    return q.front();
}

bool isEmpty() {
    return q.empty();
}

int main() {
    push(10);
    push(20);
    push(30);

    cout << pop() << endl; 
    cout << top() << endl;  
    cout << pop() << endl;  
    cout << isEmpty() << endl; 
    cout << pop() << endl;  
    cout << isEmpty() << endl; 
    return 0;
}