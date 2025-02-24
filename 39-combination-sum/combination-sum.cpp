class Solution {
public:

    void solve(int idx,int sum,vector<int>& candidates, int target,vector<int>&res,vector<vector<int>>&ans){
        if(idx==candidates.size()){
            if(sum==target)ans.push_back(res);
            return ;
        }
        if(sum+candidates[idx]<=target){
            res.push_back(candidates[idx]);
            solve(idx,sum+candidates[idx],candidates,target,res,ans);
            res.pop_back();
        }
        solve(idx+1,sum,candidates,target,res,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>res;
        solve(0,0,candidates,target,res,ans);
        return ans;
    }
};