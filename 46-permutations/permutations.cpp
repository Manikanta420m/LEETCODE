class Solution {
public:
    
    void rec(vector<int>&f,vector<int>& nums,vector<int>& res,vector<vector<int>>&ans){
        if(res.size()==nums.size()){
            ans.push_back(res);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(!f[i]){
                f[i]=1;
                res.push_back(nums[i]);
                rec(f,nums,res,ans);
                res.pop_back();
                f[i]=0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>>ans;
         vector<int>res;
         int n=nums.size();
         vector<int>f(n,0);
         rec(f,nums,res,ans);
         return ans;
    }
};