class Solution {
    const int M=1e9+7;
private:
    int power(long long a,long long b){
        long long ans=1;
        a%=M;
        while(b>0){
            if(b&1)ans=(ans*a)%M;
            a=(a*a)%M;
            b>>=1;
        }
        return (int)ans;
    }
public:
    int dfs(int node,int par,vector<vector<int>>&adj){
        if(adj[node].size()==0)return 0;
        int ans=0;
        for(auto i:adj[node]){
            if(i!=par){
                ans=max(ans,1+dfs(i,node,adj));
            }
        }
        return ans;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+2;
        vector<vector<int>>adj(n);
        for(auto &i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int depth=dfs(1,-1,adj);
        return (int)power(2,depth-1)%M;
    }
};