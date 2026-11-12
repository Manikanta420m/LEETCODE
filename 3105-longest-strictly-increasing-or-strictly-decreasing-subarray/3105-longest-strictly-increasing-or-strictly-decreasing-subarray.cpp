class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size()==1)return 1;   
       // bool f=(nums[0]<nums[x])?true:false;
        int in=1,de=1,maxi=1;
         for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1])in++,de=1;
            else if(nums[i]<nums[i-1])de++,in=1;
            else in=de=1;
            maxi=max({in,de,maxi});
         }return maxi;
    }
};