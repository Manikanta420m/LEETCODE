class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        int ans = 0;

        vector<int> dir = {0, 1, 0, -1, 0};
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int h = cur[0], r = cur[1], c = cur[2];
            ans = max(ans, h);
            if (r == n - 1 && c == n - 1) return ans;
            if (visited[r][c]) continue;
            visited[r][c] = 1;

            for (int k = 0; k < 4; k++) {
                int nr = r + dir[k], nc = c + dir[k+1];
                if (nr >= 0 && nc >= 0 && nr < n && nc < n && !visited[nr][nc]) {
                    pq.push({grid[nr][nc], nr, nc});
                }
            }
        }
        return ans;
    }
};