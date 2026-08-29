class DSU{
    public :
    vector<int>parent,rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int Find(int x){
        return parent[x] = parent[x] == x ? x : Find(parent[x]); 
    }
    bool Union(int x,int y){
        int xset=Find(x) , yset=Find(y);
        if(xset!=yset){
            rank[xset]<rank[yset] ? parent[xset] = yset : parent[yset] = xset;
            rank[xset]+=rank[xset]==rank[yset];
            return true;
        }
        return false;
    }
};
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DSU dsu(n);
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),[&](auto const &a,auto const &b){
            return a[2]<b[2];
        });
        sort(edgeList.begin(),edgeList.end(),[&](auto const &a,auto const &b){
            return a[2]<b[2];
        });
        int i=0;
        vector<bool>ans(queries.size(),false);
        for(auto q:queries){
            while(i<edgeList.size() and edgeList[i][2]<q[2]){
                dsu.Union(edgeList[i][0],edgeList[i][1]);
                i++;
            }
            if(dsu.Find(q[0])==dsu.Find(q[1])) ans[q[3]] = true;
        }
        return ans;
    }
};