class Solution {
public:
    const int M=1e9+7;
    int subsequencePairCount(vector<int>& nums) {
        int m=*max_element(nums.begin(),nums.end());
        vector<vector<int>>dp(m+1,vector<int>(m+1,0));
        dp[0][0]=1;
        for(auto i:nums){
            auto ndp=dp;
            for(int g1=0;g1<=m;g1++){
                for(int g2=0;g2<=m;g2++){
                   if(!dp[g1][g2])continue;
                   int n1=gcd(i,g1),n2=gcd(i,g2);
                   ndp[n1][g2]=(ndp[n1][g2]+dp[g1][g2])%M;
                   ndp[g1][n2]=(ndp[g1][n2]+dp[g1][g2])%M;
                }
            }
            dp=ndp;
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            ans=(ans+dp[i][i])%M;
        }
        return ans;
    }
};