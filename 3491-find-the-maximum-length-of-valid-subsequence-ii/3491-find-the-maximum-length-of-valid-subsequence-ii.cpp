class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans=2;
        for(int i=0;i<k;i++){
            vector<int>dp(k,0);
            for(int j=0;j<nums.size();j++){
                int num=nums[j]%k;
                int pos=(i-num+k)%k;
                dp[num]=dp[pos]+1;
            }
            for(auto val:dp)ans=max(ans,val);
        }
        return ans;
    }
};