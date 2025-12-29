class Solution {
private:
    bool solve(int idx,string bottom,string cur,int k,map<string,int>&mp,
        map<string,bool>&dp){
        if(k==0)return true;
        if(cur.empty() and dp.count(bottom))return dp[bottom];
        if(cur.size()==k-1)return dp[bottom]=solve(0,cur,"",k-1,mp,dp);
        for(int i=0;i<6;i++){
            char ch='A'+i;
            string pat="";
            pat+=bottom[idx];
            pat+=bottom[idx+1];
            pat+=ch;
            if(mp.count(pat)){
                if(solve(idx+1,bottom,cur+ch,k,mp,dp))return true;
            }
        }
        return false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        map<string,bool>dp;
        map<string,int>mp;
        for(auto i:allowed)mp[i]++;
        return solve(0,bottom,"",bottom.size(),mp,dp);
    }
};