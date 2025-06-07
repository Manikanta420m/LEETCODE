class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int,int>mp;
        for(int i=0;i<x.size();i++){
            mp[x[i]]=max(mp[x[i]],y[i]);
        }
        vector<int>v;
        for(auto i:mp)v.push_back(i.second);
        sort(v.rbegin(),v.rend());
        if(v.size()<3)return -1;
        return v[0]+v[1]+v[2];
    }
};