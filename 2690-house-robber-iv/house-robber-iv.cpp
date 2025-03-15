class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l=*min_element(nums.begin(),nums.end());
        int r=*max_element(nums.begin(),nums.end());
        int ansi=INT_MAX;
        while(l<r){
            int mid=l+(r-l)/2;
            int ans=0;
            int mini=INT_MIN;
            for(int i=0;i<nums.size();i++){
                if(nums[i]<=mid){
                   ans++;
                   mini=max(nums[i],mini);
                    i++;
                }
            }
            if(ans>=k)r=mid;
            else l=mid+1;
        }return l;
    }
};