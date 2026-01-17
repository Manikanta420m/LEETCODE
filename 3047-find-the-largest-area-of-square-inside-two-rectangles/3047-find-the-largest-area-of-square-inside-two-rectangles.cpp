class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        long long ans = 0;
        int n = bottomLeft.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long lx = max(bottomLeft[i][0], bottomLeft[j][0]);
                long long rx = min(topRight[i][0], topRight[j][0]);
                long long ly = max(bottomLeft[i][1], bottomLeft[j][1]);
                long long uy = min(topRight[i][1], topRight[j][1]);

                if (lx < rx && ly < uy) {
                    long long side = min(rx - lx, uy - ly);
                    ans = max(ans, side * side);
                }
            }
        }
        return ans;
    }
};