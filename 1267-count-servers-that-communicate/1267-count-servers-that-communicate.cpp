class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<int>row(m,0),col(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    col[i]++;
                    row[j]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && (col[i]>1 || row[j]>1)){
                    ans++;
                }
            }
        }return ans;
    }
};