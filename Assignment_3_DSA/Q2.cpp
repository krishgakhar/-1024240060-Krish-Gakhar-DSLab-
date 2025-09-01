#include<iostream>
#include<stack>
using namespace std;

int main(){
    string x="DataStructure";
    
    stack<char> st;
    for(char c: x){
        st.push(c);
    }

    string reversedString;
    while(!st.empty()){
        reversedString+=st.top();
        st.pop();
    }

    cout << "the reversed string is : " << reversedString << endl;

    return 0;
}
