class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n=nums.size();
        vector<long long>dp(n+1,0);
        dp[0]+=nums[0];
        for(int i=1;i<n;i++){
            if(colors[i]==colors[i-1]){
                if(i>=2)dp[i]+=max(dp[i-2]+nums[i],dp[i-1]);
                else dp[i]=max(dp[i-1],dp[i]+nums[i]);
            }
            else dp[i]=dp[i-1]+nums[i];
        }
        return dp[n-1];
    }
};