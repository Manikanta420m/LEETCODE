class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        int n=nums.size();
        vector<int>pref(n,0);
        pref[1]=1;
        for(int i=1;i<n-1;i++){
            int x=abs(nums[i]-nums[i-1]);
            int y=abs(nums[i]-nums[i+1]);
            if(y<x)pref[i+1]=pref[i]+1;
            else pref[i+1]=pref[i]+y;
        }
        vector<int>suf(n,0);
        suf[n-2]=1;
        for(int i=n-2;i>0;i--){
            int x=abs(nums[i]-nums[i-1]);
            int y=abs(nums[i]-nums[i+1]);
            if(y>=x)suf[i-1]=suf[i]+1;
            else suf[i-1]=suf[i]+x;
        }
        for(auto i:queries){
            int l=i[0],r=i[1];
            if(l<r)ans.push_back(abs(pref[r]-pref[l]));
            else ans.push_back(abs(suf[l]-suf[r]));
        }
        return ans;
    }
};