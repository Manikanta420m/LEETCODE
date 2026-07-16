class Solution {
    int n, m;

    int solve(int i, int j, vector<vector<int>>& dungeon,
              vector<vector<int>>& dp) {

        if (i >= n || j >= m)
            return INT_MAX;

        if (i == n - 1 && j == m - 1)
            return max(1, 1 - dungeon[i][j]);

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solve(i, j + 1, dungeon, dp);
        int down = solve(i + 1, j, dungeon, dp);

        int need = min(right, down);

        if (need == INT_MAX)
            return dp[i][j] = INT_MAX;

        return dp[i][j] = max(1, need - dungeon[i][j]);
    }

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size();
        m = dungeon[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(0, 0, dungeon, dp);
    }
};