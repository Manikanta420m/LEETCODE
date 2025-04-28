class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0,l=0;
        long long pro=1;
        if(k<=1)return 0;
        for(int i=0;i<nums.size();i++){
           pro*=nums[i];
           while(pro>=k){
            pro/=nums[l++];
           }
           ans+=(i-l+1);
        }return ans;
    }
};