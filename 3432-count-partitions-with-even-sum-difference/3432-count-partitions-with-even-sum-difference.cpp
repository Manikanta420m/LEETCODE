class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sm=accumulate(nums.begin(),nums.end(),0);
        if(sm&1)return 0;
        return nums.size()-1;
        // int ans=0;
        // bool f=true;
        // int pre=0;
        // for(int i=0;i<nums.size();i++){
        //     pre+=nums[i];
        //     if(pre%2==0)ans++;
        // }
        // return ans-1;
    }
};