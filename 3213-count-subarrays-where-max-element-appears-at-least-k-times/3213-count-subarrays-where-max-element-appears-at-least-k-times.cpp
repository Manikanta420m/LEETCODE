class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();
        int l=0,c=0;
        int mx=*max_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
           if(nums[i]==mx)c++;
           while(c==k){
            ans+=(n-i);
            if(nums[l]==mx)c--;
            l++;
           }
        }return ans;
    }
};