class Solution {
public:
    vector<list<pair<int,int>>>graph;

    int solve(int src,int dest ,int n){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n,1e9);
        pq.push({0,src});
        dist[src]=0;
        unordered_set<int>vis;
        while(!pq.empty()){
            auto cur=pq.top();
            int d=cur.first;
            int node=cur.second;
            pq.pop();
            if(node==dest)return d;
            if(vis.count(node))continue;
            vis.insert(node);
            for(auto gh:graph[node]){
                if(dist[gh.first]>d+gh.second){
                    pq.push({d+gh.second,gh.first});
                    dist[gh.first]=d+gh.second;
                }
            }
        }   
        return -1;
    }

    int minCost(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0],2*edges[i][2]});
        }
        return solve(0,n-1,n);
    }
};