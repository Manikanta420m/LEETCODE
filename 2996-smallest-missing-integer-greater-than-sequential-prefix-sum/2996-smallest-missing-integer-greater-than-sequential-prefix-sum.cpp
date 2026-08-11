class Solution {
public:
    int missingInteger(vector<int>& nums) {
       int n=nums.size();
       if(n==1)return nums[0]+1;
       int sm=nums[0];
       bool f=true;
       for(int i=1;i<n;i++){
        if(nums[i-1]+1==nums[i]){
            sm+=nums[i];
        }
        else {
            f=false;
            break;
        }
       }
       if(f)return sm;
       sort(nums.begin(),nums.end());
       for(auto i:nums){
        if(i>sm)return sm;
        else if(i==sm)sm++;
       }
       return sm;
    }
};