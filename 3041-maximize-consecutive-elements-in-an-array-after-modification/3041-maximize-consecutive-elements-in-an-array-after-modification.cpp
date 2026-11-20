class Solution {
public:
    int n;  
    vector<vector<int>> memo;
    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();

        memo.assign(n + 1, vector<int>(2, -1));
        sort(begin(nums), end(nums));

        int res = 1;
        for(int i = 0; i < n; i++){
            res = max({res, solve(i, 0, nums), solve(i, 1, nums)});
        }

        return res;
        
    }


    int solve(int i, int inc, vector<int>& nums){
        if(memo[i][inc] != -1) return memo[i][inc];
        int currVal = nums[i] + inc;
        int len = 1;

        int j = findVal(nums, i + 1, currVal + 1);
        if(j != -1){
            len = max(len, 1 + solve(j, 0, nums));

        }

        j = findVal(nums, i + 1, currVal);
        if(j != -1){
            len = max(len, 1 + solve(j, 1, nums));

        }

        return memo[i][inc] = len;
    }

    int findVal(vector<int>& nums, int start, int el){
        int j = lower_bound(begin(nums) + start, end(nums), el) - begin(nums);

        if(j < n && nums[j] == el) return j;
        return -1;
    }
};