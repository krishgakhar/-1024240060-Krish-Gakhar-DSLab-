#include<iostream>
using namespace std;

int main(){
    int A[3][3]={{1,2,3},{4,5,6},{7,8,9}};

    for(int i=0;i<3;i++){
        int rowSum=0;
        for(int j=0;j<3;j++){
            rowSum+=A[i][j];
        }
        cout << i+1 << ":" << rowSum << endl;
    }

    for(int j=0;j<3;j++){
        int colSum=0;
        for(int i=0;i<3;i++){
            colSum+=A[i][j];
        }
        cout << j+1 << ":" << colSum << endl;
    }

}