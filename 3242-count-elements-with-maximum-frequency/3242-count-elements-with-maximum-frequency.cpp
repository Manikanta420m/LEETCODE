class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=0,maxi=0;
        for(auto i:nums){mp[i]++;maxi=max(maxi,mp[i]);}
        for(auto i:mp){ans+=(i.second==maxi?maxi:0);}
        return ans;
    }
};