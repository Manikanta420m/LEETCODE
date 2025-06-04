class Solution {
public:
    string answerString(string word, int numFriends) {
        int n=word.size();
        string ans="";
        int ele=n-(numFriends)+1;
        if(numFriends==1)return word;
        vector<int>v;
        char ch = *max_element(word.begin(), word.end());
        for (int i = 0; i < n; ++i) {
            if (word[i] == ch) v.push_back(i);
        }
        for (int i : v) {
            string s = (ele <= n - i) ? word.substr(i, ele) : word.substr(i);
            ans = max(s, ans);
        }

        return ans;
    }
};