class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool>ans;
        vector<long long>pre(n,0);
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff)pre[i]=1;
            pre[i]+=pre[i-1];
        }
        for(auto q:queries){
            int l=q[0],r=q[1];
            if(abs(pre[r]-pre[l])==0)ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};