class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans=0,maxi=nums[0],c=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>maxi){
                ans+=(c*maxi);
                maxi=nums[i];
                c=1;
            }
            else c++;
        }
        ans+=(c-1)*maxi;
        return ans;
    }
};