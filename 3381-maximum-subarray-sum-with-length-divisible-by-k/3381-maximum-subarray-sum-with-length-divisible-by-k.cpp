class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans=LLONG_MIN;
        vector<long long>prefSum(nums.size()+1,0);
        for(int i=1;i<=nums.size();i++){
            prefSum[i]+=nums[i-1]+prefSum[i-1];
        }
        for(int i=0;i<k;i++){
            long long pre=prefSum[i];
            for(int j=i+k-1;j<nums.size();j+=k){
                //ans=max(ans,(long long)prefSum[j+1]-prefSum[i]);
                long long c1=(long long)prefSum[j+1]-prefSum[j-k+1];
                long long c2=(long long)prefSum[j+1]-pre;
                if(c1>c2){
                   pre=prefSum[j-k+1];
                }
                ans=max(ans,max(c1,c2));cout<<ans<<" ";
            }
        }
        return ans;
    }
};