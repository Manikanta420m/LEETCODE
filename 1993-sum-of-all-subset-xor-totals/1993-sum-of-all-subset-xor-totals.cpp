class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return solve(nums,0,0);
    }

    int solve(vector<int>& nums,int xori ,int cur){
        if(cur==nums.size())return xori;
        int add=solve(nums,xori^nums[cur],cur+1);
        int exc=solve(nums,xori,cur+1);
        return add+exc;
    }
};