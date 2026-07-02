class Solution {
public:
    int dir[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};
    bool isValid(int i, int j, int m, int n) {
        return (0<=i && i<m) && (0<=j && j<n);
    }
    bool findPath(int i, int j, int health,
    vector<vector<int>>& bestHealth, vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[i].size();
        health -= grid[i][j];
        bestHealth[i][j] = health;
        if(i==m-1 && j==n-1) return true;
        for(auto& d : dir) {
            int inew = i+d[0];
            int jnew = j+d[1];
            if(!isValid(inew, jnew, m, n)) continue;
            int hnew = health-grid[inew][jnew];
            if(hnew>bestHealth[inew][jnew] && findPath(inew, jnew, health, bestHealth, grid)) return true;
        } return false;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> bestHealth(m, vector<int>(n, 0));
        return findPath(0, 0, health, bestHealth, grid);
    }
};