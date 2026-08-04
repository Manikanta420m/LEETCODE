class Solution {
private:
    int n;
    vector<int>suf;
    vector<vector<int>>dp;
    int solve(int idx,int m){
        if(idx>=n)return 0;
        if(idx+2*m>=n)return suf[idx];
        if(dp[idx][m]!=-1)return dp[idx][m];
        int ans=0;
        for(int i=1;i<=2*m;i++){
            ans=max(ans,suf[idx]-solve(idx+i,max(m,i)));
        }
        return dp[idx][m]=ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        suf.assign(n+1,0);
        suf[n-1]=piles[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]+=piles[i]+suf[i+1];
        }
        dp.assign(n,vector<int>(n+1,-1));
        return solve(0,1);
    }
};