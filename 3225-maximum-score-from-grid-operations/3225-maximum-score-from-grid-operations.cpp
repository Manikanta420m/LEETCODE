class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<long long>> preSum(2, vector<long long>(n + 1, 0));

        for (int i = 0; i < n; i++) {
            preSum[0][i + 1] = preSum[0][i] + grid[i][0];
        }

        vector<vector<vector<long long>>> dp(2,
            vector<vector<long long>>(n + 1, vector<long long>(2, 0)));

        int prev = 0, curr = 1;

        for (int col = 0; col < n - 1; col++) {

            for (int i = 0; i < n; i++) {
                preSum[curr][i + 1] = preSum[curr][i] + grid[i][col + 1];
            }

            long long preMax = dp[prev][0][1];

            for (int k = 1; k <= n; k++) {
                dp[curr][k][0] = dp[curr][k][1] = max(
                    dp[prev][k][0],
                    preMax + preSum[prev][k]
                );

                preMax = max(preMax,
                             dp[prev][k][1] - preSum[prev][k]);
            }

            long long sufMax = dp[prev][n][0] + preSum[curr][n];

            for (int k = n - 1; k > 0; k--) {
                dp[curr][k][0] = max(
                    dp[curr][k][0],
                    sufMax - preSum[curr][k]
                );

                sufMax = max(sufMax,
                             dp[prev][k][0] + preSum[curr][k]);
            }

            dp[curr][0][0] = sufMax;
            dp[curr][0][1] = max(dp[prev][0][0], dp[prev][n][0]);

            swap(prev, curr);
        }

        long long ans = 0;
        for (int k = 0; k <= n; k++) {
            for (int t = 0; t < 2; t++) {
                ans = max(ans, dp[prev][k][t]);
            }
        }

        return ans;
    }
};