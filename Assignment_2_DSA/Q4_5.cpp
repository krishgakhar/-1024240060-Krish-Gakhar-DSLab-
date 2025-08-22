#include <iostream>
using namespace std;

int main() {
    string str = "HELLO WORLD";  

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;  
        }
    }

    cout << "Lowercase string: " << str;
    return 0;
}
