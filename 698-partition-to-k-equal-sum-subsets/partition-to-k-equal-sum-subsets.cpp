class Solution {
public:

    bool solve(int idx,int sum,vector<bool>&vis,vector<int>& nums, int target,int k){
       if(k==0)return true;
       if(sum==target) return solve(0,0,vis,nums,target,k-1);
       for(int i=idx;i<nums.size();i++){
            if(sum+nums[i]>target || vis[i])continue;
               vis[i]=true;
               if(solve(i+1,sum+nums[i],vis,nums,target,k))return true;
               vis[i]=false; 
            if(sum==0)return false;
       }return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
      int sum=accumulate(nums.begin(),nums.end(),0);
      int target=sum/k;
      if(sum%k!=0 || nums.size()<k)return false;
      vector<bool>vis(nums.size(),false);
      return solve(0,0,vis,nums,target,k);
    }
};