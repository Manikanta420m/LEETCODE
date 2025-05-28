class Solution {
public:
   void build_graph(vector<vector<int>>&g,vector<vector<int>>& edges){
     for(auto &i:edges){
        int u=i[0],v=i[1];
        g[v].push_back(u);
        g[u].push_back(v);
     }
   }

   int dfs(int u,int p,vector<vector<int>>&g,int k){
      if(k<0)return 0;
      int nodes=1;
      for(auto &i:g[u]){
        if(i==p)continue;
        nodes+=dfs(i,u,g,k-1);
      }return nodes;
   }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size()+1,m=edges2.size()+1;
        vector<vector<int>>g1(n),g2(m);
        vector<int>reach_g1(n),reach_g2(m),ans(n);
        build_graph(g1,edges1);
        build_graph(g2,edges2);
        for(int i=0;i<n;i++){
            reach_g1[i]=dfs(i,-1,g1,k);
        }
        for(int i=0;i<m;i++){
            reach_g2[i]=dfs(i,-1,g2,k-1);
        }
        int maxi=*max_element(reach_g2.begin(),reach_g2.end());
        for(auto i=0;i<n;i++){
            ans[i]=reach_g1[i]+maxi;
        }return ans;
    }
};