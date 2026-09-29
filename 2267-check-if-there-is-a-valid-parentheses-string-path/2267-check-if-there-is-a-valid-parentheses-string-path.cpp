class Solution {
public:
    int n,m;
    vector<vector<vector<int>>>dp;
    bool solve(int idx,int jdx,int cnt,vector<vector<char>>& grid){
        if(grid[idx][jdx]=='(')cnt++;
        else cnt--;
        if(cnt<0)return false;
        if(idx==n-1 and jdx==m-1){
            return cnt==0;
        }
        if(dp[idx][jdx][cnt]!=-1)return dp[idx][jdx][cnt];
        bool right=false,down=false;
        if(jdx+1<m)right=solve(idx,jdx+1,cnt,grid);
        if(!right and idx+1<n)right=solve(idx+1,jdx,cnt,grid);

        return dp[idx][jdx][cnt] = right || down;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        dp.assign(n,vector<vector<int>>(m,vector<int>(n+m-1,-1)));
        if (grid[0][0] == ')' || grid[n - 1][m - 1] == '(') {
            return false;
        }
        if ((n + m - 1) % 2 != 0) {
            return false;
        }
        return solve(0,0,0,grid);
    }
};