class Solution {
    const int M=1e9+7;
private:
    int solve(int i,int n,int k,vector<vector<vector<int>>>&dp,bool f){
        if(k==0)return 1;
        if(i>=n)return 0;
        if(dp[i][k][f]!=-1)return dp[i][k][f];
        int cnt=solve(i+1,n,k,dp,f);
        if(f)cnt+=solve(i,n,k-1,dp,!f);
        else cnt+=solve(i+1,n,k,dp,!f);
        return dp[i][k][f]=cnt%M;
    }
public:
    int numberOfSets(int n, int k) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return solve(0,n,k,dp,false);
    }
};