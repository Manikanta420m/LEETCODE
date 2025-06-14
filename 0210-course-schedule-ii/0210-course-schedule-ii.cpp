class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& a) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        int m=a.size();
        vector<int>indeg(n);
        for(int i=0;i<m;i++){
            adj[a[i][0]].push_back(a[i][1]);
            indeg[a[i][1]]++;
        }
        queue<int>q;
        vector<int>topo;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0)q.push(it);
            }
        }
        if(topo.size()!=n)return {};
        reverse(topo.begin(),topo.end());
        return topo;
    }
};