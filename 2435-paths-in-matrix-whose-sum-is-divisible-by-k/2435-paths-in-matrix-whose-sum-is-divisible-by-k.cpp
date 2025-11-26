class Solution {
public:
    const int MOD= 1e9+7;
    int m,n;
    vector<vector<vector<int>>> dp;
    int solve(vector<vector<int>>& grid, int k,int m, int n,int rem){
        if(m<0 || n<0) return 0;
        rem= (rem+grid[m][n])%k;
        if(m==0 && n==0) return rem==0?1:0;
        if(dp[m][n][rem]!=-1) return dp[m][n][rem];

        int up=solve(grid,k,m-1,n,rem);
        int left=solve(grid,k,m,n-1,rem);
        return dp[m][n][rem]=(up+left)%MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        dp.resize(m,vector<vector<int>>(n,vector<int>(k,-1)));
        return solve(grid,k,m-1,n-1,0);
    }
};