#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 5, 3, 2, 3, 7, 5};  
    int n = sizeof(arr) / sizeof(arr[0]);

    int distinctCount = 0;

    for (int i = 0; i < n; i++) {
        bool distinct = true;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                distinct = false;
                break;
            }
        }
        if (distinct) {
            distinctCount++;
        }
    }

    cout << "No. of distinct elements: " << distinctCount << endl;
    return 0;
}
