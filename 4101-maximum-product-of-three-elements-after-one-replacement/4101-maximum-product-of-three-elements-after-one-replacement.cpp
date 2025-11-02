class Solution {
 #define ll long long 
public:
    long long maxProduct(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int n=nums.size();
        return max((ll)abs((ll)nums[0]*(ll)nums[1]*(ll)1e5),max((ll)abs((ll)nums[n-1]*(ll)nums[n-2]*(ll)1e5),(ll)abs((ll)nums[0]*(ll)nums[n-1]*(ll)1e5)));
    }
};