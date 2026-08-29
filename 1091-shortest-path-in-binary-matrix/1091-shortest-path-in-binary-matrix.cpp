class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0]!=0 or grid[n-1][m-1]!=0)return -1;
        int dx[]={-1,-1,-1,0,0,1,1,1};
        int dy[]={-1,0,1,1,-1,-1,0,1};
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            int dist=grid[x][y];
            if(x==n-1 and y==m-1)return dist;
            for(int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 and nx<n and ny>=0 and ny<m and grid[nx][ny]==0){
                    grid[nx][ny]=dist+1;
                    q.push({nx,ny});
                }
            }
        }
        return -1;
    }
};