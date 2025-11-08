class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=1;
        int n=nums.size();
        if(n==1){
            return 1;
        }
        vector<int>pre(n,0),suf(n,0);
        int c=0,prev=-1e9;
        for(int i=0;i<n;i++){
           if(nums[i]>=prev)c++;
           else c=1;
           prev=nums[i];
           pre[i]=c;
           ans=max(ans,c);
        }c=0,prev=1e9+5;
        for(int i=n-1;i>=0;i--){
           if(nums[i]<=prev)c++;
           else c=1;
           prev=nums[i];
           suf[i]=c;
           ans=max(ans,c);
        }
        for(int i=0;i<n;i++){
            if(i==0){
               if(nums[0]>nums[1])ans=max(ans,suf[i+1]+1);
            }
            else if(i==n-1){
               if(nums[i-1]>nums[i])ans=max(ans,pre[i-1]+1);
            }
            else{
               if(nums[i-1]<=nums[i+1])ans=max(ans,1+pre[i-1]+suf[i+1]);
               else ans=max(ans,max(pre[i-1]+1,suf[i+1]+1));
            }
        }
        return ans;
    }
};