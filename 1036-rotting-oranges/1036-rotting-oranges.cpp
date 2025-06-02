class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0,rot=0,cnt=0;
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)q.push({i,j});
                if(grid[i][j]!=0)rot++;
            }
        }
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        while(!q.empty()){
            int siz=q.size();
            cnt+=siz;
            while(siz--){
               int x=q.front().first,y=q.front().second;
               q.pop();
               for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx<0 || nx>=n || ny<0 || ny>=m || grid[nx][ny]!=1)continue;
                grid[nx][ny]=2;
                q.push({nx,ny});
               }
            }
            if(!q.empty())ans++;
        }
        return cnt==rot?ans:-1;
    }
};