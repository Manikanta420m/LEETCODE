class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, c = 1, maxi = 0, maxpop = 0;
       for(auto i:nums){
        if(maxi==i)c++;
        else if(i>maxi){c=ans=1;maxi=i;}
        else c=0;
        ans=max(c,ans);
       }
       return ans;
    }
};