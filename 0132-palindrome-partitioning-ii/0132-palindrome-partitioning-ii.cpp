class Solution {
public:
     static bool is_pali(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }return true;
     }
    int f(int i,int j,string &s, vector<int>&dp){
        if(i==j)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            if(is_pali(i,k,s)){
                int cost=1+f(k+1,j,s,dp);
                ans=min(ans,cost);
            }
        }return dp[i]=ans;
    }
    int minCut(string s) {
       int n=s.size();
       vector<int>dp(n+1,0);
       for(int i=n-1;i>=0;i--){
        int ans=1e9;
        for(int j=i;j<n;j++){
          if(is_pali(i,j,s)){
            int cost=1+dp[j+1];
            ans=min(ans,cost);
          }
        }
        dp[i]=ans;
       }
       return dp[0]-1;
    }
};