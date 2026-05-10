class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(n,-1);
        dp[0]=0;
        for(int j=0;j<n;j++){
            for(int i=j-1;i>=0;i--){
                if(nums[j]-nums[i]>=-target and nums[j]-nums[i]<=target){
                    if(dp[i]!=-1){
                        dp[j]=max(dp[j],dp[i]+1);
                    }
                }
            }
        }
        return dp[n-1];
    }
};