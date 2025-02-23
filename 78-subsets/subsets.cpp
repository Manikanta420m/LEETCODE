class Solution {
public:
    void rec(int idx,vector<int>&res,vector<int>&nums,vector<vector<int>>&ans){
        ans.push_back(res);
        for(int i=idx;i<nums.size();i++){
            res.push_back(nums[i]);
            rec(i+1,res,nums,ans);
            res.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>>ans;
       vector<int>res;
       rec(0,res,nums,ans);
       return ans;
    }
};