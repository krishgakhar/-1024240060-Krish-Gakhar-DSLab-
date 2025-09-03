#include<iostream>
#include<stack>
using namespace std;

int main(){
    int A[]= {1, 3, 2, 4};
    int G[4];
    stack <int> st;

    for(int i=3;i>=0;i--){
        while(!st.empty() && A[i]>=st.top()){
            st.pop();
        }
        if(st.empty()){
            G[i]=-1;
        }
        else{
            G[i]=st.top();
        }
        st.push(A[i]);
    }

    for(int c:G){
        cout << c << " ";
    }

}
