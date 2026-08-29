class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        queue<pair<int,int>>q;
        q.push({src,0});
        int ans=0;
        while(!q.empty() and ans<=k){
            int sz=q.size();
            while(sz--){
                auto [u,cost]=q.front();
                q.pop();
                for(auto &[v,wt]:adj[u]){
                   if(cost+wt<dist[v]){
                     dist[v]=cost+wt;
                     q.push({v,dist[v]});
                   }
                }
            }
            ans++;
        }
        return dist[dst]==INT_MAX ?-1:dist[dst];
    }
};