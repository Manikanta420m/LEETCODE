class Solution {
    long long b = 215215;
    long long M = (1LL << 31) - 1;

private:
    bool check(int len, vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, int> mp;

        long long h = 0, p = 1;

        // p = b^(len-1)
        for (int i = 1; i < len; i++) {
            p = (p * b) % M;
        }

        // first window
        for (int i = 0; i < len; i++) {
            h = (h * b + (nums[i] % M + M) % M) % M;
        }
        mp[h]++;

        // next windows
        for (int i = len; i < n; i++) {
            long long out = (nums[i - len] % M + M) % M;
            long long in  = (nums[i] % M + M) % M;

            h = (h - out * p % M + M) % M;
            h = (h * b + in) % M;

            mp[h]++;
        }

        for (auto &x : mp) {
            if (x.second == 1) return true;
        }
        return false;
    }

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        int l = 1, r = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid, nums)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};