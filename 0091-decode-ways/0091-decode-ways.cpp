class Solution {
public:
    int dp[105];
    /*
    int solve(int idx,string s){
        if(idx==s.size())return 1;
        if(s[idx]=='0')return 0;
        if(dp[idx]!=-1)return dp[idx];
        int one=0,two=0;
        one=solve(idx+1,s);
        int num=0;
        if(idx<s.size()-1)num=int(s[idx]-'0')*10+int(s[idx+1]-'0');
        if(idx<s.size()-1 and num<=26){
            two=solve(idx+2,s);
        }
        return dp[idx]=one+two;
    }
    */
    int numDecodings(string s) {
        if(s[0]=='0')return 0;
        int n=s.size();
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        dp[1]=s[0]=='0'?0:1;
        for(int i=2;i<=n;i++){
            int one=s[i-1]-'0';
            int two=(s[i-2]-'0')*10+(s[i-1]-'0');
            if(one>=1)dp[i]+=dp[i-1];
            if(two>=10 and two<=26)dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};