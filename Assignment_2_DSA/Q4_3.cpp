#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "Hello World";
    int n = str.length();
    string new_str;

    for (int i = 0; i < n; i++) {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && 
            str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
            new_str += str[i]; 
        }
    }

    cout << "String without vowels: " << new_str << endl;
    return 0;
}
