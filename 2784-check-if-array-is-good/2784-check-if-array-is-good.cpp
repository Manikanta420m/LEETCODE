class Solution {
public:
    bool isGood(vector<int>& nums) {
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i])>nums.size()-1)return false;
            if(abs(nums[i])==nums.size()-1){c++;continue;}
            if(nums[abs(nums[i])-1]<0)return false;
            else nums[abs(nums[i])-1]*=-1;
        }
        return (c==2?true:false);
    }
};