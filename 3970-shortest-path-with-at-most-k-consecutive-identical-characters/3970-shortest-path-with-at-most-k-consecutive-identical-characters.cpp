#define ll long long
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        if(k==0)return -1;
        vector<vector<pair<int,int>>>adj(n);
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
        }
        priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<>>pq;
        vector<vector<ll>>dis(n,vector<ll>(k+1,LLONG_MAX));
        dis[0][1]=0;
        ll reso=0;
        pq.push({0,{0,1}});
        while(!pq.empty()){
            auto it=pq.top();
            int pri=it.first,node=it.second.first,c=it.second.second;
            pq.pop();
            if(node==n-1)return (int)pri;
            if(pri<=dis[node][c]){
                reso++;
                for(auto &[x,y]:adj[node]){
                    ll nc=(labels[node]==labels[x])?c+1:1;
                    if(nc>k)continue;
                    else{
                        ll np=pri+y;
                        if(np<dis[x][nc]){
                            dis[x][nc]=np;
                            pq.push({np,{x,nc}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};