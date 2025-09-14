#include<iostream>
#include<vector>
using namespace std;

int f=-1,r=-1;

bool isEmpty(vector<int> &arr){
    return (f==-1 && r==-1);
}

bool isFull(vector<int> &arr){
    return ((r+1)%arr.size()==f);
}

void enqueue(vector<int> &arr,int val){
    if(isFull(arr)){
        cout<< "the queue is full " << endl;
    }
    else{
        if(isEmpty(arr)){
            f=r=0;
        }
        else{
            r=(r+1)%arr.size();
        }
        arr[r]=val;
        cout << val << "inserted" << endl;
    }
}

void dequeue(vector<int> &arr){
    if(isEmpty(arr)){
        cout<< "the queue is empty" << endl;
    }
    else{
        cout << arr[f] << "removed" << endl;
        if(f==r){
            f=r=-1;
        }
        else{
            f=(f+1)%arr.size();
        }
    }
}

void peek(vector<int>&arr){
    if(isEmpty(arr)){
        cout <<"the queue is empty" << endl;
    }
    else{
        cout<< arr[f] << endl;
    }
}

void display(vector<int> &arr){
    if(isEmpty(arr)){
        cout <<"the queue is empty" << endl;
    }
    else{
        int i=f;
        while(true){
            cout<<arr[i] << " ";
            if(i==r) break;
            i=(i+1)%arr.size();

        }
        cout << endl;
    }

}
int main(){
    int n=5;
    vector<int> arr(5);

     enqueue(arr, 10);
    enqueue(arr, 20);
    enqueue(arr, 30);
    enqueue(arr, 40);

    display(arr);
    peek(arr);

    dequeue(arr);
    dequeue(arr);

    display(arr);
    peek(arr);

    enqueue(arr, 50);
    enqueue(arr, 60); 

    display(arr);

    return 0;
}
