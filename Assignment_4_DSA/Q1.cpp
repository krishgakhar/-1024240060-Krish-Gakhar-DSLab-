#include <iostream>
#include <vector>
using namespace std;

int f =-1, r =-1; 

bool isEmpty(vector<int> &arr) {
    return (f == -1 && r == -1);
}

bool isFull(vector<int> &arr) {
    return (r == arr.size() - 1);
}

void enqueue(vector<int> &arr, int value) {
    if (isFull(arr)) {
        cout << "The queue is full" << endl;
    } 
    else {
        if (f == -1) f = 0; 
        r++;
        arr[r] = value;
        cout << value << " inserted" << endl;
    }
}

void dequeue(vector<int> &arr) {
    if (isEmpty(arr)) {
        cout << "queue is empty" << endl;
    } 
    else {
        cout << arr[f] << " removed" << endl;
        if (f == r) {
            f = r = -1;
        } 
        else {
            f++;
        }
    }
}

void display(vector<int> &arr) {
    if (isEmpty(arr)) {
        cout << "queue is empty" << endl;
    } 
    else {
        cout << "Queue elements: ";
        for (int i = f; i <= r; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
void peek(vector<int> &arr) {
    if (isEmpty(arr)) {
        cout << "queue empty" << endl;
    } 
    else {
        cout << "front element : " << arr[f] << endl;
    }
}

int main() {
    int n = 5;
    vector<int> arr(n); 

    enqueue(arr, 10);
    enqueue(arr, 20);
    enqueue(arr, 30);
    display(arr);

    dequeue(arr);
    display(arr);
    peek(arr);

    return 0;
}
