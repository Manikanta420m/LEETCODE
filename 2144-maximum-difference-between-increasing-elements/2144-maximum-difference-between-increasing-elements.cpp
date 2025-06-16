class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini=nums[0],ans=-1;
        for(int i=1;i<nums.size();i++){
            if(mini<nums[i]){
                ans=max(ans,nums[i]-mini);
            }
            mini=min(mini,nums[i]);
        }
        return ans;
    }
};