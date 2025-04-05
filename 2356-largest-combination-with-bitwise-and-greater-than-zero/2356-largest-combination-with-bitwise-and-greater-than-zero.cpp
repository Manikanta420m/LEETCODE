class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxi = 0;
        for (int i = 0; i < 32; i++) {
            int ans = 0;
            for (auto j : candidates) {
                if (j & (1 << i))
                    ans++;
            }
            maxi = max(maxi, ans);
        }
        return maxi;
    }
};