class Solution {
public:
    void solve(int i,string &s,vector<string>&ans){
        if(i>=s.size()){ans.push_back(s);return;}
        if(isdigit(s[i])){solve(i+1,s,ans);return;}
        s[i]=toupper(s[i]);
        solve(i+1,s,ans);
        s[i]=tolower(s[i]);
        solve(i+1,s,ans);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        solve(0,s,ans);
        return ans;
    }
};