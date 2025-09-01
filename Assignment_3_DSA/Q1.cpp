#include <iostream>
using namespace std;

int main() {
    int stack[100];
    int top = -1;
    int n;

    cout << "Enter size of stack: ";
    cin >> n;

    int choice;
    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Check if Empty\n";
        cout << "4. Check if Full\n";
        cout << "5. Display Stack\n";
        cout << "6. Peek Top Element\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1) {
            if(top == n - 1) {
                cout << "Stack Overflow!\n";
            } else {
                int val;
                cout << "Enter value to push: ";
                cin >> val;
                top++;
                stack[top] = val;
                cout << val << " pushed to stack.\n";
            }
        } 
        else if(choice == 2) {
            if(top == -1) {
                cout << "Stack Underflow!\n";
            } else {
                cout << stack[top] << " popped from stack.\n";
                top--;
            }
        } 
        else if(choice == 3) {
            if(top == -1) cout << "Stack is Empty.\n";
            else cout << "Stack is not Empty.\n";
        } 
        else if(choice == 4) {
            if(top == n - 1) cout << "Stack is Full.\n";
            else cout << "Stack is not Full.\n";
        } 
        else if(choice == 5) {
            if(top == -1) {
                cout << "Stack is Empty.\n";
            } else {
                cout << "Stack elements: ";
                for(int i = 0; i <= top; i++) {
                    cout << stack[i] << " ";
                }
                cout << endl;
            }
        } 
        else if(choice == 6) {
            if(top == -1) {
                cout << "Stack is Empty.\n";
            } else {
                cout << "Top element: " << stack[top] << endl;
            }
        } 
        else if(choice == 7) {
            cout << "Exiting...\n";
        } 
        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 7);

    return 0;
}
