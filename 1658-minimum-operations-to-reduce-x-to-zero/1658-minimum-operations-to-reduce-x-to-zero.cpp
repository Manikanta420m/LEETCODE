class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int sm=0,ans=INT_MAX;
        mp[0]=n;
        for(int i=n-1;i>=0;i--){
            sm+=nums[i];
            mp[sm]=i;
            if(sm==x)ans=n-i;
        }
        if(sm<x)return -1;
        if(sm==x)return n;
        sm=0;
        for(int i=0;i<n;i++){
           sm+=nums[i];
           if(mp.count(x-sm)){
            ans=min(ans, i+1+(n-mp[x-sm]));
           }
        }
        return ans==INT_MAX?-1:ans;
    }
};