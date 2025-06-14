class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<vector<int>>check(n);
        vector<int>indeg(n);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                check[it].push_back(i);
                indeg[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto i:check[node]){
                indeg[i]--;
                if(indeg[i]==0){
                    q.push(i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};