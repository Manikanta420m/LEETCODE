class Solution {
public:
    int n, m;
    int solve(int i, int j, int k, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if (k < 0) return -1e9;
        if(i==n or j==m)return -1e9;
        if (i == n - 1 && j == m - 1) {
            if (min(grid[i][j],1)<=k)return grid[i][j];
            return -1e9;
        }
        if (dp[i][j][k] != -1) return dp[i][j][k];
        int right=grid[i][j]+solve(i,j+1,k-min(grid[i][j],1),grid,dp);
        int down=grid[i][j]+solve(i+1,j,k-min(grid[i][j],1),grid,dp);
        int best = max(down, right);
        return dp[i][j][k] = best;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(k + 1, -1)));
        int res = solve(0, 0, k, grid, dp);
        return (res <0 ? -1 : res);
    }
};
