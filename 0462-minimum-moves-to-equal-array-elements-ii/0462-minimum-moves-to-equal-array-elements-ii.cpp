class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n= nums.size(),mid=0,ans=0;
        sort(nums.begin(),nums.end());
        if(n&1)mid=nums[n/2];
        else mid=(nums[n/2]+nums[(n/2)-1])/2;
        for(auto i:nums)ans+=abs(i-mid);
        return ans;
    }
};