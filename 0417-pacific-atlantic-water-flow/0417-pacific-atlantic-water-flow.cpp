class Solution {
public:
    int n, m;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        n = h.size(), m = h[0].size();

        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));

        queue<pair<int,int>> qp, qa;

        // Pacific (top row + left column)
        for (int i = 0; i < n; i++) {
            qp.push({i, 0});
            pac[i][0] = true;
        }
        for (int j = 0; j < m; j++) {
            qp.push({0, j});
            pac[0][j] = true;
        }

        // Atlantic (bottom row + right column)
        for (int i = 0; i < n; i++) {
            qa.push({i, m - 1});
            atl[i][m - 1] = true;
        }
        for (int j = 0; j < m; j++) {
            qa.push({n - 1, j});
            atl[n - 1][j] = true;
        }

        bfs(h, pac, qp);
        bfs(h, atl, qa);

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pac[i][j] && atl[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }

    void bfs(vector<vector<int>>& h, vector<vector<bool>>& vis, queue<pair<int,int>>& q) {
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (vis[nx][ny]) continue;
                if (h[nx][ny] < h[x][y]) continue;  // only climb up
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
};