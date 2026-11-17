class Solution {
public:
    int minimumChanges(string s, int k) {
        vector<vector<optional<int>>> memo(s.size(), vector<optional<int>>(k + 1, nullopt));

        auto get_cost_d = [&](int start, int len, int d, int limit) {
            int cost = 0;
            int num_parts = d;
            int part_len = len / d;

            for (int front_pos = 0; front_pos < part_len / 2; ++front_pos) {
                for (int part = 0; part < num_parts; ++part) {
                    if (cost >= limit) return limit;
                    int back_pos = part_len - 1 - front_pos;
                    int front = start + part + front_pos * num_parts;
                    int back = start + part + back_pos * num_parts;
                    cost += (s[front] != s[back]);
                }
            }
            return cost;
        };

        auto get_cost = [&](int start, int len, int limit) {
            int cost = get_cost_d(start, len, 1, limit);
            for (int d = 2; d * d <= len && cost > 0; ++d) {
                if (len % d != 0) continue;
                cost = get_cost_d(start, len, d, cost);
                if (d * d != len && cost > 0) {
                    cost = get_cost_d(start, len, len / d, cost);
                }
            }
            return cost;
        };

        auto dfs = [&](auto&& self, int start, int k) -> int {
            if (start == s.size()) return 0;
            if (memo[start][k].has_value()) {
                return memo[start][k].value();
            }

            if (k == 1) {
                int cost = get_cost(start, s.size() - start, numeric_limits<int>::max());
                memo[start][k] = cost;
                return cost;
            }

            int max_len = s.size() - 2 * (k - 1) - start;
            int best = numeric_limits<int>::max();
            for (int len = 2; len <= max_len; ++len) {
                int first = get_cost(start, len, best);
                if (first >= best) continue;
                int rest = self(self, start + len, k - 1);
                best = min(best, first + rest);
            }
            memo[start][k] = best;
            return best;
        };

        return dfs(dfs, 0, k);
    }
};