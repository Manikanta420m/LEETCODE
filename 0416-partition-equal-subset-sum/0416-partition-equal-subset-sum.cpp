class Solution {
public:

    bool f(int idx,vector<vector<int>>&dp,vector<int>& nums,int target,int n){
        if(target==0)return true;
        if(idx==0)return nums[0]==target;
        if(dp[idx][target]!=-1)return dp[idx][target];
        bool take=false;
        bool noti=f(idx-1,dp,nums,target,n);
        if(nums[idx]<=target)
          take=f(idx-1,dp,nums,target-nums[idx],n);
        return dp[idx][target]=noti||take;
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto &i:nums)sum+=i;
        vector<vector<int>>dp(n,vector<int>((sum/2)+1,-1));
        if(sum&1)return false;
        return f(n-1,dp,nums,sum/2,n);

    }
};