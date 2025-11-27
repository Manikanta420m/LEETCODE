class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
       /*
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
      */
        long long ans=LLONG_MIN,pref=0;
        vector<long long>prefSum(k,LLONG_MAX);
        prefSum[0]=0;
        for(int i=0;i<nums.size();i++){
            int mod=((i+1)%k);
            pref+=nums[i];
            if(prefSum[mod]!=LLONG_MAX){
                ans=max(ans,pref-prefSum[mod]);
            }
            prefSum[mod]=min(prefSum[mod],pref);
        }
        return ans;
    }
};