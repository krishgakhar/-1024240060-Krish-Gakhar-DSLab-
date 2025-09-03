class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack <int> st;
        vector<int> array(temperatures.size());

        for(int i=temperatures.size()-1;i>=0;i--){
            while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
                st.pop();
            }
            if(st.empty()){
                array[i]=0;
            }
            else{
                array[i]=st.top()-i;
            }
            st.push(i);
            
        }
        return array;
        
    }
};