class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        if(k<=1)return 0;
        long long ans=0,sum=0;
        int l=0,n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum*(i-l+1)>=k){
                sum-=nums[l++];
            }
            ans+=(i-l+1);
        }return ans;
    }
};