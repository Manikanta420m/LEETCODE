class Solution {
public:

     int solve(int idx,int sum,vector<int>& nums, int target){
        if(idx==nums.size()){
           if(sum==target)return 1;
           else return 0;
        }
         int x=solve(idx+1,sum+nums[idx],nums,target);
         int y=solve(idx+1,sum-nums[idx],nums,target);
         return x+y;
     }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,0,nums,target);
    }
};