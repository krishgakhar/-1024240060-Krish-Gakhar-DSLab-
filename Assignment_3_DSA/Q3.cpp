//I have copied this solution from leetcode where this question was already solved by me.
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            if(c=='('||c=='{'||c=='['){
                st.push(c);
            }
            else if(c==')'||c=='}'||c==']'){
                if(st.empty()){
                    return false;
                }
                if(c==')' && st.top()=='(' ){
                    st.pop();
                }
                else if(c=='}' && st.top()=='{' ){
                    st.pop();
                }
                else if(c==']' && st.top()=='[' ){
                    st.pop();
                }
                else return false;
            }
        }
        return  st.empty();
            
        
        
    }
};