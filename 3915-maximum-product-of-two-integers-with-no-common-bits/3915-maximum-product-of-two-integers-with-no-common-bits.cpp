class Solution {
public:
    long long maxProduct(vector<int>& nums) {
       int pw=0,mx=0;
        for(auto i:nums)mx=max(i,mx);
        while((1<<pw)<=mx)pw++;
        vector<int>dp(1<<pw,-1);
        for(auto i:nums)dp[i]=max(dp[i],i);
        for(int i=0;i<pw;i++){
            for(int j=0;j<1<<pw;j++){
               if((j>>i)&1) dp[j]=max(dp[j],dp[j^(1<<i)]);
            }
        }
        long long res=0;
        int all=(1<<pw)-1;
        for(auto i:nums){
            if(dp[all^i]==-1)continue;
            res=max(res,1LL*i*dp[all^i]);
        }
        return res; 
    }
};