class Solution {
public:
    bool valid(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, pair<int, int>>> q;
        vector<vector<vector<bool>>> visited(
            m + 1, vector<vector<bool>>(n + 1, vector<bool>(k + 1, false)));

        q.push({0, {0, k}});
        visited[0][0][k] = true;

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {

                int i = q.front().first;
                int j = q.front().second.first;
                int K = q.front().second.second;
                q.pop();

                if (i == m - 1 && j == n - 1)
                    return steps;

                for (int p = 0; p < 4; p++) {
                    int new_i = i + row[p];
                    int new_j = j + col[p];

                    if (valid(new_i, new_j, m, n)) {

                        if (grid[new_i][new_j] == 0 &&
                            !visited[new_i][new_j][K]) {

                            visited[new_i][new_j][K] = true;
                            q.push({new_i, {new_j, K}});
                        }
                        if (grid[new_i][new_j] == 1 &&
                            K > 0 && !visited[new_i][new_j][K]) {

                            visited[new_i][new_j][K] = true;
                            q.push({new_i, {new_j, K - 1}});
                        }
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};