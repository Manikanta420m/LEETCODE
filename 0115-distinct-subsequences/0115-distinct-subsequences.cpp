class Solution {
public:
    int f(int i,int j,string s1, string s2, vector<vector<int>>&dp){
    if(i<0)return 0;
    if(j<0)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i]==s2[j])return dp[i][j]=f(i-1,j-1,s1,s2,dp)+f(i-1,j,s1,s2,dp);
    return dp[i][j]=f(i-1,j,s1,s2,dp);
    }
    long long  numDistinct(string s1, string s2) {
        long long n=s1.size();
         long long m=s2.size();
         vector<vector<unsigned long long >>dp(n+1,vector<unsigned long long >(m+1,0));
         for(long long  i=0;i<=n;i++)dp[i][0]=1;
          //for(long long  i=1;i<=m;i++)dp[0][i]=0;
          for(long long  i=1;i<=n;i++){
            for(long long  j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
          }return dp[n][m];
       ///  return f(n-1,m-1,s1,s2,dp);
    }
};