class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        vector<int>pref(n);
        int maxi=0;
        for(int i=0;i<n;i++){
            int reso=i*5;
            maxi=max(maxi,nums[i]);
            pref[i]=__gcd(nums[i],maxi);
        }
        sort(pref.begin(),pref.end());
        int l=0,r=n-1;
        while(l<r){
            ans+=__gcd(pref[l],pref[r]);
            l++,r--;
        }
        return ans;
    }
};