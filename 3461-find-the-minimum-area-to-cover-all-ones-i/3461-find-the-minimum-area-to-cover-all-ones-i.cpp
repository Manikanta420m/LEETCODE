class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int up=0,down=0,left=0,right=0;
        int n=grid.size();
        int m=grid[0].size();
        bool f=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!f and grid[i][j]==1){
                    up=i,down=i,left=j,right=j;
                    f=true;
                }
                else if(grid[i][j]==1){
                    up=min(up,i);
                    down=max(down,i);
                    left=min(left,j);
                    right=max(right,j);
                }
            }
        }
        if(!f) return 0;
        return (down-up+1)*(right-left+1);
    }
};