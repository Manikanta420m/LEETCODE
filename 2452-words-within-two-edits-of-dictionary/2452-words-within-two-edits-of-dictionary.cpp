class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& dict) {
        vector<string> res;
        int m = q.size(), n = dict.size();
        int t = q[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = 0;
                for (int k = 0; k < t; k++) {
                    if (dict[j][k] != q[i][k]) {
                        cnt++;
                    }
                    if(cnt>2) break;
                }
                if (cnt <= 2) {
                    res.push_back(q[i]);
                    break;
                }
            }
        }
        return res;
    }
};