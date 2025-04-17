class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        vector<vector<int>>frq(101,vector<int>());
        for (int i=0;i<nums.size();i++){
            int it=nums[i];
            frq[it].push_back(i);
        }
        int ans=0;
        for(auto &it:frq){
            if(it.size()<2)continue;
            int n=it.size();
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    ans+=((it[j]*it[i])%k==0);
                }
            }
        }return ans;
    }
};