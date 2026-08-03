class Solution {
    int n;
    const int MIN=-50000001;
    int solve(int idx,vector<int>& stoneValue,vector<int>&dp){
        if(idx==n)return 0;
        if(dp[idx]!=MIN)return dp[idx];
        int ans=MIN;
        if(idx<n)ans=max(ans,stoneValue[idx]-solve(idx+1,stoneValue,dp));
        if(idx<n-1)ans=max(ans,stoneValue[idx]+stoneValue[idx+1]-solve(idx+2,stoneValue,dp));
        if(idx<n-2)ans=max(ans,stoneValue[idx]+stoneValue[idx+1]+stoneValue[idx+2]-solve(idx+3,stoneValue,dp));
        return dp[idx]=ans;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        vector<int>dp(n,MIN);
        int res=solve(0,stoneValue,dp);
        if(res>0)return "Alice";
        if(res==0)return "Tie";
        return "Bob";
    }
};