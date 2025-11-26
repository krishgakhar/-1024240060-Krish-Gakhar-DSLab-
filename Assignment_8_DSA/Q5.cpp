#include<bits/stdc++.h>
using namespace std;

void heapifymax(vector<int>& a , int n , int i){
    int big = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l<n && a[l] > a[big]) big = l;
    if(r<n && a[r] > a[big]) big = r;

    if(big != i){
        swap(a[i] , a[big]);
        heapifymax(a , n , big);
    }
}

void heapifymin(vector<int>& a , int n , int i){
    int sm = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l<n && a[l] < a[sm]) sm = l;
    if(r<n && a[r] < a[sm]) sm = r;

    if(sm != i){
        swap(a[i] , a[sm]);
        heapifymin(a , n , sm);
    }
}

void heapsortinc(vector<int>& a){
    int n = a.size();
    for(int i=n/2-1 ; i>=0 ; i--) heapifymax(a , n , i);

    for(int i=n-1 ; i>=0 ; i--){
        swap(a[0] , a[i]);
        heapifymax(a , i , 0);
    }
}

void heapsortdec(vector<int>& a){
    int n = a.size();
    for(int i=n/2-1 ; i>=0 ; i--) heapifymin(a , n , i);

    for(int i=n-1 ; i>=0 ; i--){
        swap(a[0] , a[i]);
        heapifymin(a , i , 0);
    }
}

int main(){

    vector<int> arr = {7,2,9,1,5,3};

    heapsortinc(arr);
   

    cout<<"inc   sort  ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<"   ";
    }

     heapsortdec(arr);
    cout<<"\n";

    cout<<"dec sort  ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<"    ";
    }

}
