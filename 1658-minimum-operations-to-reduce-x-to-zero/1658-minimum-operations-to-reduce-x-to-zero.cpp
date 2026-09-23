class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int s = 0;

        for (int v : nums) {
            s += v;//TOTALSUM
        }

        int t = s - x;//TARGET

        if (t == 0) {
            return n;
        }

        if (t < 0) {
            return -1;
        }

        int l = 0;//MAX-LENGTH
        int w = 0;//CURRENT-SUM
        int best = -1;//LEFT

        for (int r = 0; r < n; r++) {
            w += nums[r];

            while (w > t) {
                w -= nums[l++];
            }

            if (w == t) {
                best = max(best, r - l + 1);
            }
        }

        return best == -1 ? -1 : n - best;
    }
};