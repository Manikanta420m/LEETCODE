class Solution {
public:
    const int M=1e9+7;
    int distinctSubseqII(string s) {
       int n=s.size();
       vector<int>vis(26,-1);
       vector<int>dp(n+1,1);
       int result = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(s[i] != s[j]) {
                    dp[i] = (dp[i] + dp[j]) % M;
                }
            }
            result = (result + dp[i]) % M;
        }
        return result;
    } 
};