#include <iostream>
#include <queue>
#include <climits>
using namespace std;

void display(queue<int> q) {
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int minimumElement(queue<int> q, int n,int prevmin) {
    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (prevmin < q.front() && q.front() < min) {
            min = q.front();
        }
        q.pop();
    }
    return min;
}

int main() {
    queue<int> q;
    int arr[4] = {4,3,2,1};
    for (int a : arr) {
        q.push(a);
    }
    int prevmin=INT_MIN;

    int n = q.size();
    int m = q.size();
    int originalcount=0;
    while (m!= 0) {

        int min = minimumElement(q, n,prevmin);
        prevmin=min;

        for(int i=0;i<originalcount;i++){
            q.push(q.front());
            q.pop();
        }
        q.push(min);
     
        m--;
    }
    for (int i = 0; i < n; i++) {
            q.pop();
        }

    display(q);
    return 0;
}