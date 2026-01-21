class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1){
                int ele=nums[i];
                int z=((ele+1)&~ele)>>1;
                ans.push_back(ele&(~z));
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;

    }
};