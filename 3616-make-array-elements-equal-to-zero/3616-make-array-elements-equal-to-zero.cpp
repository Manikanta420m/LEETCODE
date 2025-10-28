class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int ans=0,n=nums.size(),sm=nums[0];
        vector<int>pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){pre[i]+=pre[i-1]+nums[i];sm+=nums[i];}
        for(int i=0;i<n;i++){
            if(nums[i]==0 and (pre[i]==sm-pre[i]))ans+=2;
            else if(nums[i]==0 and (abs(2*pre[i]-sm)==1))ans+=1;
        }
        return ans;
    }
};