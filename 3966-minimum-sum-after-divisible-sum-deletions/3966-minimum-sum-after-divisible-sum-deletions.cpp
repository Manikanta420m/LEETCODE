class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>pre(n+1,0);
        for(int i=1;i<=n;i++)pre[i]=pre[i-1]+nums[i-1];
        vector<long long>best(k,-1e18),dp(n+1,0);
        best[0]=0;
        for(int i=1;i<=n;i++){
           int m=pre[i]%k;
           dp[i]=dp[i-1];
           if(best[m]!=-1e9)dp[i]=max(dp[i],pre[i]+best[m]);
           best[m]=max(best[m],dp[i]-pre[i]); 
        }
        return pre[n]-dp[n];
    }
};