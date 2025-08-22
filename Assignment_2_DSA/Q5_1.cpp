#include<iostream>
using namespace std;

int main(){
    int elements[]={1,2,3};

    int DiagonalMatrix[3][3];
    int k=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==j){
                DiagonalMatrix[i][j]=elements[k] ;
                k++;
            }
            else{
                DiagonalMatrix[i][j]=0;
            }
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout << DiagonalMatrix[i][j] << " ";
        }
        cout << endl;
    }
}