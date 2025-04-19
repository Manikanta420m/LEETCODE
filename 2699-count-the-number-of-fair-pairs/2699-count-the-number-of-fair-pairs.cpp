class Solution {
    #define ll long long
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ll n=nums.size(),ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            auto u=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i]);
            auto l=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i]);
            ans+=(u-l);
        }return ans;
    }
};