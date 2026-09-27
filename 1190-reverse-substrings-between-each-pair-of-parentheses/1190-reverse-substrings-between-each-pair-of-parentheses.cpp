class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<int>st;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(ans.size());
            }
            else if (s[i]==')'){
                int l=st.top();
                st.pop();
                int r=ans.size()-1;
                reverse(ans.begin()+l,ans.begin()+r+1);
            }
            else ans+=s[i];
        }
        return ans;
    }
};