class Solution {
public:
    int min_steps = INT_MAX;
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = bank.size();
        vector<bool> vis(n, false);
        dfs(startGene, endGene, vis, bank, 0);
        if (min_steps == INT_MAX) min_steps = -1;
        return min_steps;

    }

    void dfs(string start, string end, vector<bool>& vis, vector<string>& bank, int steps) {      
        if (start == end) {
            min_steps = min(min_steps, steps);
            return;
        };

        for (int i = 0; i < bank.size(); i++) {
            if (!vis[i] && valid(bank[i], start)) {
                vis[i] = true;
                dfs(bank[i], end, vis, bank, steps+1);
                vis[i] = false;
            }
        }
    }

    bool valid(string a, string b) {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            if (a[i] == b[i]) cnt++;
        }
        return cnt == 7;
    }
};