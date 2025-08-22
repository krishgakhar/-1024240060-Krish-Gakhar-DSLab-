#include <iostream>
using namespace std;

void binarySearch(int arr[],int n,int target){
    int start=0,end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==target){
            cout << "Element found at index " << mid;
            break;
        }
        else if(arr[mid]>target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
}

int main(){
    int arr[6]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(int);
    binarySearch(arr,n,7);
    return 0;
}