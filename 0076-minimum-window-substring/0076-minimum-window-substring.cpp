class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> mp(128, 0);

        for(char c : t) {
            mp[c]++;
        }

        int required = t.size();

        int j = 0;
        int mini = INT_MAX;
        int start = 0;

        for(int i = 0; i < s.size(); i++) {

            if(mp[s[i]] > 0)
                required--;

            mp[s[i]]--;

            while(required == 0) {

                if(i - j + 1 < mini) {
                    mini = i - j + 1;
                    start = j;
                }

                mp[s[j]]++;

                if(mp[s[j]] > 0)
                    required++;

                j++;
            }
        }

        return mini == INT_MAX ? "" : s.substr(start, mini);
    }
};