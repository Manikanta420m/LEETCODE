class Solution {
private:
    bool solve(int idx,string s,unordered_set<string>st,vector<int>&dp){
        if(idx>=s.size())return true;
        if(dp[idx]!=-1)return dp[idx];
          
        for(int i=idx;i<s.size();i++){
            string s1=s.substr(idx,i-idx+1);
            if(st.find(s1)!=st.end() && solve(i+1,s,st,dp)){
                return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        vector<int>dp(s.size(),-1);
        return solve(0,s,st,dp);
    }
};