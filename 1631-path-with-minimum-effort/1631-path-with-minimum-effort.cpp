class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;
        pq.emplace(0,0,0);
        dist[0][0]=0;
        int dir[4][2] ={{0,1},{0,-1},{1,0},{-1,0}};
        while(!pq.empty()){
            auto [effort,x,y]=pq.top();
            pq.pop();
            if(effort>dist[x][y])continue;
            if(x==n-1 and y==m-1) return effort;
            for(auto i:dir){
                int nx=x+i[0];
                int ny=y+i[1];
                if(nx>=0 and nx<n and ny>=0 and ny<m){
                   int newEffort = max(effort,abs(heights[x][y]-heights[nx][ny]));
                   if(newEffort<dist[nx][ny]){
                      dist[nx][ny]=newEffort;
                      pq.emplace(newEffort,nx,ny);
                   }
                }
            }
        }
        return -1;
    }
};