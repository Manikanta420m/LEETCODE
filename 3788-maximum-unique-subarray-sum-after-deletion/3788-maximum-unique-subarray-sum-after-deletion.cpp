class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=max(0,nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>=0 and nums[i]!=nums[i-1] and i>0)ans+=nums[i];
        }
        return (ans==0?nums[nums.size()-1]:ans);
    }
};