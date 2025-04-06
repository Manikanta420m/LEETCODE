class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==1)return nums;
        vector<int>ans;
        vector<int>dp(n+1,1);
        int lis=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if((nums[i]%nums[j]==0 && dp[i]<1+dp[j])){
                    dp[i]=1+dp[j];
                    if(lis<dp[i]){
                        lis=dp[i];
                    }
                }
            }
        }
        int pre=-1;
        for(int i=n-1;i>=0;i--){
            if(dp[i]==lis && (pre==-1 || pre%nums[i]==0)){
                ans.push_back(nums[i]);
                lis--;
                pre=nums[i];
            }
        }
        return ans;
    }
};