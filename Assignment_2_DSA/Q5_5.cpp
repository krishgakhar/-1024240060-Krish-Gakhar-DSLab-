#include<iostream>
using namespace std;

int main() {
    int elements[] = {1,2,3,4,5,6,7,8,9,10}; 

    int n = 4;
    int Sym[4][4];
    int k = 0;


    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            Sym[i][j] = elements[k++];
            Sym[j][i] = Sym[i][j]; 
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << Sym[i][j] << " ";
        }
        cout << endl;
    }
}
