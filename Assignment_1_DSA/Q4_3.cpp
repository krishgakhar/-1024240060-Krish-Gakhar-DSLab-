#include<iostream>
using namespace std;

int main(){
    int A[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    
    int T[3][3]={0};

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            
                T[i][j]=A[j][i];
            
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout << T[i][j] << " ";
            }
            cout<< endl ;
        }

}