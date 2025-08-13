#include <iostream>
using namespace std;

void create(int arr[], int &n) {
    cout << "Enter number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insertElement(int arr[], int &n, int value, int index) {
    if (index < 0 || index > n) {
        cout << "Invalid index\n";
        return;
    }
    for (int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    n++;
}

int linearSearch(int arr[], int n, int value) {
    for (int i = 0; i < n; i++)
        if (arr[i] == value) return i;
    return -1;
}

void deleteElement(int arr[], int &n, int value) {
    int pos = linearSearch(arr, n, value);
    if (pos != -1) {
        for (int i = pos; i < n - 1; i++)
            arr[i] = arr[i + 1];
        n--;
    } else {
        cout << "not found";
    }
}

int main() {
    int arr[100], n = 0, choice = 0;
    while (choice != 6) {
        cout << "\nMENU\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                create(arr, n);
                break;
            case 2:
                display(arr, n);
                break;
            case 3: {
                int value, index;
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter index to insert at: ";
                cin >> index;
                insertElement(arr, n, value, index);
                break;
            }
            case 4:
                deleteElement(arr, n, 999);
                break;
            case 5: {
                int val = 1;
                int pos = linearSearch(arr, n, val);
                if (pos != -1) cout << val << " found at index " << pos << endl;
                else cout << val << " not found" << endl;
                break;
            }
            case 6:
                cout << "Exiting program";
                break;
        }
    }
    return 0;
}
