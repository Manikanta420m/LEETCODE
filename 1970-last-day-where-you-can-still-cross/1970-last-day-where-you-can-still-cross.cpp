class Solution {
private:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    bool check(int mid,int r, int c, vector<vector<int>>& cells){
        vector<vector<int>>a(r+1,vector<int>(c+1,0));
        vector<vector<int>>vis(r+1,vector<int>(c+1,-1));
        for(int i=0;i<mid;i++){
            int x=cells[i][0],y=cells[i][1];
            a[x][y]=1;
        }
        queue<pair<int,int>>q;
        for(int j=1;j<=c;j++){
            if(a[1][j]==0)q.push({1,j});
            vis[1][j]=1;
        }
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int x=it.first,y=it.second;
            if(x==r)return true;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<=0 or ny<=0 or nx>r or ny>c or vis[nx][ny]==1)continue;
                if(a[nx][ny]==1)continue;
                vis[nx][ny]=1;
                q.push({nx,ny});
            }
        }
        return false;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
       int ans=0;
       int n=cells.size();
       int l=0,r=n-1;
       ans=r;
       while(l<=r){
        int mid=l+(r-l)/2;
        if(check(mid,row,col,cells)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
       }
       return ans;
    }
};