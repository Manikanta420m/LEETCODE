class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size(),ans=-1,mini=INT_MAX;
        vector<int>pre(n,0),suf(n,INT_MAX);
        pre[0]=nums[0],suf[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
           pre[i]=max(nums[i],pre[i-1]);
        }
        if(pre[n-1]-suf[n-1]<=k)ans=n-1;
        for(int i=n-2;i>=0;i--){
           suf[i]=min(nums[i],suf[i+1]);
           if(pre[i]-suf[i]<=k){
                ans=i;
           }
        }
        return ans;
    }
};