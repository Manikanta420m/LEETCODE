class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int sum=INT_MIN;int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            int curr=grid[i][0];
            for(int j=1;j<n;j++){
                int len2=curr+grid[i][j];
                sum=max(sum,len2);
                if(i>0&&i<m-1&&j>0&&j<n-1) sum=max(sum,grid[i][j]);
                curr=max(grid[i][j],grid[i][j]+curr);
            }
        }
         for(int j=0;j<n;j++){
            int curr=grid[0][j];
            for(int i=1;i<m;i++){
                int len2=curr+grid[i][j];
                sum=max(sum,len2);
                if(i>0&&i<m-1&&j>0&&j<n-1) sum=max(sum,grid[i][j]);
                curr=max(grid[i][j],grid[i][j]+curr);
            }
        }
        return sum;
    }
};