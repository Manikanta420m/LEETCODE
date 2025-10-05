class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long ans=0,sum1=0,sum2=0;
        int n=nums.size();
        int idx=0;
        if(n==2)return abs(nums[0]-nums[1]);
        int i=0,j=n-1;
        while(i<n-1 and nums[i]<nums[i+1]){sum1+=nums[i];i++;}
        while(j>0 and nums[j-1]>nums[j]){sum2+=nums[j];j--;}
        if(abs(i-j)==1 and (nums[i]==nums[j]))return abs(sum1-sum2);
        if(i!=j)return -1;
        ans=sum1-sum2;
        return min(abs(ans+nums[i]),abs(ans-nums[i]));
    }
};