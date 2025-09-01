#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
int add(int a, int b){
    return a+b;
}
int diff(int a, int b){
    return a-b;
}

int multiply(int a, int b){
    return a*b;
}

int divide(int a,int b){
    return a/b;
}

int power(int a, int b){
    return pow(a,b);
}

int postfixEvaluation(string s){
    stack<int> st;
    int a,b;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else if(s[i]=='+'){
            b=st.top();
            st.pop();
            a=st.top();
            st.pop();
            st.push(add(a,b));

        }
        else if(s[i]=='-'){
            b=st.top();
            st.pop();
            a=st.top();
            st.pop();
            st.push(diff(a,b));

        }
        else if(s[i]=='*'){
            b=st.top();
            st.pop();
            a=st.top();
            st.pop();
            st.push(multiply(a,b));

        }
        else if(s[i]=='/'){
            b=st.top();
            st.pop();
            a=st.top();
            st.pop();
            st.push(divide(a,b));

        }
        else if(s[i]=='^'){
            b=st.top();
            st.pop();
            a=st.top();
            st.pop();
            st.push(power(a,b));

        }
    
    }
    return st.top();
}

int main(){
    string expression="73+52-*863/-/";
    cout << postfixEvaluation(expression) << endl;
}