#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int elements[]={1,2,3,4,5,6,7,8,9,10,11,12,13};

    int TriDiagonal[5][5];
    int k=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i==j or abs(i-j)==1){
                TriDiagonal[i][j]=elements[k];
                k++;
            }
            else{
                TriDiagonal[i][j]=0;
            }
        }
    }

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout << TriDiagonal[i][j] << " ";
        }
        cout << endl;

    }
}