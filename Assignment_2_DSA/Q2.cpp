#include <iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    bool swapped=false;
    for(int i=0; i < n-1 ; i++){
        for(int j=0; j < n-i-1 ; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

int main() {
    int arr[7]={64,34,25,12,22,11,90};
    int n=sizeof(arr)/sizeof(int);
    bubbleSort(arr,n);
    for(int values:arr){
        cout << values << " ";
    }
    cout << endl;
    return 0;
}