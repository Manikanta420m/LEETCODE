class Solution {
public:
    int countSubarrays(vector<int>& nums) {
      int ans=0;
        for(int i=1;i<nums.size()-1;i++){int s=0;
           
            if(nums[i-1]+nums[i+1]==double(nums[i])/2)ans++;
        }
        return ans;
    }
};