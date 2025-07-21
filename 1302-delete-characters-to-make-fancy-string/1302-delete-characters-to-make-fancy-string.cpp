class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            if(ans.size()>=2 and s[i]==s[i-1] and s[i]==s[i-2])continue;
            else ans.push_back(s[i]);
        }
        return ans;
    }
};