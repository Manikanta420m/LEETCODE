class Solution {
public:
    void dfs(int i_idx,int j_idx,queue<pair<int,int>>&q,vector<vector<int>>& image,int old,int color,int dx[],int dy[]){
        image[i_idx][j_idx]=color;
        int n=image.size(),m=image[0].size();
        for(int i=0;i<4;i++){
            int nx=i_idx+dx[i];
            int ny=j_idx+dy[i];
            if(nx<0 || nx>=n || ny<0 ||ny>=m||image[nx][ny]==color||
            image[nx][ny]!=old)continue;
          dfs(nx,ny,q,image,old,color,dx,dy);           
        }return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        int old=image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        dfs(sr,sc,q,image,old,color,dx,dy);
        return image;
    }
};