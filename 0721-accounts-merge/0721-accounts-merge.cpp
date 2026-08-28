class Disjointset{
    public:
    vector<int>parent,rank;
    Disjointset(int n){
        parent.resize(n);
        rank.resize(n,0);
        iota(parent.begin(),parent.end(),0);
    }
    int find(int node){
        if(node==parent[node])return node;
        return parent[node]=find(parent[node]);
    }
    void unite(int u,int v){
        int pu=find(u),pv=find(v);
        if(pu!=pv){
            if(rank[pu]<rank[pv]){
               parent[pu]=pv;
            }
            else if(rank[pu]>rank[pv]){
               parent[pv]=pu;
            }
            else {
               parent[pv]=pu;
               rank[pu]++;
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n= accounts.size();
        Disjointset ds(n);
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email=accounts[i][j];
                if(mp.find(email)==mp.end()){
                    mp[email]=i;
                }
                else{
                    ds.unite(i,mp[email]);
                }
            }
        }
        vector<string>merged[n];
        for(auto i:mp){
            int root=ds.find(i.second);
            merged[root].push_back(i.first);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(merged[i].empty())continue;
            sort(merged[i].begin(),merged[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            temp.insert(temp.end(),merged[i].begin(),merged[i].end());
            ans.push_back(temp);
        }
        return ans;
    }
};