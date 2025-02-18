class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.size();
        stack<int>st;
        string ans="";
        for(int i=1;i<=n+1;i++){
            st.push(i);
            char c=pattern[i-1];
            if(c=='I' || i==n+1){
                while(!st.empty()){
                    ans.push_back(char('0'+st.top()));
                    st.pop();
                }
            }
        }return ans;
    }
};