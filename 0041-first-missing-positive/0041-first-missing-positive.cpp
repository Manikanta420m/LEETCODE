class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=nums[i];
            while(x>=1 and x<=n and nums[x-1]!=x){
                swap(nums[i],nums[x-1]);
                x=nums[i];
            }
        }
        for(int i=0;i<n;i++)if(nums[i]!=i+1)return i+1;
        return n+1;
    }
};