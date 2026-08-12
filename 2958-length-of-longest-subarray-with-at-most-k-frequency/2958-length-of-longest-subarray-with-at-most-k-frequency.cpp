class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size(),ans=0;
        unordered_map<int,int>mp;
        int l=0,r=0;
        while(r<n){
           mp[nums[r]]++;
           while(mp[nums[r]]>k){
            if(mp[nums[l]]>1) mp[nums[l]]--;
            else mp.erase(nums[l]);
            l++;
           }
           ans=max(ans,r-l+1);
           r++;
        }
        return ans;
    }
};