class Solution {
public:
#define ll long long
    int maxDistinctElements(vector<int>& nums, int k) {
        ll ans=0;
        sort(nums.begin(),nums.end());
        ll mini=INT_MIN;
        for(ll i=0;i<nums.size();i++){
            ll lmin=nums[i]-k;
            ll lmax=nums[i]+k;
            if(mini<lmin){
                mini=lmin;
                ans++;
            }
            else if(mini<lmax){
                mini++;
                ans++;
            }
        }return ans;
    }
};