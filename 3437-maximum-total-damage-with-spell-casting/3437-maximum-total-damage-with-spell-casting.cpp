class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        long long ans=0;
        unordered_map<int,long long>frq;
        for(auto p:power)frq[p]++;
        vector<int>keys;
        for(auto i:frq)keys.push_back(i.first);
        sort(keys.begin(),keys.end());
        int n=keys.size();
        vector<long long>dp(n);
        dp[0]=frq[keys[0]]*keys[0];
        for(int i=1;i<n;i++){
            long long take=frq[keys[i]]*keys[i];
            int prev=upper_bound(keys.begin(),keys.begin()+i,keys[i]-3)-keys.begin()-1;
            if(prev>=0)take+=dp[prev];
            dp[i]=max(dp[i-1],take);
        }
        return dp[n-1];
    }
};