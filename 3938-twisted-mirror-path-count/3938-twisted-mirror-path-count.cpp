class Solution {
public:
     int mod=1e9+7;
    int fn(vector<vector<int>>& grid,int i,int j,vector<vector<vector<int>>>&dp,int n,int m,int dir)
    {
        if(i>=n || j>=m) return 0;
        
        if(i==n-1 && j==m-1) return 1;

        if(dp[i][j][dir]!=-1) return dp[i][j][dir];

        if(grid[i][j]==1)
        {
            if(dir==1)
            {
                return fn(grid,i+1,j,dp,n,m,0);
                
            }
            else if(dir==0)
            {
                return fn(grid,i,j+1,dp,n,m,1);
                
            }
        }

        long long  move=0;
        
            move+=fn(grid,i,j+1,dp,n,m,1);
        
            move+=fn(grid,i+1,j,dp,n,m,0);
            
        return dp[i][j][dir]=move%mod;
    }
    int uniquePaths(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(2,-1)));

        return fn(grid,0,0,dp,n,m,0);
        
        
        
    }
};