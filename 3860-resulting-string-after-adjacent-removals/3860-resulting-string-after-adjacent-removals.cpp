class Solution {
public:
    string resultingString(string s) {
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(!st.empty()){
                char ch=st.top();
                if(ch=='a' and (s[i]=='z' or s[i]=='b'))st.pop();
                else if(ch=='z' and (s[i]=='a' or s[i]=='y'))st.pop();
                else if(ch>'a' and ch<'z'){
                    if(ch==char(s[i]-1))st.pop();
                    else if(ch==char(s[i]+1))st.pop();
                    else st.push(s[i]);
                }
                else st.push(s[i]);
            }
            else st.push(s[i]);
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};