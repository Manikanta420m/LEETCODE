class Solution {
    vector<int> DP;

public:
    bool solve(int i) {
        if (i == 0) {
            return DP[i] = false;
        }
        if (DP[i] != -1) {
            return DP[i];
        }
        for (int j = 1; j * j <= i; j++) {
            if (!solve(i - j * j)) {
                return DP[i] = true;
            }
        }
        return DP[i] = false;
    }

    bool winnerSquareGame(int n) {
        DP.assign(n + 1, -1);
        return solve(n);
    }
};