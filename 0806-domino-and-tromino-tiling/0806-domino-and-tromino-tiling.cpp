class Solution {
public:
    int numTilings(int n) {
        int M=1e9+7;
        vector<long long>dp(1001,0);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        if(n>3){
            for(int i=4;i<=n;i++){
                dp[i]=2*dp[i-1]+dp[i-3];
                dp[i]%=M;
            }
        }return dp[n];
    }
};