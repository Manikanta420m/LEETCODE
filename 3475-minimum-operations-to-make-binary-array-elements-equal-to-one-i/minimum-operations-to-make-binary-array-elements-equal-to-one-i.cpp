class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==0){
                nums[i]^=1;
                nums[i+1]^=1;
                nums[i+2]^=1;
                ans++;
            }
        }
        if(nums[nums.size()-1]==0 || nums[nums.size()-2]==0)return -1;
        return ans;
    }
};