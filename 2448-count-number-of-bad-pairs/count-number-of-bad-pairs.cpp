class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans=0,c=0;
        unordered_map<int,int>mp;
        long long n=nums.size();
        for(int i=0;i<n;i++){
            int req=i-nums[i];
            ans+=mp[req];
            mp[req]++;
        }
        long long resu=n*(n-1)/2;
        return  resu-ans;
    }
};