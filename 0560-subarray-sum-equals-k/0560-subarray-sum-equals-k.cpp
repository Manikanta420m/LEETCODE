class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int t=0,ans=0;
        for(auto i:nums){
            t+=i;
            if(mp.find(t-k)!=mp.end()){
                ans+=mp[t-k];
            }
            mp[t]++;
        }return ans;
    }
};