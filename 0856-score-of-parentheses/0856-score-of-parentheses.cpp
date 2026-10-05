class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans=0;
        int cur=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')cur++;
            else{
                cur--;
                if(s[i-1]=='('){
                    ans+=(1<<cur);
                }
            }
        }
        return ans;
    }
};