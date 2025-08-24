class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0,c=0,j=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
           if(nums[i]==0){
            c=i-j-1;
            j=i;
           }
           else c++;
           ans=max(ans,c);
        }
        return ans==n?n-1:ans;
    }
};