class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1,ans=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            ans=min(ans,nums[mid]);
            if(nums[l]<nums[mid]){
                ans=min(ans,nums[l]);
                l=mid+1;
            }
            else{
                ans=min(ans,nums[r]);
                r=mid-1; 
            }
        }return ans;
    }
};