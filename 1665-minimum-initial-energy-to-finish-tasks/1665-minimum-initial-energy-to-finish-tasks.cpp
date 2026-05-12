class Solution {
public:
   static bool comp(pair<int,int>&p1,pair<int,int>&p2){
        return (p1.first-p1.second)>(p2.first-p2.second);
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        vector<pair<int,int>>pr;
        for(auto i:tasks){
            pr.push_back({i[1],i[0]});
        }
        sort(pr.begin(),pr.end(),comp);
        int req=pr[0].first;
        int have=pr[0].first;
        for(auto i:pr){
            if(have>=i.first){
                have-=i.second;
            }
            else{
                req+=(i.first-have);
                have=i.first;
                have-=i.second;
            }
        }
        return req;
    }
};