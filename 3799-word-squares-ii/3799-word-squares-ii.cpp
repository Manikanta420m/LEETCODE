class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& s) {
        sort(s.begin(), s.end());
        vector<vector<string>> result;
        int n = s.size();
        
        for (int a = 0; a < n; ++a) {
            for (int b = 0; b < n; ++b) {
                if (a != b && s[a][0] == s[b][0]) {
                    for (int c = 0; c < n; ++c) {
                        if (c != a && c != b && s[a][3] == s[c][0]) {
                            for (int d = 0; d < n; ++d) {
                                if (d != a && d != b && d != c && 
                                    s[d][0] == s[b][3] && 
                                    s[d][3] == s[c][3]) {
                                    result.push_back({s[a], s[b], 
                                                     s[c], s[d]});
                                }
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
};