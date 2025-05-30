class Solution {
private:
    void dfs(int cur,int distance,const vector<int>&edges,vector<int>&dist){
        while(cur!=-1 and dist[cur]==-1){
            dist[cur]=distance++;
            cur=edges[cur];
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int ans=-1,mini=INT_MAX,n=edges.size();
        vector<int>dist1(n,-1),dist2(n,-1);
        dfs(node1,0,edges,dist1);
        dfs(node2,0,edges,dist2);

        for(int i=0;i<n;i++){
            if(dist1[i]>=0 and dist2[i]>=0){
                if(max(dist1[i],dist2[i])<mini){
                    mini=max(dist1[i],dist2[i]);
                    ans=i;
                }
            }
        }return ans;
    }
};