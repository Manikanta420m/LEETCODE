class Solution {
private:
    int solve(int idx,vector<string>& strs,int prev,vector<vector<int>>&dp){
        if(idx==strs[0].size())return 0;
        if(dp[idx][prev+1]!=-1)return dp[idx][prev+1];
        int pick=0,skip=0;
        bool f=true;
        for(int j=0;j<strs.size();j++){
            if(prev!=-1 and strs[j][idx]<strs[j][prev]){
                f=false;
                break;
            }
        }
        if(prev==-1 or f)pick=1+solve(idx+1,strs,idx,dp);
        skip=solve(idx+1,strs,prev,dp);
        return dp[idx][prev+1]=max(skip,pick);
    }
public:
    int minDeletionSize(vector<string>& strs) {
        vector<vector<int>>dp(strs[0].size()+2,vector<int>(strs[0].size()+2,-1));
        return strs[0].size()-solve(0,strs,-1,dp);
    }
};