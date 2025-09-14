#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void display(queue<int>q){
    if(q.empty()) {
        cout << "the queue is empty" << endl;
    }
    else{
        while(!q.empty()){
            cout << q.front() << " ";
            q.pop();

        }
        cout << endl;
    }
}

int main(){
    queue<int> q1;
    queue<int> q2;
    queue<int> q3;
    q1.push(4);
    q1.push(7);
    q1.push(11);
    q1.push(20);
    q1.push(5);
    q1.push(9);
    display(q1);

    int half = q1.size() / 2;

    for(int i = 0; i < half; i++) {
        q2.push(q1.front());
        q1.pop();
    }
    display(q1);
    display(q2);

    while(!q1.empty() || !q2.empty()) {
        if(!q2.empty()) {
            q3.push(q2.front());
            q2.pop();
        }
        if(!q1.empty()) {
            q3.push(q1.front());
            q1.pop();
        }
    }
    display(q3);




    


}