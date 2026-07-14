class Solution {
public:
    static const int MOD = 1e9 + 7;

    int n, mx;
    vector<int> nums;
    vector<vector<vector<int>>> dp;

    int solve(int i, int g1, int g2) {
        if (i == n)
            return (g1 > 0 && g1 == g2);

        int &ans = dp[i][g1][g2];
        if (ans != -1) return ans;

        long long res = 0;

        // Skip
        res += solve(i + 1, g1, g2);

        // Put in seq1
        int ng1 = (g1 == 0) ? nums[i] : gcd(g1, nums[i]);
        res += solve(i + 1, ng1, g2);

        // Put in seq2
        int ng2 = (g2 == 0) ? nums[i] : gcd(g2, nums[i]);
        res += solve(i + 1, g1, ng2);

        return ans = res % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();

        mx = *max_element(nums.begin(), nums.end());

        dp.assign(n,
                  vector<vector<int>>(mx + 1,
                  vector<int>(mx + 1, -1)));

        return solve(0, 0, 0);
    }
};