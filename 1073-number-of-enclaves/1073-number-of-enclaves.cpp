class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        // Push all border 1's that are not visited
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1 && !vis[i][0]) {
                q.push({i, 0});
                vis[i][0] = 1;
            }
            if(grid[i][m-1] == 1 && !vis[i][m-1]) {
                q.push({i, m-1});
                vis[i][m-1] = 1;
            }
        }

        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 1 && !vis[0][j]) {
                q.push({0, j});
                vis[0][j] = 1;
            }
            if(grid[n-1][j] == 1 && !vis[n-1][j]) {
                q.push({n-1, j});
                vis[n-1][j] = 1;
            }
        }

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) ans++;
            }
        }
        return ans;
    }
};
