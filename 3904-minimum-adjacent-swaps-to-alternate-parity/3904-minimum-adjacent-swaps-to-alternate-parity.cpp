class Solution {
public:
    int solve(vector<int>v){
        int ans=0;
        for(int i=0;i<v.size();i++){
            ans+=abs(v[i]-2*i);
        }
        return ans;
    }
    int minSwaps(vector<int>& nums) {
        vector<int>eve,odd;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1)odd.push_back(i);
            else eve.push_back(i);
        }
        int eve_siz=eve.size();
        int odd_siz=odd.size();
        if(abs(odd_siz-eve_siz)>1)return -1;
        int ans=INT_MAX;
        if(eve_siz>=odd_siz)ans=min(ans,solve(eve));
        if(odd_siz>=eve_siz)ans=min(ans,solve(odd));
        return ans;
    }
};