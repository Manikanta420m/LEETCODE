class Solution {
private:
    int solve(int n,vector<int>&dp){
        if(n==0)return 1;
        if(dp[n]!=-1)return dp[n];
        int ans=1;
        for(int i=1;i<=n;i++){
            ans=max(ans,i*solve(n-i,dp));
        }
        return dp[n]=ans;
    }
public:
    int integerBreak(int n) {
        if(n<=3)return n-1;
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};