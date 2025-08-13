#include <iostream>
using namespace std;

void reverse_array(int arr[],int n){
    int i=0,j=n-1;
    while(i<j){
        int x=arr[i];
        arr[i]=arr[j];
        arr[j]=x;
        i++;
        j--;
    }
}

int main(){
    int arr[5]={1,2,3,4,5};
    int n=5;
    reverse_array(arr,n);
    for(int values:arr){
        cout<< values << " ";
    }
    cout << endl;
    return 0;
}