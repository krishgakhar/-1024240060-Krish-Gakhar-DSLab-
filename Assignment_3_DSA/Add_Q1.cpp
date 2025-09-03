#include<iostream>
#include<stack>
using namespace std;

int main(){
    int A[]= {4, 5, 2, 10, 8};
    int G[5];
    stack <int> st;

    for(int i=0;i<5;i++){
        while(!st.empty() && A[i]<=st.top()){
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
