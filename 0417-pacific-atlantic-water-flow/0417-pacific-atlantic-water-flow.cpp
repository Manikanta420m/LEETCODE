class Solution {
public:
    int n,m;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        vector<vector<int>>ans;
        n=h.size(),m=h[0].size();
        vector<vector<bool>>pac(n,vector<bool>(m,false));
        vector<vector<bool>>atl(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            dfs(i,0,h,pac);
            dfs(i,m-1,h,atl);
        }
        for(int j=0;j<m;j++){
            dfs(0,j,h,pac);
            dfs(n-1,j,h,atl);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }

    void dfs(int x,int y,vector<vector<int>>&h,vector<vector<bool>>&vis){
        vis[x][y]=true;
        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,1,-1};
        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(nx<0 || ny<0 || nx>=n || ny>=m)continue;
            if(vis[nx][ny])continue;
            if(h[nx][ny]<h[x][y])continue;
            dfs(nx,ny,h,vis);
        }
    }
};