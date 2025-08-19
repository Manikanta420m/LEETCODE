class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0,c=0;
        for(auto i:nums){
            if(i==0)c++;
            else c=0;
            ans+=c;
        }
        return ans;
    }
};