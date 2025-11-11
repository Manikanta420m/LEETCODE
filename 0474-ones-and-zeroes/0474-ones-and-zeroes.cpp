class Solution {
private:
    int solve(int i,vector<int>&zero,vector<int>&one,int m,int n,vector<vector<vector<int>>>&dp){
        if(m<0 or n<0)return -1e9;
        if(i==one.size())return 0;
        if(dp[i][m][n]!=-1)return dp[i][m][n];
        int pick=1+solve(i+1,zero,one,m-zero[i],n-one[i],dp);
        int not_pick=solve(i+1,zero,one,m,n,dp);
        return dp[i][m][n]=max(pick,not_pick);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int siz=strs.size();
        vector<int>zero(siz),one(siz);
        vector<vector<vector<int>>>dp(siz,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        for(int i=0;i<siz;i++){
            int cnt=count(strs[i].begin(),strs[i].end(),'0');
            zero[i]=cnt;
            one[i]=strs[i].size()-cnt;
        }
        return solve(0,zero,one,m,n,dp);
    }
};