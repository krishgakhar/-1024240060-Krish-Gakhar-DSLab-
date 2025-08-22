#include <iostream>
using namespace std;

int main() {
    int arr[4][4] = {
        {1, 2, 0, 0},
        {0, 0, 3, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    int nonZero = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[i][j] != 0) nonZero++;
        }
    }

    int sparseMatrix[20][3];  
    sparseMatrix[0][0] = 4;       
    sparseMatrix[0][1] = 4;       
    sparseMatrix[0][2] = nonZero; 

    int k = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[i][j] != 0) {
                sparseMatrix[k][0] = i;
                sparseMatrix[k][1] = j;
                sparseMatrix[k][2] = arr[i][j];
                k++;
            }
        }
    }

    int transpose[20][3];
    transpose[0][0] = sparseMatrix[0][1];
    transpose[0][1] = sparseMatrix[0][0];
    transpose[0][2] = sparseMatrix[0][2];

    int t = 1;
    for (int i = 1; i <= nonZero; i++) {
        transpose[t][0] = sparseMatrix[i][1];
        transpose[t][1] = sparseMatrix[i][0];
        transpose[t][2] = sparseMatrix[i][2];
        t++;
    }

    cout << "Sparse Matrix (Triplet Form)\n";
    cout << "ROW  COLUMN  VALUE\n";
    for (int i = 0; i <= nonZero; i++) {
        cout << sparseMatrix[i][0] << "      "
             << sparseMatrix[i][1] << "       "
             << sparseMatrix[i][2] << endl;
    }

    cout << "Transpose (Triplet Form)\n";
    cout << "ROW  COLUMN  VALUE\n";
    for (int i = 0; i <= nonZero; i++) {
        cout << transpose[i][0] << "      "
             << transpose[i][1] << "       "
             << transpose[i][2] << endl;
    }

    return 0;
}