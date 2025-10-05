class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr=0,n=nums.size();
        bool f=false;
        for(auto i:nums){xr^=i;if(i>0)f=true;}
        if(!f)return 0;
        return (xr==0?n-1:n);
    }
};