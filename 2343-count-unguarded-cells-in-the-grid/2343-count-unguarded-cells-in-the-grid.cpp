class Solution {
public:
     vector<int>dir={-1,0,1,0,-1};
     void dfs(int x,int y,int dire,vector<vector<int>>&a){
        if((x<0||x>=a.size())||(y<0||y>=a[0].size())||(a[x][y]==2||a[x][y]==3))return ;
        a[x][y]=1;
        if(dire==0) dfs(x-1,y,dire,a);
        else  if(dire==1) dfs(x,y+1,dire,a);
        else  if(dire==2) dfs(x+1,y,dire,a);
        else  if(dire==3) dfs(x,y-1,dire,a);

     }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>a(m,vector<int>(n,0));
        for(auto &i:guards){
            a[i[0]][i[1]]=2;
        }
         for(auto &i:walls){
            a[i[0]][i[1]]=3;
        }
         for(auto &j:guards){
            for(int i=0;i<4;i++){
                int x=j[0]+dir[i];
                int y=j[1]+dir[i+1];
                dfs(x,y,i,a);
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==0)ans++;
            }
        }
        return ans;
    }
};
