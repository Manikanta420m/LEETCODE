class Solution {
public:
    string processStr(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='*' and ans.size()>0)ans.pop_back();
          else if(s[i]=='#' and ans.size()>0)ans=ans+ans;
          else if(s[i]=='%' and ans.size()>0)reverse(ans.begin(),ans.end());
          else if(s[i]>='a' and s[i]<='z')ans.push_back(s[i]);
        }
        return ans;
    }
};