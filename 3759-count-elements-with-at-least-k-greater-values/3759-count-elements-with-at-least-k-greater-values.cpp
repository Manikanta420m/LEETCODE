class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto i:nums){mp[i]++;}
        int n=nums.size();
        int sm=n,ans=0;
        for(auto &[ele,freq]:mp){
           sm-=freq;
           if(sm>=k){
            ans+=freq;
           }
           else break;
        }
        return ans;
    }
};