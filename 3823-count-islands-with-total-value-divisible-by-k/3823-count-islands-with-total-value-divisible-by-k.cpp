class Solution {
private:
    void dfs(int i,int j,int n,int m,vector<vector<int>>& grid, long long &sum){
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]==0)return;

        sum+=grid[i][j];
        grid[i][j]=0;

        dfs(i-1,j,n,m,grid,sum);
        dfs(i,j-1,n,m,grid,sum);
        dfs(i+1,j,n,m,grid,sum);
        dfs(i,j+1,n,m,grid,sum);
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    long long sum=0;
                    dfs(i,j,n,m,grid,sum);
                    if(sum%k==0)ans++;
                }
            }
        }
        return ans;
    }
};