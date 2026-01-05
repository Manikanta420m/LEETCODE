class Solution {
    int dp[201][201][201];
private:
    bool solve(int i,int j,int k,string &s1, string &s2, string &s3){
        if(k==0)return true;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        if(i>0 and j>0 and s1[i-1]==s2[j-1] and s1[i-1]==s3[k-1]){
            return dp[i][j][k]=(solve(i-1,j,k-1,s1,s2,s3) or solve(i,j-1,k-1,s1,s2,s3));
        }
        else if(i>0 and s1[i-1]==s3[k-1]){
            return dp[i][j][k]=solve(i-1,j,k-1,s1,s2,s3);
        }
        else if(j>0 and s2[j-1]==s3[k-1]){
            return dp[i][j][k]=solve(i,j-1,k-1,s1,s2,s3);
        }
        else return dp[i][j][k]=false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int k=s3.size();
        if(k<n+m)return false;
        memset(dp,-1,sizeof(dp));
        return solve(n,m,k,s1,s2,s3);
    }
};