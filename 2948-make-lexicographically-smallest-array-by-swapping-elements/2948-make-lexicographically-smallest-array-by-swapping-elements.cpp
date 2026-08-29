class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>>pr;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pr.push_back({nums[i],i});
        }
        sort(pr.begin(),pr.end());
        vector<vector<pair<int,int>>>gpr;
        gpr.push_back({pr[0]});
        for(int i=1;i<n;i++){
            if(pr[i].first-pr[i-1].first<=limit){
                gpr.back().push_back(pr[i]);
            }
            else{
                gpr.push_back({pr[i]});
            }
        }
        for(auto i:gpr){
            vector<int>ind;
            for(auto j:i){
                ind.push_back(j.second);
            }
            sort(ind.begin(),ind.end());
            for(int j=0;j<ind.size();j++){
                nums[ind[j]]=i[j].first;
            }
        }
        return nums;
    }
};