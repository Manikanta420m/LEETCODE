class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size(),ans;
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            dp[i]=energy[i];
            if(i-k>=0)dp[i]=max(dp[i],dp[i-k]+dp[i]);
            if(n-i<=k)ans=max(ans,dp[i]);
        }
        return ans;
    }
};