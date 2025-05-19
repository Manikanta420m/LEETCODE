class Solution {
public:
    string triangleType(vector<int>& nums) {
        int sum=nums[0]+nums[1]+nums[2];
        int maxi=max(nums[0],max(nums[1],nums[2]));
        int mani=min(nums[0],min(nums[1],nums[2]));
        if(sum-maxi<=maxi)return "none";
        if(nums[0]==nums[1] and nums[0]==nums[2])return "equilateral";
        else if(nums[0]!=nums[1] and nums[1]!=nums[2] and nums[0]!=nums[2])return "scalene";
        else return "isosceles";
    }
};