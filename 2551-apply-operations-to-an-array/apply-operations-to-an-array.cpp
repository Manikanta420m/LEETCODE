class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
       vector<int>ans;
        for(int i=0;i<nums.size()-1;i++){
              if(nums[i]==nums[i+1] && nums[i]!=0){
                ans.push_back(2*nums[i]);
                nums[i+1]=0;
              }
              else if(nums[i]!=0) ans.push_back(nums[i]);
        }
        if(nums[nums.size()-1]!=nums[nums.size()-2] && nums[nums.size()-1])
                     ans.push_back(nums[nums.size()-1]);
        for(int i=ans.size();i<nums.size();i++)  ans.push_back(0);
        return ans;
    }
};