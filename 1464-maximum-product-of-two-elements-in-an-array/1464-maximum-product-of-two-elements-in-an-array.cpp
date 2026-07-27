class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mini=nums[0],maxi=nums[0];
        int ans=INT_MIN;
        for(int i=1;i<nums.size();i++){
                ans=max(ans,(nums[i]-1)*(maxi-1));
                maxi=max(maxi,nums[i]);
        }
        return ans;
    }
};