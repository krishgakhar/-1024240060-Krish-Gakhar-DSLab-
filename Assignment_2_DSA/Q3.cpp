#include <iostream>
using namespace std;

void binarySearch(int arr[],int n){
    int start=0,end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]!=mid+1 && arr[mid-1]==mid){
            cout << "Missing element is " << arr[mid]-1;
            break;
        }
        else if(arr[mid]==mid+1){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
}

int main(){
    int arr[5]={1,2,4,5,6};
    int n=sizeof(arr)/sizeof(int);
    binarySearch(arr,n);
    return 0;
}