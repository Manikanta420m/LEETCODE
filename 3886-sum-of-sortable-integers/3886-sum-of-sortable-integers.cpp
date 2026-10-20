class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 0);

        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + (nums[i - 1] > nums[i]);
        }

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool ok = true;
            int prevmax = INT_MIN;
            for (int i = 0; i < n; i += k) {
                int mn = INT_MAX, mx = INT_MIN;
                for (int j = i; j < i + k; j++) {
                    mn = min(mn, nums[j]);
                    mx = max(mx, nums[j]);
                }
                int desc = pre[i + k - 1] - pre[i];
                if (desc > 1 || (desc == 1 && nums[i] < nums[i + k - 1])) {
                    ok = false; break;
                }
                if (i > 0 && prevmax > mn) {
                    ok = false;break;
                    }
                prevmax = mx;
                    }
            if (ok) ans += k;
                   }
        return ans;
    }
};