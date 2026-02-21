class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> mpp;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].size() >= k) {
                mpp[words[i].substr(0, k)]++;
            }
        }

        int cnt = 0;
        for (auto [x, y] : mpp) {
            if (y >= 2) {
                ++cnt;
            }
        }
        return cnt;
    }
};