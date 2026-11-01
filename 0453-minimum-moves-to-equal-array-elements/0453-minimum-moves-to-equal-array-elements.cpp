class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size(),ans=0;
        unordered_set<int>st(nums.begin(),nums.end());
        if(st.size()==1)return 0;
        sort(nums.begin(),nums.end());
        for(auto i:nums)ans+=(i-nums[0]);
        return ans;
    }
};