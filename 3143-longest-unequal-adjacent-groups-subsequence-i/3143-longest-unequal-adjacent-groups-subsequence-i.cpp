class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>ans;
        ans.push_back(words[0]);
        int c=groups[0];
        for(int i=1;i<groups.size();i++){
           if(c!=groups[i]){ans.push_back(words[i]);c^=1;}
        }return ans;
    }
};