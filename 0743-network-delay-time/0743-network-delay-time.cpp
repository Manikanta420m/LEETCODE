class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,1e9);
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto i:times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto [dis,node] = pq.top();
            pq.pop();
            for(auto i:adj[node]){
                int node = i.first;
                int wt = i.second;
                if(dis+wt<dist[node]){
                    dist[node]=dis+wt;
                    pq.push({dist[node],node});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9)return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};